#include <iostream>

void increment(std::istream& input, std::ostream& output)
{
  int x;
  for (int i = 0; i < 10; ++i)
  {
    input >> x;
    if (x == 0)
      break;
    output << (x + 1) << std::endl;
  }
}
