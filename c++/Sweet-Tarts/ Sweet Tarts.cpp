#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int recurse(vector<int>&, vector<int>, map<vector<int>, int>&, int);

int main() {
	for (int n = 1; ; n++) {
		vector<int> sweetTartRoll, beg_end(2);
		map<char, int> sweetTartValues;
		map<vector<int>, int> tartScore;

		int count;
		cin >> count;

		// Check for end of solution conditions
		if (!count) {
			break;
		}

		// Get the value of each type of tart
		for (int i = 0; i < 4; i++) {
			char temp;
			cin >> temp;
			sweetTartValues[temp] = 4 - i;
		}

		// Read tart order input 
		for (int i = 0; i < count; i++) {
			char temp;
			cin >> temp;
			sweetTartRoll.push_back(sweetTartValues[temp]);
		}

		beg_end[0] = 0;
		beg_end[1] = sweetTartRoll.size() - 1;

		cout << "Case " << n << " has a maximum score of " << recurse(sweetTartRoll, beg_end, tartScore, 1) << ".\n";
	}

	return 0;
}

int recurse(vector<int>& list, vector<int> beg_end, map<vector<int>, int>& tartScore, int depth) {
	// Case: Last sweet tart has been reached
	if (beg_end[1] - beg_end[0] == 0)
		return list[beg_end[0]] * depth;

	// Case: Check if the current state of the remaining sweet tart roll has already been calculated
	else if (tartScore.count(beg_end))
		return tartScore[beg_end];

	// Case: The current state of the roll has not yet been evaluated. Calculate the values of removing
	// both the left and right most sweet tarts and return the greater of the two values */
	else {
		vector<int> remove_left(beg_end), remove_right(beg_end);
		++remove_left[0];
		--remove_right[1];

		tartScore[beg_end] = max(recurse(list, remove_left, tartScore, depth + 1) + list[beg_end[0]] * depth, recurse(list, remove_right, tartScore, depth + 1) + list[beg_end[1]] * depth);
		return tartScore[beg_end];
	}
}
