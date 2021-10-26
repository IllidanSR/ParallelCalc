#pragma once
#include "ThreadPool.hpp"

#include <future>
#include <vector>


class A {
 public:
  A() : m_threadPool(num_threads) {}

  template <typename T>
  std::vector<T> f(std::vector<T> const& vec) {

    using Future = std::future<T>;

    std::vector<T> returnVector;
    std::vector<Future> awaitedResult;
    returnVector.reserve(vec.size());
    awaitedResult.reserve(vec.size());

    for (int i = 0; i < vec.size(); ++i) {
      T value = vec.at(i);
      awaitedResult.emplace_back(
          m_threadPool.addToWork<T>([value]() { return value * value; }));
    }

    for (int i = 0; i < awaitedResult.size(); ++i) {
      returnVector.insert(returnVector.begin() + i, awaitedResult.at(i).get());
    }
    return returnVector;
  }

 public:
  static constexpr int num_threads = 8;

 private:
  ThreadPool m_threadPool;
};
