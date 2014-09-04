#include <fstream>
#include <sstream>
#include "test.hpp"
#include "st.hpp"

void diff_test()
{
  std::fstream input("test.in");
  std::stringstream output;
  std::fstream solutions("test.out");

  solution(input, output);

  std::string compare1, compare2;
  while(output >> compare1 and solutions >> compare2)
  {
    if (compare1 != compare2)
      throw failed;
  }
}

int main()
{
  int err = 0;
  err += test(diff_test);
  return err;
}
