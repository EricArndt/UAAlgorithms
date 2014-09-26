
#include "bfs.h"

using namespace std;

void bfs2(BNode * root, vector<BNode *> & ret) {
	if (root != NULL) {
		if (root->l != NULL) ret.push_back(root->l);
		if (root->r != NULL) ret.push_back(root->r);

		bfs2(root->l, ret);
		bfs2(root->r, ret);
	}
}

vector<BNode *> bfs(BNode * root) {
	vector<BNode *> ret;
	if (root != NULL) ret.push_back(root);
	bfs2(root, ret);
	return ret;
}