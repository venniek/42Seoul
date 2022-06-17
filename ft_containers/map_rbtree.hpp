#ifndef __RED_BLACK_TREE_HPP__
#define __RED_BLACK_TREE_HPP__

# include <memory>
# include <iostream>
# include "pair.hpp"

namespace ft {
	// tree class
	template<typename T, typename Alloc = std::allocator<T> >
	class Rbtree {
	private:
		// color enum: BLACK = 0, RED = 1
		enum Color { BLACK, RED	};
		// node struct
		template<typename type>
		struct Node {
			type key;
			int color;
			Node *left;
			Node *right;
			Node *parent;
		};
		typedef T value_type;
		typedef Node<value_type> *RbtNode;
		typedef Alloc allocator_type;
		std::allocator<Node<value_type> > _alloc;
		RbtNode root;
		RbtNode nil;
	public:
		// -----constructor, destructor
		Rbtree(): nil(makeNilNode()) 
		{
			root = nil;
		}
		Rbtree(T key): nil(makeNilNode())
		{ 
			root = nil;
			insertNode(key);
		}
		~Rbtree()
		{
			if (root)
				_alloc.deallocate(root, 1);
			if (nil)
				_alloc.deallocate(nil, 1);
		}

		// -----operation insert, delete, search
		void insertNode(value_type key)  {
			RbtNode node = makeNode(key, RED);
			RbtNode now = root;
			RbtNode y = NULL;

			while (now != nil)
			{
				y = now;
				if (now->key.first == key.first)
					return ;
				if (now->key.first > key.first)
					now = now->left;
				else
					now = now->right;
			}
			node->parent = y;
			if (y == NULL)
			{ // tmp가 루트가 된다
				root = node;
				node->color = BLACK;
				return ;
			}
			if (y->key > key)
				y->left = node;
			else
				y->right = node;
			if (node->parent->parent == NULL) // tmp가 루트의 자식. 바꿔줄 필요 없다.
				return ;
			insertFix(node);	
		}
		void deleteNode(value_type key)
		{
			RbtNode x, y;  // y: 대체할 노드
			RbtNode z = nil; // z: 지울 노드
			RbtNode now = root;
			int y_origin_c;

			while (now != nil) // 지울 노드 찾기
			{
				if (now->key == key)
				{
					z = now;
					break;
				}
				else if (now->key < key)
					now = now->right;
				else
					now = now->left;
			}
			if (z == nil) // key not found in tree
			{
				std::cout << key << " is not in the tree" << std::endl;
				return ;
			}
			y = z;
			y_origin_c = y->color; // 없어지는 색 == 지울 노드(바뀔 수 있음. 우선 대입해놓기)
			if (z->left == nil) // 자식 없거나 하나인지 검사
			{
				x = z->right;
				nodeReplace(z, z->right);
			}
			else if (z->right == nil)
			{
				x = z->left;
				nodeReplace(z, z->left);
			}
			else // 자식 둘 다 있으면 successor의 색을 지우게 된다.
			{
				y = minimum(z->right); // y는 z의 successor
				y_origin_c = y->color;
				x = y->right;
				if (y->parent == z)
					x->parent = y;
				else
				{
					nodeReplace(y, y->right);
					y->right = z->right;
					y->right->parent = y;
				}
				nodeReplace(z, y);
				y->left = z->left;
				y->left->parent = y;
				y->color = z->color;
			}
			_alloc.deallocate(z, 1);
			if (y_origin_c == BLACK) {
				deleteFix(x);
			}
		}
		RbtNode searchNode(value_type key)
		{
			RbtNode now = root;
			while (now != nil && now->key != key)
			{
				if (now->key > key)
					now = now->left;
				else
					now = now->right;
			}
			if (now->key != key)
				return NULL;
			return now;
		}

		// -----utils_tree
		RbtNode makeNode(value_type key, int color)
		{
			RbtNode res = _alloc.allocate(1);

			res->key = key;
			res->color = color;
			res->parent = NULL;
			res->left = nil;
			res->right = nil;
			return res;
		}
		RbtNode makeNilNode()
		{
			RbtNode nil = _alloc.allocate(1);

			nil->key = 0;
			nil->color = BLACK;
			nil->parent = NULL;
			nil->left = NULL;
			nil->right = NULL;
			return nil;
		}
		RbtNode minimum(RbtNode node)
		{
			while (node->left != nil)
			{
				node = node->left;
			}
			return node;
		}
		RbtNode maximum(RbtNode node)
		{
			while (node->right != nil)
			{
				node = node->right;
			}
			return node;
		}
		RbtNode getGrandNode(RbtNode curr)
		{
			if (curr->parent == nil)
				return NULL;
			return curr->parent->parent;
		}
		RbtNode getUncleNode(RbtNode curr)
		{
			RbtNode grand = getGrandNode(curr);
			if (grand == nil)
				return nullptr;
			if (grand->left == curr->parent)
				return grand->right;
			return grand->left;
		}
		void leftRotate(RbtNode x)
		{
			RbtNode y = x->right;
			
			x->right = y->left;
			if (y->left != nil)
				y->left->parent = x;
			y->parent = x->parent;
			if (x->parent == NULL)
				root = y;
			else if (x->parent->left == x)
				x->parent->left = y;
			else
				x->parent->right = y;
			y->left = x;
			x->parent = y;
		}
		void rightRotate(RbtNode x)
		{
			RbtNode y = x->left;

			x->left = y->right;
			if (y->right != nil)
				y->right->parent = x;
			y->parent = x->parent;
			if (x->parent == NULL)
				root = y;
			else if (x->parent->right == x)
				x->parent->right = y;
			else
				x->parent->left = y;
			y->right = x;
			x->parent = y;
		}
		void insertFix(RbtNode node)
		{
			RbtNode tmp = getUncleNode(node);

			while (node->parent->color == Rbtree::RED)
			{ // 나도 red, 부모도 red
				if (tmp->color == Rbtree::RED)
				{ // case 2. z.uncle = red
					tmp->color = Rbtree::BLACK;
					node->parent->color = Rbtree::BLACK;
					node->parent->parent->color = Rbtree::RED;
					node = node->parent->parent;
				}
				else {
					if (tmp == node->parent->parent->left)
					{
						if (node == node->parent->left)
						{ // case 3. triangle(right)
							node = node->parent;
							rightRotate(node);
						}
						node->parent->color = Rbtree::BLACK; // case 4. line(right)
						node->parent->parent->color = Rbtree::RED;
						leftRotate(node->parent->parent);
					}
					else {
						if (node == node->parent->right)
						{ // case 3. triangle(left)
							node = node->parent;
							leftRotate(node);
						}
						node->parent->color = Rbtree::BLACK; // case 4. line(left)
						node->parent->parent->color = Rbtree::RED;
						rightRotate(node->parent->parent);
					}
				}
				if (node == root)
					break;
			}
			root->color = Rbtree::BLACK;
		}
		void deleteFix(RbtNode x)
		{
			RbtNode s; // x's sibling
			while (x != root && x->color == BLACK)
			{
				if (x == x->parent->left)
				{
					s = x->parent->right;
					if (s->color == RED)
					{
						s->color = BLACK;
						x->parent->color = RED;
						leftRotate(x->parent);
						s = x->parent->right;
					}
					if (s->left->color + s->right->color == 0)
					{
						s->color = 1;
						x = x->parent;
					}
					else
					{
						if (s->right->color == BLACK)
						{
							s->left->color = BLACK;
							s->color = RED;
							rightRotate(s);
							s = x->parent->right;
						}
						s->color = x->parent->color;
						x->parent->color = BLACK;
						s->right->color = BLACK;
						leftRotate(x->parent);
						x = root;
					}
				}
				else
				{
					s = x->parent->left;
					if (s->color == RED)
					{

						s->color = BLACK;
						x->parent->color = RED;
						rightRotate(x->parent);
						s = x->parent->left;
					}
					if (s->right->color + s->right->color == 0)
					{
						s->color = RED;
						x = x->parent;
					}
					else
					{
						if (s->left->color == BLACK)
						{
							s->right->color = BLACK;
							s->color = RED;
							leftRotate(s);
							s = x->parent->left;
						}
						s->color = x->parent->color;
						x->parent->color = BLACK;
						s->left->color = BLACK;
						rightRotate(x->parent);
						x = root;
					}
				}
			}
			x->color = BLACK;
		}
		void nodeReplace(RbtNode u, RbtNode v)
		{
			if (u->parent == NULL) // u == root
				root = v;
			else if (u == u->parent->left) // u == left child
				u->parent->left = v;
			else // u == right child
				u->parent->right = v;
			v->parent = u->parent;
		}
		void printHelper(RbtNode root, std::string indent, bool last)
		{
			if (root != nil)
			{
				std::cout << indent;
				if (last)
				{
					std::cout << "R----";
					indent += "	 ";
				}
				else
				{
					std::cout << "L----";
					indent += "|	";
				}

				std::string sColor = root->color ? "RED" : "BLACK";
				std::cout << root->key << "(" << sColor << ")" << std::endl;
				printHelper(root->left, indent, false);
				printHelper(root->right, indent, true);
			}
		}
		void printTree()
		{
			if (root)
				printHelper(root, "", true);
		}
	};
}


#endif