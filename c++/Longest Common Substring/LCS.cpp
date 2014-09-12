#include "LCS.cpp"
using namespace;

LCS::LCS(string str1, string str2) : str1(str1), str2(str2), grid(str1.size()+1, vector<int>(str2.size()+1, 0)) { }

string LCS::getLCS() {
		int maxX = 0, maxY = 0;

		for (int i = 1; i < grid.size(); ++i) {
				for (int n = 1; n < grid[0].size(); ++n) {
						grid[i][n] = (str1[i-1] == str2[n-1] ? grid[i-1][n-1] + 1 : 0);
						if (grid[i][n] > grid[maxY][maxX]) {
								maxY = i;
								maxX = n;
						}
				}
		}

		return str1.substr(maxY-grid[maxY][maxX], grid[maxY][maxX]);
}
