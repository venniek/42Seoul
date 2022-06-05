#ifndef __RED_BLACK_TREE_H__
#define __RED_BLACK_TREE_H__

# define RED true
# define BLACK false
# include <memory>

namespace ft {

	template<typename T>
	struct node {
		T key;
		bool color;
		struct node *left;
		struct node *right;
		struct node *parent;
	};

	template<typename T>
	class Rbtree {
	private:
		typedef struct node rbt_node;
		typedef typename T key_type;
		rbt_node *tree;
	public:
		Rbtree() {
			tree = NULL;
		}
		Rbtree(key_type key) {
			rbt_node *tmp = new rbt_node;

			tree = makeNode(key, RED, NULL, NULL, NULL);
		}
		~Rbtree() {
			clearAll();
		}

		rbt_node *makeNode(key_type key, bool color, rbt_node *parent = NULL, rbt_node *left = NULL, rbt_node *right = NULL) {
			rbt_node *res = new rbt_node;

			res->key = key;
			res->color = color;
			res->parent = parent;
			res->left = left;
			res->right = right;
			return res;
		}
		void insertNode(rbt_node *parent, key_type key) {

		}
		void deleteNode(key_type key);
		void searchNode(key_type key);
		void clearAll() {
			
		}

		// -----utils_tree-----
		rbt_node *getGrandNode(rbt_node *curr) {
			return curr->parent->parent;
		}
		rbt_node *getUncleNode(rbt_node *curr) {
			rbt_node *grand = getGrandNode(curr);
			if (grand == nullptr)
				return nullptr;
			if (grand->left == curr->parent)
				return grand->right;
			return grand->left;
		}
		void left_rotate(rbt_node *x) {
			rbt_node *y = x->right;
			int flag;

			if (x->parent->left == x)
				flag = 0;
			else
				flag = 1;
			y->parent = x->parent;
			x->right = y->left;
			y->left = x;
			if (flag == 0)
				y->parent->left = y;
			else
				y->parent->right = y;
		}
		void right_rotate(rbt_node *node) {
			rbt_node *y = x->left;
			int flag;

			if (x->parent->left == x)
				flag = 0;
			else
				flag = 1;
			y->parent = x->parent;
			x->left = y->right;
			y->right = x;
			if (flag == 0)
				y->parent->left = y;
			else
				y->parent->right = y;
		}
		void insert_fix()
		void check_right(rbt_node *node);
		
	};
}


#endif