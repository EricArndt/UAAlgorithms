#include "sample.hpp"

void increment_problem(std::istream& input, std::ostream& output) {
    int x;

    for (int i = 0; i < 10; ++i) {
        input >> x;

        if (x == 0)
            break;

        output << increment_algorithm(x) << std::endl;
    }
}

int increment_algorithm(int value) {
    return value + 1;
}
