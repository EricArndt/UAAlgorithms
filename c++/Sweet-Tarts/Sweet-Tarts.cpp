#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct rollIndices {
	int beg, end;
	rollIndices(int beg, int end) : beg(beg), end(end) { }

	bool operator < (const rollIndices & rhs) const {
		return (rhs.beg != beg ? rhs.beg < beg : rhs.end < end);
	}
};

int recurse(vector<int>&, rollIndices, map<rollIndices, int>&, int);

int main() {
	for (int n = 1; ; ++n) {
		int count;
		cin >> count;

		int sweetTartValues[4];
		map<rollIndices, int> tartScore;
		vector<int> sweetTartRoll(count);
		rollIndices rollPosition(0, count - 1);

		// Check for end of solution conditions
		if (!count) {
			break;
		}

		// Get the value of each type of tart
		for (int i = 0; i < 4; ++i) {
			char temp;
			cin >> temp;
			sweetTartValues[temp - 'A'] = 4 - i;
		}

		// Read tart order input 
		for (int i = 0; i < count; i++) {
			char temp;
			cin >> temp;
			sweetTartRoll[i] = sweetTartValues[temp - 'A'];
		}
		
		cout << "Case " << n << " has a maximum score of " << recurse(sweetTartRoll, rollPosition, tartScore, 1) << ".\n";
	}

	return 0;
}

int recurse(vector<int>& list, rollIndices rollPosition, map <rollIndices, int>& tartScore, int depth) {
	// Case: Last sweet tart has been reached
	if (rollPosition.end - rollPosition.beg == 0) {
		return list[rollPosition.beg] * depth;
	}

	// Case: Check if the current state of the remaining sweet tart roll has already been calculated
	else if (tartScore.count(rollPosition)) {
		return tartScore[rollPosition];
	}

	// Case: The current state of the roll has not yet been evaluated. Calculate the values of removing
	// both the left and right most sweet tarts and return the greater of the two values
	else {
		rollIndices remove_left(rollPosition.beg + 1, rollPosition.end), remove_right(rollPosition.beg, rollPosition.end - 1);
		tartScore[rollPosition] = max(recurse(list, remove_left, tartScore, depth + 1) + list[rollPosition.beg] * depth, recurse(list, remove_right, tartScore, depth + 1) + list[rollPosition.end] * depth);
		return tartScore[rollPosition];
	}
}
