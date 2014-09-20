# Sample Project

This project is meant as a guide for how to use the testing framework as well as
be an example of the preferred style. The sample is used in the context of
solving a problem (such as "Sweet Tarts") for the respository. Such a pattern is
not likely to be used very often, but there are some famous problems that ought
to be recorded in the repository and it doesn't hurt to have examples.

The project directory is setup in the following way:

* Parent - c++ root, housing the root CMakeLists and test.hpp
  * sample.test - A directory housing all of the testing code and data
    * increment.cpp - The implementation of the tests
    * increment.in - Input test data
    * increment.out - Solution data
  * CMakeLists.txt - The local CMake file that will setup the build
  * sample.cpp - The implementation of the algorithm or solution
  * sample.hpp - The declaration of the algorithm or solution

Note that you can't build the algorithm of solution locally with the current
setup, this is a flaw that is being worked on. In order to build you need to
move to the parent or root directory and run the pipeline of building and
testing there.

## The Solution

The solution to the problem "Increment this number by one" can be found in the
sample.cpp file:

```C++
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
```

Note the pattern here that needs to be repeated, the function should take a
reference to an input stream, and an output stream, named however you like.
Treating these as if they were std::cin and std::cout it's business as usual.
Read from the input stream, parse the input as necessary, check for sentinels,
compute, write to the output stream. This makes testing very easy, you only
need to include the input and output data and mimic the testing file.

### Why a header?

The general idea of c++ file structure is header files declare signatures and
functions names that you can use with another file or program so that you can
compile. That is, without knowing the declaration (or name) the compiler wont
know what you're talking about. Insert a header file. The actual implementation
is entirely different, and will instead show up at linking time. That is why
the implementation is not necessary at compile time. This is also why templates
are implement in the header files themselves (or sometimes an .ipp file that is
included). Templates must be *compiled* with implementation in order to make
sure the specialization of the template actually makes sense, for instance:

```c++
template<typename T>
int has_size(T t)
{
  return t.size();
}

has_size<int>();
```

This will surely fail, because `int` has no member function `size`.

In short, we structure files the way we do because of the compiler, and there
are arguments for it being better, but who cares about those.

## The Tests

The test file, increment.cpp, is actually incredible small:

```c++
#include "test.hpp"
#include "sample.hpp"

int main()
{
  int err = 0;
  err += test(diff(increment, "increment.in", "increment.out"));
  return err;
}
```

In order to test an algorithm or a problem solution, you need to include the
framework header, test.hpp. Also, obviously, you need to include the header for
your own algorithm / solution. From there you need to create a main function.
Note that there is no main function anywhere else except in the tests. The main
function will then keep a running total of exceptions thrown, the convention is
to use a variable named err. Use the test function to catch and propogate the
sum of failures. In the case of a problem solution, you need only follow the
precise pattern shown above, that is, use the diff function in test.hpp with
your own two data files. Give the name of the data files here as strings. Note
that you **must** label the data files with .in and .out. This is simply a
fault in the test framework and will be improved later.

If you're working with an algorithm you could, and probably should, follow the
same pattern. However, you can always write your own function and pass it into
the test function. Something like this:

```c++
#include "test.hpp"
#include "my_algorithm.hpp"

void testing()
{
  if (my_algorithm())
    throw failed;
}

int main()
{
  int err = 0;
  err += test(testing);
  return err;
}
```

is also fine.

## Good Testing Practices

You're lucky. All of your testing here is entirely isolated. However, there is
still some general practices that you need to realize and hold up. If you
adhere to the patterns and the framework it won't really be an issue, but just
in case you decide to brave, here is why we do things this way. Writing tests
is software development, just like writing normal code, and because of that you
have to deal with maintenance. Maintenance is a very painful thing, especially
if you're doing it often. Ideally you want to minimize maintenance at all
costs, and you definitely don't want to spent as much time maintaining your
test suite that you are maintaining your releases.

In order to minimize maintenance you need to separate actual test data from
code. So that a change in the test data does not affect the implementation.
Moreover you want to prefer not having the code depend on any implicit
structure in the data. This is unavoidable for problem solutions, but shouldn't
be a problem with algorithms. The idea is data should be detached, swappable,
and simplistic. That way when you do decide to change or swap it in and out you
don't have to touch code.

Moreover, you want your testing code to small. The smaller and more expressive
or robust your testing code is the less often you'll have to change it and the
easier it will be to change it when you have to. Do the work once, and do it
*well* once. Focus on how the data itself might change or how you can handle
data in robust ways. Usually the data will have a set of predefined assumptions
on it that you can abuse, but be wary of changing requirements.

## The Build

In order to hook everything you've written up into the currently pretty
terrible build structure is through making your own CMakeLists and adding one
line to the root CMakeLists.

Consider the CMakeLists in the sample:

```CMake
# ---------------------------------------------------------------------------- #
# Setup

include_directories(.)

project(sample CXX)

add_library(sample sample.cpp)

add_unit_test(sample increment)

make_manifest(
  sample.cpp
  readme.markdown
)
```

The first line will include the current directory, and pick up your header
files. The second and third lines are required to setup the targets for your
algorithm of solution. From there you can make as many unit tests as you like.

TODO:
- [ ] explain add_unit_test syntax and brittleness
- [ ] explain the manifest, and any ordering concerns
