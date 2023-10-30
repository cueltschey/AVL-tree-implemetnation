#include "Node.h"

int Node::degree() const {
	int res = 0;
	if (left != nullptr) {
		res += 1;
	}
	if (right != nullptr) {
		res += 1;
	}
	return res;
}