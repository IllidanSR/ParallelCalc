#pragma once

#include <cassert>
#include <iostream>
#include <type_traits>
#include <vector>

#include "../ThreadPool/AClass.hpp"

using Vector = std::vector<int>;

void TestSizeEquals() {
  std::vector<int> testVector = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3,
                                 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
  A a;
  auto resultVector = a.f(testVector);
  assert(testVector.size() == resultVector.size());
}

void TestMultiplex() {
  std::vector<int> testVector = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3,
                                 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
  A a;
  auto resultVector = a.f(testVector);
  for (int i = 0; i < testVector.size(); ++i) {
    assert(testVector.at(i) * testVector.at(i) == resultVector.at(i));
  }
}
