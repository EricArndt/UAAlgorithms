
#include "bfs.h"
#include "gtest/gtest.h"

using namespace std;

TEST(BFS, Empty) {
	vector<BNode *> ret = bfs(NULL);

	ASSERT_EQ(0, ret.size());
}

TEST(BFS, SingleLeft) {
	BNode * root = new BNode(0, new BNode(100, NULL, NULL), NULL);
	vector<BNode *> ret = bfs(root);
	
	ASSERT_EQ(2, ret.size());
	ASSERT_EQ(100, root->l->d);
}

TEST(BFS, SingleRight) {
	BNode * root = new BNode(0, NULL, new BNode(200, NULL, NULL));
	vector<BNode *> ret = bfs(root);

	ASSERT_EQ(2, ret.size());
	ASSERT_EQ(200, root->r->d);
}