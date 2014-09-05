#include <fstream>
#include <sstream>
#include "test.hpp"
#include "sample.hpp"

void diff_test()
{
  using namespace std;

  fstream input("increment.in");
  stringstream output;
  fstream solutions("increment.out");

  increment(input, output);

  string compare1, compare2;
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
