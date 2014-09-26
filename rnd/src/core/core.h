
#ifndef _H_CORE_
#define _H_CORE_

#include <cstddef>

/// Binary tree node
class BNode {
public:
	int d;
	BNode * l;
	BNode * r;

	BNode(int d, BNode * l, BNode * r);
};

#endif