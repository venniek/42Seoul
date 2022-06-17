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
	bst.printTree();
	std::cout << std::endl;


	std::cout << "delete 40" << std::endl;
	bst.deleteNode(40);
	std::cout << "after delete node 40" << std::endl;
	bst.printTree();
	std::cout << "delete 65" << std::endl;
	bst.deleteNode(65);
	std::cout << "after delete node 65" << std::endl;
	bst.printTree();
	std::cout << "delete 75" << std::endl;
	bst.deleteNode(75);
	std::cout << "after delete node 75" << std::endl;
	bst.printTree();
	std::cout << "delete 60" << std::endl;
	bst.deleteNode(60);
	std::cout << "after delete node 60" << std::endl;
	bst.printTree();
	std::cout << "delete 55" << std::endl;
	bst.deleteNode(55);
	std::cout << "after delete node 55" << std::endl;
	bst.printTree();
	system("leaks a.out");
	return 0;
}