#include<iostream>
#include<vector>

using namespace std;

bool success = true;

struct Node {
	vector<Node*> children;
	char name;
	bool visited;

	Node() {
		this->visited = false;
	}

};

vector<Node*> BFSTraversal (vector<Node*> graph, int start = 0) {
	
	vector<Node*> order;
	vector<Node*> queue;

	queue.push_back(graph[start]);
	queue[0]->visited = true;

	while(!queue.empty()) {
		
		Node* cur_node = queue.front();
		queue.erase(queue.begin());
		order.push_back(cur_node);

		for(int i = 0; i < cur_node->children.size(); i++) {
			
			Node *child = cur_node->children[i];
			
			if(!child->visited) {
				queue.push_back(child);
				child->visited = true;
			}
		}
	}
	return order;
}

void testOne(bool printDebug) {
	Node* tree[7];

	for (int i = 0; i < 7; i++) {
		tree[i] = new Node();
		tree[i]->name = 'A' + i;
	}

	vector<Node*> graph;
	tree[0]->children.push_back(tree[1]);
	tree[0]->children.push_back(tree[2]);

	tree[1]->children.push_back(tree[0]);
	tree[1]->children.push_back(tree[3]);
	tree[1]->children.push_back(tree[4]);

	tree[2]->children.push_back(tree[0]);
	tree[2]->children.push_back(tree[5]);
	tree[2]->children.push_back(tree[6]);

	tree[3]->children.push_back(tree[1]);

	tree[4]->children.push_back(tree[1]);

	tree[5]->children.push_back(tree[2]);

	tree[6]->children.push_back(tree[2]);
	
	for(int i = 0; i < 7; i++) {
		graph.push_back(tree[i]);
	}

	vector<Node*> traversal = BFSTraversal(graph);

	//Traversal of graph is expected to be in alphabetical oder
	for (int i = 0; i < traversal.size(); i++) {
		if(!traversal[i]->name == ('A' + i)) {
			success = false;
			return;
		}
	}

	// We're traversing the graph again and nodes are still visited so we only get one
	traversal = BFSTraversal(graph, 6);
	if (traversal.size() > 1 || !traversal[0]->name == 'G') {
		success = false;
		return;
	}
}

int main() {
	testOne(true);
	//testTwo(true);
	if(!success) {
		cout << "FAILED: TestBFS" << endl;
		system("pause");
		return 1;
	}
	else
		return 0;

	
}