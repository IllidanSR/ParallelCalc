cmake_minimum_required(VERSION 3.19)
project(ParallelCalc)

set(CMAKE_CXX_STANDARD 17)

find_package(Threads REQUIRED)

add_executable(${PROJECT_NAME} main.cpp
        ThreadPool/ThreadPool.hpp
        Tests/Test.hpp
        ThreadPool/AClass.hpp)

target_link_libraries(${PROJECT_NAME} Threads::Threads)