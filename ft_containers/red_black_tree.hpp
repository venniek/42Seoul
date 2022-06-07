#ifndef __RED_BLACK_TREE_HPP__
#define __RED_BLACK_TREE_HPP__

# include <memory>

namespace ft {
	// color enum: RED = 0, BLACK = 1
	enum Color { BLACK, RED	};
	// node struct
	template<typename T>
	struct node {
		T key;
		int color;
		struct node *left;
		struct node *right;
		struct node *parent;
	};

	template<typename T>
	typedef struct node rbt_node;
	
	// tree class
	template<typename T, typename Alloc = std::allocator<T> >
	class Rbtree {
	private:
		typedef typename T T;
		size_t count;
		rbt_node *tree;
	public:
		Rbtree();
		Rbtree(T key);
		~Rbtree();
		
		// -----operation insert, delete, search
		void insertNode(T key);
		void deleteNode(T key);
		rbt_node *searchNode(T key);

		// -----utils_tree
		rbt_node *makeNode(T key, int color, rbt_node *parent = NULL, rbt_node *left = NULL, rbt_node *right = NULL);
		rbt_node *getGrandNode(rbt_node *curr);
		rbt_node *getUncleNode(rbt_node *curr);
		void left_rotate(rbt_node *x);
		void right_rotate(rbt_node *x);
		void insert_fix(rbt_node *node);
		void check_right(rbt_node *node);
		void clearAll();
	};

	// constructor, destructor
	template<typename T, typename Alloc>
	Rbtree<T, Alloc>::Rbtree(): count(0), tree(NULL) {}
	template<typename T, typename Alloc>
	Rbtree<T, Alloc>::Rbtree(T key): count(0), tree(NULL) { insertNode(tree, key); }
	template<typename T, typename Alloc>
	Rbtree<T, Alloc>::~Rbtree() { clearAll(); }

	// -----operatio insert, delete, search
	template<typename T, typename Alloc>
	rbt_node *Rbtree<T, Alloc>::makeNode(T key, int color, rbt_node *parent = NULL, rbt_node *left = NULL, rbt_node *right = NULL) {
		rbt_node *res = new rbt_node;

		res->key = key;
		res->color = color;
		res->parent = parent;
		res->left = left;
		res->right = right;
		return res;
	}
	template<typename T, typename Alloc>
	void Rbtree<T, Alloc>::insertNode(T key) {
		int node = makeNode(key, Color.Red);
		int now = tree;
		int parent = NULL;

		while (now != NULL) {
			parent = now;
			if (now->key > key)
				now = now->left;
			else
				now = now->right;
		}

		node->parent = parent;
		if (parent == NULL) { // tmp가 루트가 된다
			tree = node;
			node->color = Color.BLACK;
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
	template<typename T, typename Alloc>
	void Rbtree<T, Alloc>::deleteNode(T key) {
		rbt_node *del = searchNode(key);

		if (del == NULL)
			return ;
		
		
	}
	template<typename T, typename Alloc>
	rbt_node *Rbtree<T, Alloc>::searchNode(T key) {
		rbt_node *now = tree;
		while (now != NULL && now->key != key) {
			if (now->key > key)
				now = now->left;
			else
				now = now->right;
		}
		return now;
	}
	template<typename T, typename Alloc>
	void Rbtree<T, Alloc>::clearAll() {
		
	}

	// -----utils_tree-----
	template<typename T, typename Alloc>
	rbt_node *Rbtree<T, Alloc>::getGrandNode(rbt_node *curr) {
		if (curr->parent == NULL)
			return NULL;
		return curr->parent->parent;
	}
	template<typename T, typename Alloc>
	rbt_node *Rbtree<T, Alloc>::getUncleNode(rbt_node *curr) {
		rbt_node *grand = getGrandNode(curr);
		if (grand == nullptr)
			return nullptr;
		if (grand->left == curr->parent)
			return grand->right;
		return grand->left;
	}
	template<typename T, typename Alloc>
	void Rbtree<T, Alloc>::left_rotate(rbt_node *x) {
		rbt_node *y = x->right;
		
		x->right = y->left;
		if (y->left != NULL)
			y->left->parent = x;
		y->parent = x->parent;
		if (x->parent == NULL)
			tree = y;
		else if (x->parent->left == x)
			x->parent->left = y;
		else
			x->parent->right = y;
		y->left = x;
		x->parent = y;
	}
	template<typename T, typename Alloc>
	void Rbtree<T, Alloc>::right_rotate(rbt_node *x) {
		rbt_node *y = x->left;

		x->left = y->right;
		if (y->right != NULL)
			y->right->parent = x;
		y->right->parent = x;
		if (x->parent == NULL)
			tree = y;
		else if (x->parent->left == x)
			x->parent->left = y;
		else
			x->parent->right = y;
		y->right = x;
		x->parent = y;
	}
	template<typename T, typename Alloc>
	void Rbtree<T, Alloc>::insert_fix(rbt_node *node) {
		rbt_node *tmp = getUncleNode(node);

		while (node->parent->color == Color.RED) { // 나도 red, 부모도 red
			if (tmp->color == Color.RED) { // case 2. z.uncle = red
				tmp->color = Color.BLACK;
				node->parent->color = Color.BLACK;
				node->parent->parent->color = Color.RED;
				node = node->parent->parent;
			}
			else {
				if (tmp == node->parent->parent->left) {
					if (node == node->parent->left) { // case 3. triangle(right)
						node = node->parent;
						right_rotate(node);
					}
					node->parent->color = Color.BLACK; // case 4. line(right)
					node->parent->parent->color = Color.RED;
					left_rotate(node->parent->parent);
				}
				else {
					if (node == node->parent->right) { // case 3. triangle(left)
						node = node->parent;
						left_rotate(node);
					}
					node->parent->color = Color.BLACK; // case 4. line(left)
					node->parent->parent->color = Color.RED;
					right_rotate(node->parent->parent);
				}
			}
			if (node == tree)
				break;
		}
		tree->color = Color.BLACK;
	}
}


#endif