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
	// bst.inOrderTraverse(bst.root);
	bst.printTree();
	std::cout << std::endl;

	std::cout << "before deleting 40" << std::endl;
	bst.deleteNode(40);
	std::cout << "after delete node 40" << std::endl;
	bst.printTree();
	// bst.inOrderTraverse(bst.root);
	return 0;
}