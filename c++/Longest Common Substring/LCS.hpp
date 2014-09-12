#ifndef LCS_HPP
#define LCSHPP

#include "LCS.cpp"
#include <string>
#include <vector>

struct LCS {
        std::string str1, str2;
        std::vector<std::vector<int> > grid;

        LCS(std::string, std::string);
        std::string getLCS();
};

#endif