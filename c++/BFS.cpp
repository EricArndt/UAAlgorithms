#include<iostream>
#include<vector>

using namespace std;

struct Node {
	vector<Node*> children;
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

		/* for(Node child = cur_node.children) { }
		   for(int i = 0; i < queue.size(); i++) {
		       Node *child = queue[i];

		*/

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

int main() {

}