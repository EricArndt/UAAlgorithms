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

/*
 * arguments are start and end nodes
 * returns length of path to end node
 * returns -1 if end node is not found
 */
int BFSLength (Node* start, Node* end) {
	Node* sentinel = NULL;
	int length = 0;
	vector<Node*> queue;

	queue.push(start);
	start->visited = true;

	while(!queue.empty()) {
		
		Node* cur_node = queue.pop();
		if (cur_node == end) {
			return length;
		}
		if (sentinel == cur_node) {
			length++;
			sentinel = cur_node->connections.back();
		}

		for(int i = 0; i < cur_node->children.size(); i++) {
			Node *child = cur_node->children[i];
			
			if(!child->visited) {
				queue.push_back(child);
				child->visited = true;
			}
		}
	}
	return -1;
}
