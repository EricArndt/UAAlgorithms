#include "LCS.hpp"
#include <string>
using namespace std;

int main() {
        string str1, str2;
                
        while (cin >> str1 >> str2) {
                cout << LCS(str1, str2).getLCS() << endl;
        }

        return 0;
}
