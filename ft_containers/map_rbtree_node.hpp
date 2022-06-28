#ifndef __RED_BLACK_TREE_HPP__
#define __RED_BLACK_TREE_HPP__

# include <memory>
# include <iostream>
# include "pair.hpp"

namespace ft {
	// color enum: BLACK = 0, RED = 1
	enum Color { BLACK, RED	};
	// node struct
	template<typename type>
	struct Node {
		type data;
		int color;
		Node *left;
		Node *right;
		Node *parent;
	};

	template<typename T>
	int isNil(T *node)
	{
		return node->left == NULL && node->right == NULL;
	}
	template<typename T>
	T *minimum(T *node)
	{
		if (!isNil(node))
		{
			while (!isNil(node->left))
				node = node->left;
		}
		return node;
	}
	template<typename T>
	T *maximum(T *node)
	{
		if (!isNil(node))
		{
			while (!isNil(node->right))
				node = node->right;
		}
		return node;
	}
	template<typename T>
	T *successor(T *x)
	{
		is (!isNil(x->right))
			return minimum(x->right);
		T *y = x->parent;
		while (!isNil(y) && x == y->right)
		{
			x = y;
			y = y->parent;
		}
		return y;
	}
	template<typename T>
	T *predecessor(T *x)
	{
		if (!isNil(x->left))
			return maximum(x->left);
		T *y = x->parent;
		while (!isNil(y) && x == y->left)
		{
			x = y;
			y = y->parent;
		}
		return y;
	}
	template<typename T>
	T *getGrandNode(T *curr)
	{
		if (isNil(curr->parent))
			return NULL;
		return curr->parent->parent;
	}
	template<typename T>
	T *getUncleNode(T *curr)
	{
		T *grand = getGrandNode(curr);
		if (isNil(grand))
			return NULL;
		if (grand->left == curr->parent)
			return grand->right;
		return grand->left;
	}

	






}


#endif