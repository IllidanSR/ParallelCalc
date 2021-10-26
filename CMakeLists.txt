cmake_minimum_required(VERSION 3.19)
project(Task)

set(CMAKE_CXX_STANDARD 17)

find_package(Threads REQUIRED)

add_executable(Task main.cpp  ThreadPool.hpp Test.hpp AClass.hpp)

target_link_libraries(${PROJECT_NAME} Threads::Threads)