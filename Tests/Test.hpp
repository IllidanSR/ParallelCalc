#pragma once

#include <cassert>
#include <iostream>
#include <type_traits>
#include <vector>

#include "../ThreadPool/AClass.hpp"

using Vector = std::vector<int>;

void TestSizeEqualsInt() {
  std::vector<int> testVector = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3,
                                 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
  A a;
  auto resultVector = a.f(testVector);
  assert(testVector.size() == resultVector.size());
}

void TestMultiplexInt() {
  std::vector<int> testVector = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3,
                                 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
  A a;
  auto resultVector = a.f(testVector);
  for (int i = 0; i < testVector.size(); ++i) {
    assert(testVector.at(i) * testVector.at(i) == resultVector.at(i));
  }
}

void TestSizeEqualsDouble() {
  std::vector<double> testVector = {1.1, 2.2, 3.3, 4.4, 5.5, 1.1, 2.2, 3.3, 4.4,
                                    5.5, 1.1, 2.2, 3.3, 4.4, 5.5, 1.1, 2.2, 3.3,
                                    4.4, 5.5, 1.1, 2.2, 3.3, 4.4, 5.5};
  A a;
  auto resultVector = a.f(testVector);
  assert(testVector.size() == resultVector.size());
}

void TestMultiplexDouble() {
  std::vector<double> testVector = {1.1, 2.2, 3.3, 4.4, 5.5, 1.1, 2.2, 3.3, 4.4,
                                    5.5, 1.1, 2.2, 3.3, 4.4, 5.5, 1.1, 2.2, 3.3,
                                    4.4, 5.5, 1.1, 2.2, 3.3, 4.4, 5.5};
  A a;
  auto resultVector = a.f(testVector);
  for (int i = 0; i < testVector.size(); ++i) {
    assert(testVector.at(i) * testVector.at(i) == resultVector.at(i));
  }
}

void TestSizeEqualsFloat() {
  std::vector<float> testVector = {1.1, 2.2, 3.3, 4.4, 5.5, 1.1, 2.2, 3.3, 4.4,
                                   5.5, 1.1, 2.2, 3.3, 4.4, 5.5, 1.1, 2.2, 3.3,
                                   4.4, 5.5, 1.1, 2.2, 3.3, 4.4, 5.5};
  A a;
  auto resultVector = a.f(testVector);
  assert(testVector.size() == resultVector.size());
}

void TestMultiplexFloat() {
  std::vector<float> testVector = {1.1, 2.2, 3.3, 4.4, 5.5, 1.1, 2.2, 3.3, 4.4,
                                   5.5, 1.1, 2.2, 3.3, 4.4, 5.5, 1.1, 2.2, 3.3,
                                   4.4, 5.5, 1.1, 2.2, 3.3, 4.4, 5.5};
  A a;
  auto resultVector = a.f(testVector);
  for (int i = 0; i < testVector.size(); ++i) {
    assert(testVector.at(i) * testVector.at(i) == resultVector.at(i));
  }
}

void TestSizeEqualsInt64() {
  std::vector<int64_t> testVector = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3,
                                     4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
  A a;
  auto resultVector = a.f(testVector);
  assert(testVector.size() == resultVector.size());
}

void TestMultiplexInt64() {
  std::vector<int64_t> testVector = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3,
                                     4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
  A a;
  auto resultVector = a.f(testVector);
  for (int i = 0; i < testVector.size(); ++i) {
    assert(testVector.at(i) * testVector.at(i) == resultVector.at(i));
  }
}