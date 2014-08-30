#include <iostream>
#include <cmath>
#include <vector>
#include <tuple>
#include <map>
using namespace std;

int recurse(vector<int>&, tuple<int,int>, map<tuple<int,int>, int>&, int);

int main() {
	for(int n = 1; ; n++) {
		vector<int> list;
		map<char, int> tartVal;
		map<tuple<int, int>, int> tartScore;

		int count;
		cin >> count;
		if(!count) break;

		for(int i = 0; i < 4; i++) {
			char temp;
			cin >> temp;
			tartVal[temp] = 4-i;
		}
		for(int i = 0; i < count; i++) {
			char temp;
			cin >> temp;
			list.push_back(tartVal[temp]);
		}

		tuple<int, int> beg_end(0, list.size()-1);
		cout << "Case " << n << " has a maximum score of " <<  recurse(list, beg_end, tartScore, 1) <<".\n";
	}
	
	return 0;
}

int recurse(vector<int>& list, tuple<int,int> beg_end, map<tuple<int,int>, int>& tartScore, int depth) {
	if(get<1>(beg_end) - get<0>(beg_end) == 0)
		return list[get<0>(beg_end)] * depth;

	else if(tartScore.count(beg_end))
		return tartScore[beg_end];

	else {
		tuple<int, int> remove_left(get<0>(beg_end)+1,get<1>(beg_end)), remove_right(get<0>(beg_end),get<1>(beg_end)-1);
		tartScore[beg_end] = max( recurse(list, remove_left, tartScore, depth+1) + list[get<0>(beg_end)]*depth  ,  recurse(list, remove_right, tartScore, depth+1) + list[get<1>(beg_end)]*depth );
		return tartScore[beg_end];
	}
}
