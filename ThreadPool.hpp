#pragma once

#include <condition_variable>
#include <functional>
#include <future>
#include <memory>
#include <queue>
#include <mutex>
#include <type_traits>
#include <thread>
#include <vector>
#include <utility>


class ThreadPool {
 public:
  using WorkerVector = std::vector<std::thread>;
  using TaskQueue = std::queue<std::function<void()>>;

 public:
  ThreadPool(size_t threads) : m_stopFlag(false) {
    for (size_t i = 0; i < threads; ++i)
      m_worker.emplace_back([this] {
        for (;;) {
          std::function<void()> task;
          {
            std::unique_lock<std::mutex> lock(this->m_workerMutex);
            this->m_condition.wait(lock, [this] {
              return this->m_stopFlag || !this->m_taskQueue.empty();
            });
            if (this->m_stopFlag && this->m_taskQueue.empty()) return;
            task = std::move(this->m_taskQueue.front());
            this->m_taskQueue.pop();
          }
          task();
        }
      });
  }

  template<typename ValueType>
  std::future<ValueType> addToWork(std::function<ValueType(void)> const& function) {
    static_assert(std::is_arithmetic_v<ValueType>);
    auto task = std::make_shared<std::packaged_task<int()>>(function);

    std::future<ValueType> result = task->get_future();
    {
      std::unique_lock<std::mutex> lock(m_workerMutex);

      if (m_stopFlag) throw std::runtime_error("addToWork on stopped ThreadPool");

      m_taskQueue.emplace([task]() { (*task)(); });
    }
    m_condition.notify_one();
    return result;
  }

  ~ThreadPool() {
    {
      std::unique_lock<std::mutex> lock(m_workerMutex);
      m_stopFlag = true;
    }
    m_condition.notify_all();
    for (std::thread &worker : m_worker) {
      worker.join();
    }
  }

 private:
  WorkerVector m_worker;
  TaskQueue m_taskQueue;
  std::mutex m_workerMutex;
  std::condition_variable m_condition;
  bool m_stopFlag;
};
