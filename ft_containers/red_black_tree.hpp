#ifndef __RED_BLACK_TREE_H__
# define __RED_BLACK_TREE_H__

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
			clear();
		}

		rbt_node *makeNode(key_type key, bool color, rbt_node *left = NULL, rbt_node *right = NULL, rbt_node *parent) {
			rbt_node *res = new rbt_node;

			res->key = key;
			res->color = color;
			res->left = left;
			res->right = right;
			res->parent = parent;

			return res;
		}
		void insertNode(key_type key) {

		}
		void deleteNode(key_type key);
		void searchNode(key_type key);
		void clear();

		// -----utils_tree-----
		void left_rotate(rbt_node *node);
		void right_rotate(rbt_node *node);
		void check_right(rbt_node *node);
		
	};
}


#endif