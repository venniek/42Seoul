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
	// tree class
	template<typename Key, typename T, typename Compare, typename Alloc = std::allocator<ft::pair<Key, T> > >
	class Rbtree {
	public:

		typedef Key key_type;
		typedef T mapped_type;
		typedef ft::pair<key_type, mapped_type> pair_t;
		typedef Compare key_compare;
		typedef Node<pair_t> *RbtNode;
		typedef Alloc allocator_type;

		std::allocator<Node<pair_t> > _alloc;
		RbtNode root;
		RbtNode nil;
		
		// -----constructor, destructor
		Rbtree() : nil(makeNilNode())
		{
			root = nil;
		}
		~Rbtree()
		{
			this->clear();
			if (nil)
			{
				_alloc.destroy(nil);
				_alloc.deallocate(nil, 1);
			}
		}
		Rbtree(const Rbtree &copy)
		{
			*this = copy;
		}
		Rbtree& operator=(const Rbtree& origin)
		{
			if (this != &origin)
			{
				this->clear();
				RbtNode now;
				if (origin.root == origin.nil)
					now = origin.root;
				else
					now = this->minimum(origin.root);
				while (!isNil(now))
				{
					this->insertNode(now->data);
					now = this->successor(now);
				}
			}
			return *this;
		}

		// -----operation insert, delete, search
		void insertNode(pair_t nvalue)
		{
			RbtNode node = makeNode(nvalue, RED);
			RbtNode now = root;
			RbtNode x = NULL; // 부모 노드 저장
			key_compare comp = key_compare();
			while (!isNil(now))
			{
				x = now;
				if (comp(nvalue.first, now->data.first))
					now = now->left;
				else
					now = now->right;
			}
			node->parent = x;
			if (x == NULL)
			{ // tmp가 루트가 된다
				root = node;
				node->color = BLACK;
				return ;
			}
			if (comp(node->data.first, nvalue.first))
				x->left = node;
			else
				x->right = node;
			if (node->parent->parent == NULL) // tmp가 루트의 자식. 바꿔줄 필요 없다.
				return ;
			insertFix(node);
		}
		void deleteNode(key_type dkey)
		{
			RbtNode x, y;  // y: 대체할 노드
			RbtNode z; // z: 지울 노드
			int y_origin_c;

			z = searchNode(dkey);
			if (isNil(z)) // key not found in tree
			{
				std::cout << dkey << " is not in the tree" << std::endl;
				return ;
			}
			y = z;
			y_origin_c = y->color; // 없어지는 색 == 지울 노드(바뀔 수 있음. 우선 대입해놓기)
			if (isNil(z->left)) // 자식 없거나 하나인지 검사
			{
				x = z->right;
				nodeReplace(z, z->right);
			}
			else if (isNil(z->right)) //
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
			if (y_origin_c == BLACK)
				deleteFix(x);
		}
		RbtNode searchNode(key_type skey)
		{
			RbtNode now = root;
			key_compare comp = key_compare();

			while (!isNil(now)  && now->data.first != skey)
			{
				if (comp(skey, now->data.first))
					now = now->left;
				else
					now = now->right;
			}
			return now;
		}

		// -----utils_tree
		RbtNode makeNode(pair_t key, int color)
		{
			RbtNode res = _alloc.allocate(1);

			res->data = key;
			res->color = color;
			res->parent = nil;
			res->left = nil;
			res->right = nil;
			return res;
		}
		RbtNode makeNilNode()
		{
			RbtNode nil = _alloc.allocate(1);

			nil->data = pair_t();
			nil->color = BLACK;
			nil->parent = NULL;
			nil->left = NULL;
			nil->right = NULL;
			return nil;
		}

		RbtNode minimum(RbtNode node)
		{
			if (!isNil(node))
			{
				while (!isNil(node->left))
					node = node->left;
			}
			return node;
		}
		RbtNode maximum(RbtNode node)
		{
			while (!isNil(node->right))
				node = node->right;
			return node;
		}
		RbtNode successor(RbtNode x)
		{
			if (!isNil(x->right))
				return minimum(x->right);
			RbtNode y = x->parent;
			while (!isNil(y) && x == y->right)
			{
				x = y;
				y = y->parent;
			}
			return y;
		}
		RbtNode predecessor(RbtNode x)
		{
			if (!isNil(x->right))
				return maximum(x->left);
			RbtNode y = x->parent;
			while (!isNil(y) && x == y->left)
			{
				x = y;
				y = y->parent;
			}

			return y;
		}
		RbtNode getGrandNode(RbtNode curr)
		{
			if (isNil(curr->parent))
				return NULL;
			return curr->parent->parent;
		}
		RbtNode getUncleNode(RbtNode curr)
		{
			RbtNode grand = getGrandNode(curr);
			if (isNil(grand))
				return NULL;
			if (grand->left == curr->parent)
				return grand->right;
			return grand->left;
		}
		void leftRotate(RbtNode x)
		{
			RbtNode y = x->right;
			
			x->right = y->left;
			if (!isNil(y->left))
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
			if (!isNil(y->right))
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

			while (node->parent->color == ft::RED)
			{ // 나도 red, 부모도 red
				if (tmp->color == ft::RED)
				{ // case 2. z.uncle = red
					tmp->color = ft::BLACK;
					node->parent->color = ft::BLACK;
					node->parent->parent->color = ft::RED;
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
						node->parent->color = ft::BLACK; // case 4. line(right)
						node->parent->parent->color = ft::RED;
						leftRotate(node->parent->parent);
					}
					else {
						if (node == node->parent->right)
						{ // case 3. triangle(left)
							node = node->parent;
							leftRotate(node);
						}
						node->parent->color = ft::BLACK; // case 4. line(left)
						node->parent->parent->color = ft::RED;
						rightRotate(node->parent->parent);
					}
				}
				if (node == root)
					break;
			}
			root->color = ft::BLACK;
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
		void clear()
		{
			while (root != NULL)
			{
				RbtNode del = minimum(root);
				if (isNil(del))
					break;
				_alloc.destroy(del);
				_alloc.deallocate(del, 1);
			}
			nil = makeNilNode();
			root = nil;
		}
		int isNil(RbtNode node)
		{
			return node->right == NULL && node->left == NULL;
		}
		void printHelper(RbtNode root, std::string indent, bool last)
		{
			if (!isNil(root))
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
				std::cout << root->data.first << "(" << sColor << ")" << std::endl;
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