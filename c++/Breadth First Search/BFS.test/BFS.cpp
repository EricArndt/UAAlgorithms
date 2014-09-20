#include <fstream>
#include "test.hpp"
#include "BFS.hpp"

using namespace std;

void test_BFSLength() {
	fstream input("BFS.in");
	fstream output("BFS.out");

	int cases;
	input >> cases;

	for (int i = 0; i < cases; i++) {
		int num_nodes;
		int start, end;
		input >> num_nodes;
		input >> start >> end;

		vector<Node> nodes = vector<Node>();

		for (int n = 0; n < nodes; n++) {
			nodes.pushback(Node(n));
		}

		int path_len = BFSLength(&(nodes[start]), &(nodes[end]));
		int answer;
		output >> answer;
		if (path_len != answer) {
			throw failed;
		}
	}
}

int main() {
	int err = 0;
	err += test(test_BFSLength());
	return err;
}
