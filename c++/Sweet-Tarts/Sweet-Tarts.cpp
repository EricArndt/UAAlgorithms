#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <utility>
using namespace std;

int recurse(vector<int>&, pair<int, int>, map<pair<int,int>, int>&, int);

int main() {
	for (int n = 1; ; ++n) {
		int count;
		cin >> count;

		// Check for end of solution conditions
		if (!count) {
			break;
		}

		int sweetTartValues[4];
		map<pair<int,int>, int> tartScore;
		vector<int> sweetTartRoll(count);
		pair<int, int> rollPosition(0, count - 1);

		// Get the value of each type of tart
		for (int i = 0; i < 4; ++i) {
			char temp;
			cin >> temp;
			sweetTartValues[temp - 'A'] = 4 - i;
		}

		// Read tart order input 
		for (int i = 0; i < count; ++i) {
			char temp;
			cin >> temp;
			sweetTartRoll[i] = sweetTartValues[temp - 'A'];
		}
		
		cout << "Case " << n << " has a maximum score of " << recurse(sweetTartRoll, rollPosition, tartScore, 1) << ".\n";
	}

	return 0;
}

int recurse(vector<int>& list, pair<int,int> rollPosition, map<pair<int,int>, int>& tartScore, int depth) {
	// Case: Last sweet tart has been reached
	if (rollPosition.first == rollPosition.second) {
		return list[rollPosition.first] * depth;
	}

	// Case: Check if the current state of the remaining sweet tart roll has already been calculated
	else if (tartScore.count(rollPosition)) {
		return tartScore[rollPosition];
	}

	// Case: The current state of the roll has not yet been evaluated. Calculate the values of removing
	// both the left and right most sweet tarts and return the greater of the two values
	else {
		pair<int, int> remove_left(rollPosition.first + 1, rollPosition.second), remove_right(rollPosition.first, rollPosition.second - 1);
		tartScore[rollPosition] = max(recurse(list, remove_left, tartScore, depth + 1) + list[rollPosition.first] * depth, recurse(list, remove_right, tartScore, depth + 1) + list[rollPosition.second] * depth);
		return tartScore[rollPosition];
	}
}
