#ifndef __RED_BLACK_TREE_HPP__
#define __RED_BLACK_TREE_HPP__

# include <memory>
# include <iostream>
namespace ft {
	// color enum: BLACK = 0, RED = 1
	// enum Color { BLACK, RED	};
	// tree class
	template<typename T, typename Alloc = std::allocator<T> >
	class Rbtree {
	public:
		// node struct
	enum Color { BLACK, RED	};
		template<typename type>
		struct Node {
			type key;
			int color;
			Node *left;
			Node *right;
			Node *parent;
		};
		typedef T value_type;
		typedef Node<value_type> *rbt_node;
		size_t count;
		rbt_node root;
	private:
	public:
		// -----constructor, destructor
		Rbtree(): count(0), root(NULL) {}
		Rbtree(T key): count(0), root(NULL) { insertNode(root, key); }
		~Rbtree() { /*clearAll();*/ }

		// -----operation insert, delete, search
		void insertNode(value_type key)  {
			std::cout << "let's insert " << key << std::endl;
			rbt_node node = makeNode(key, Rbtree::RED);
			rbt_node now = root;
			rbt_node parent = NULL;

			while (now != NULL) {
				parent = now;
				if (now->key > key)
					now = now->left;
				else
					now = now->right;
					node->parent = parent;
			}
			if (parent == NULL) { // tmp가 루트가 된다
				root = node;
				node->color = Rbtree::BLACK;
				return ;
			}
			if (parent->key > key)
				parent->left = node;
			else
				parent->right = node;
			
			if (node->parent->parent == NULL) // tmp가 루트의 자식. 바꿔줄 필요 없다.
				return ;
			insert_fix(node);	
		}
		void deleteNode(value_type key);
		rbt_node searchNode(value_type key) {
			rbt_node now = root;
			while (now != NULL && now->key != key) {
				if (now->key > key)
					now = now->left;
				else
					now = now->right;
			}
			return now;
		}

		// -----utils_tree
		rbt_node makeNode(value_type key, int color, rbt_node parent = NULL, rbt_node left = NULL, rbt_node right = NULL) {
			rbt_node res = new Node<value_type>;

			res->key = key;
			res->color = color;
			res->parent = parent;
			res->left = left;
			res->right = right;
			return res;
		}
		rbt_node getGrandNode(rbt_node curr) {
			if (curr->parent == NULL)
				return NULL;
			return curr->parent->parent;
		}
		rbt_node getUncleNode(rbt_node curr) {
			rbt_node grand = getGrandNode(curr);
			if (grand == nullptr)
				return nullptr;
			if (grand->left == curr->parent)
				return grand->right;
			return grand->left;
		}
		void left_rotate(rbt_node x) {
			rbt_node y = x->right;
			
			x->right = y->left;
			if (y->left != NULL)
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
		void right_rotate(rbt_node x) {
			rbt_node y = x->left;

			x->left = y->right;
			if (y->right != NULL)
				y->right->parent = x;
			y->right->parent = x;
			if (x->parent == NULL)
				root = y;
			else if (x->parent->left == x)
				x->parent->left = y;
			else
				x->parent->right = y;
			y->right = x;
			x->parent = y;
		}
		void insert_fix(rbt_node node) {
			rbt_node tmp = getUncleNode(node);

			while (node->parent->color == Rbtree::RED) { // 나도 red, 부모도 red
				if (tmp->color == Rbtree::RED) { // case 2. z.uncle = red
					tmp->color = Rbtree::BLACK;
					node->parent->color = Rbtree::BLACK;
					node->parent->parent->color = Rbtree::RED;
					node = node->parent->parent;
				}
				else {
					if (tmp == node->parent->parent->left) {
						if (node == node->parent->left) { // case 3. triangle(right)
							node = node->parent;
							right_rotate(node);
						}
						node->parent->color = Rbtree::BLACK; // case 4. line(right)
						node->parent->parent->color = Rbtree::RED;
						left_rotate(node->parent->parent);
					}
					else {
						if (node == node->parent->right) { // case 3. triangle(left)
							node = node->parent;
							left_rotate(node);
						}
						node->parent->color = Rbtree::BLACK; // case 4. line(left)
						node->parent->parent->color = Rbtree::RED;
						right_rotate(node->parent->parent);
					}
				}
				if (node == root)
					break;
			}
			root->color = Rbtree::BLACK;
		}
		void check_right(rbt_node node);
		void clearAll();


		void traverse(rbt_node node) {
			std::cout << node->key << " ";
			if (node->left) {traverse(node->left);}
			if (node->right) {traverse(node->right);}
		}
	};
}


#endif