#include <fstream>
#include <sstream>
#include "test.hpp"
#include "sample.hpp"

int main()
{
  int err = 0;
  err += test(diff(increment, "increment.in", "increment.out"));
  return err;
}
