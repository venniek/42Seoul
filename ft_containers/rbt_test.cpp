#include <iostream>
#include "red_black_tree.hpp"
using namespace ft;

int main() {
	Rbtree<int> bst;
	bst.insertNode(55);
	bst.insertNode(40);
	bst.insertNode(65);
	bst.insertNode(60);
	bst.insertNode(75);
	bst.insertNode(57);

	// bst.printTree();
	// cout << endl
	// 	<< "After deleting" << endl;
	// bst.deleteNode(40);
	// bst.printTree();
	bst.traverse(bst.root);
	return 0;
}