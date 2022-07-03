#include "map_rbtree.hpp"
#include <iostream>

int main()
{
	ft::Rbtree<int, int> bst;
	bst.insert({55, 55});
	bst.insert({40, 40});
	bst.insert({65, 65});
	bst.insert({60, 60});
	bst.insert({75, 75});
	bst.insert({57, 57});
	
	// bst.printTree();
	std::cout << "delete 40" << std::endl;
	bst.deleteNode(bst.findNode(40));
	std::cout << "after delete node 40" << std::endl;
	// bst.printTree();
	// std::cout << "delete 65" << std::endl;
	// bst.deleteNode(65);
	// std::cout << "after delete node 65" << std::endl;
	// bst.printTree();
	// std::cout << "delete 75" << std::endl;
	// bst.deleteNode(75);
	// std::cout << "after delete node 75" << std::endl;
	// bst.printTree();
	// std::cout << "delete 60" << std::endl;
	// bst.deleteNode(60);
	// std::cout << "after delete node 60" << std::endl;
	// bst.printTree();
	// std::cout << "delete 55" << std::endl;
	// bst.deleteNode(55);
	// std::cout << "after delete node 55" << std::endl;
	// bst.printTree();
	return 0;
}