#include <fstream>
#include <sstream>
#include <cstdlib>
#include "test.hpp"
#include "sample.hpp"

void test_increment_algorithm()
{
  using namespace std;

  for(int i = 0; i < 100; ++i)
  {
    int x = rand();
    int y = increment_algorithm(x);
    if (x + 1 != y)
      throw failed;
  }
}

void test_increment_problem()
{
  using namespace std;

  fstream input("increment.in");
  stringstream output;
  fstream solutions("increment.out");

  increment_problem(input, output);

  string compare1, compare2;
  while(not output.eof() and not solutions.eof())
  {
    output >> compare1;
    solutions >> compare2;

    if (output.bad() or solutions.bad()
        or compare1 != compare2)
      throw failed;
  }
}

int main()
{
  int err = 0;
  err += test(test_increment_problem);
  err += test(test_increment_algorithm);
  return err;
}
