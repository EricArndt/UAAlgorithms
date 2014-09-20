#include<vector>

using namespace std;

struct Node {
	vector<Node*> connections;
	int value;
	bool visited;

	Node(int val) {
		this->visited = false;
		this->value = val;
	}
};

int BFSLength(Node*, Node*);
