#ifndef TEST_HPP
#define TEST_HPP

#include <stdexcept>
#include <iostream>

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

template<typename F>
void diff(F f, std::string in_file, std::string solution_file) {

  std::fstream input(in_file);
  std::stringstream output;
  std::fstream solutions(solution_file);

  f(input, output);

  string compare1, compare2;
  while(output >> compare1 or solutions >> compare2)
  {
    if (output.fail() or solutions.fail()
        or compare1 != compare2)
      throw failed;
  }
}

#endif
