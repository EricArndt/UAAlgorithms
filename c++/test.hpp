#ifndef TEST_HPP
#define TEST_HPP

#include <stdexcept>
#include <iostream>
#include <fstream>

// This is used to provide simple function diagnostics.
#define failed std::runtime_error(__FUNCTION__)

// This is a test harness. It runs a test and logs any failures.
template<typename F>
int test(F f) {
  try {
    f();
  } catch(std::exception& err) {
    std::cerr << "error: " << err.what() << std::endl;
    return 1;
  }
  return 0;
}

#endif
