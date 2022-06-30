#ifndef __RED_BLACK_TREE_HPP__
#define __RED_BLACK_TREE_HPP__

# include <memory>
# include <iostream>
# include "pair.hpp"
# include "map_iter.hpp"
# include "iterator_traits.hpp"

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

		Node(): data(type()), color(BLACK), left(ft::nil), right(ft::nil), parent(ft::nil) { }
		Node(type &d): data(d), color(RED), left(ft::nil), right(ft::nil), parent(ft::nil) { }
		Node(const Node& copy): data(copy.data), color(copy.color), left(copy.left), right(copy.right), parent(copy.parent) {}
		~Node() {}

		Node &operator=(const Node& origin)
		{
			if (this != &origin)
			{
				data = origin.data;
				color = origin.color;
				left = origin.left;
				right = origin.right;
				parent = origin.parent;
			}
			return *this;
		}
	};
	// non-member function for Node
	template<typename node_ptr>
	bool isRightChild(const node_ptr &ptr)
	{
		return ptr == ptr->parent->right;
	}
	template<typename node_ptr>
	bool isLeftChild(const node_ptr &ptr)
	{
		return ptr == ptr->parent->left;
	}
	template<typename node_ptr>
	node_ptr minNode(node_ptr ptr, node_ptr nil)
	{
		while (ptr->left != nil)
			ptr = ptr->left;
		return ptr;
	}
	template<typename node_ptr>
	node_ptr maxNode(node_ptr ptr, node_ptr nil)
	{
		while (ptr->right != nil)
			ptr = ptr->right;
		return ptr;
	}
	template<typename node_ptr>
	node_ptr successor(node_ptr ptr, node_ptr nil)
	{
		if (ptr->right != nil)
			return minNode(ptr->right, nil);
		while (!isLeftChild(ptr))
			ptr = ptr->parent;
		return ptr->parent;
	}
	template<typename node_ptr>
	node_ptr predecessor(node_ptr ptr, node_ptr nil)
	{
		if (ptr->left != nil)
			return minNode(ptr->left, nil);
		while (!isRightChild(ptr))
			ptr = ptr->parent;
		return ptr->parent;
	}

	// tree class
	template<typename Key, typename T, typename Compare, typename Alloc = std::allocator<ft::pair<Key, T> > >
	class Rbtree {
	public:
		typedef Key key_type;
		typedef T value_type;
		typedef ft::pair<key_type, value_type> pair_t;
		typedef Node<pair_t> node_type;
		typedef Node<pair_t> *node_ptr;
		typedef mapIter<pair_t, node_type> iterator;
		typedef mapIter<const pair_t, node_type> const_iterator;

		typedef Compare key_compare;
		typedef Alloc allocator_type;
		typedef std::allocator<node_type> node_allocator;
		typedef std::allocator_traits<node_allocator> node_traits;

		typedef std::size_t size_type;
		typedef std::ptrdiff_t difference_type;
	private:
		node_ptr _begin;
		node_ptr _end;
		node_ptr _nil;
		node_allocator _alloc;
		key_compare _comp;
		size_type _size;
		// begin, end, nil node 세개 변수로 갖고 nil의 left, right, parent 전부 자기자신 nil. end의 left가 root, right랑 parent는 nil, 비교는 다 nil로 하고 비교할 때 인자로 nil 넘기기.
	public:
		// -----constructor, destructor, operator=
		Rbtree(const key_compare &comp, const allocator_type &alloc): _comp(comp), _alloc(alloc), _size(size_type())
		{
			_nil = _alloc.allocate(1);
			_alloc.construct(_nil, pair_t());
			_nil->color = BLACK;
			_nil->parent = _nil;
			_nil->left = _nil;
			_nil->right = _nil;
			_end = makeNode(pair_t());
			_end->color = BLACK;
			_begin = _end;
		}
		Rbtree(const Rbtree& copy): _comp(comp), _alloc(alloc), _size(size_type())
		{
			_nil = _alloc.allocate(1);
			_alloc.construct(_nil, pair_t());
			_nil->color = BLACK;
			_nil->parent = _nil;
			_nil->left = _nil;
			_nil->right = _nil;
			_end = makeNode(pair_t());
			_end->color = BLACK;
			_begin = _end;
			insert(copy.begin(), copy.end());
		}
		~Rbtree()
		{
			while (_end->right)
				deleteNode(_end->left->data.first);
			deleteNode(_nil);
		}
		Rbtree& operator=(const Rbtree& origin)
		{
			if (this != &origin)
			{
				Rbtree tmp(origin);
				swap(tmp);
			}
			return *this;
		}


		// iterator
		iterator begin()
		{
			return iterator(_begin, _nil);
		}
		const_iterator begin() const
		{
			return const_iterator(_begin, _nil);
		}
		iterator end()
		{
			return iterator(_end, _nil_);
		}
		const_iterator end() const
		{
			return const_tierator(_end, _nil);
		}
		// capacity
		size_type size() const
		{
			return _size;
		}
		size_type max_size() const
		{
			return std::min<size_type>(std::numeric_limits<size_type>::max(), node_traits::max_size(node_allocator()));
		}
		bool empty() const
		{
			return _size == 0;
		}
		// modifier
		ft::pair<iterator, bool> insert(const pair_t& value)
		{
			node_pointer ptr = searchNode(value);
			if (ptr != _end && isEqual(ptr->data, value, _comp))
				return ft::make_pair(iterator(ptr, _nil), false);
			return ft::make_pair(iterator(insertNode(value, ptr), _nil), true);
		}
		iterator insert(iterator position, const pair_t& value)
		{
			node_pointer ptr = searchNode(value, position.base());
			if (ptr != _end && isEqual(ptr->data, value, _comp))
				return iterator(ptr, _nil);
			return iterator(insertNode(value, ptr), _nil);
		}
		template<typename InputIterator>
		void insert(InputIterator first, InputIterator last)
		{
			for (; first != last; first++)
				insert(*first);
		}
		iterator erase(iterator position)
		{
			if (_size == 0)
				return iterator(_nil, _nil);
			iterator tmp(position);
			++tmp;
			if (position == begin())
				_begin = tmp.base();
			--_size;
			removeNode(position.base());
			destructNode(position.base());
			return tmp;
		}
		template<typename U>
		size_type erase(const U& value)
		{
			iterator it(findNode(value), _nil);
			if (it == end())
				return 0;
			if (it == begin())
			{
				iterator tmp(it);
				++tmp;
				_begin = tmp.base();
			}
			--_size;
			removeNode(it.base());
			destructNode(it.base());
			return 1;
		}
		void erase(iterator first, iterator last)
		{
			for (; first != last; )
				first = erase(first);
		}
		void swap(Rbtree& x)
		{

		}
		void clear()
		{
			Rbtree tmp(_comp, _alloc);
			swap(tmp);
		}

		// lookup operation
		iterator find(const key_type& key)
		{
			return iterator(findNode(key), _nil);
		}
		const_iterator find(const key_type& key) const
		{
			return const_iterator(findNode(key), _nil);
		}
		iterator lower_bound(const key_type &key)
		{
			return iterator(lowerboundNode(key), _nil);
		}
		const_iterator lower_bound(const key_type &key) const
		{
			return const_iterator(lowerboundNode(key), _nil);
		}
		iterator upper_bound(const key_type &key)
		{
			return iterator(upperboundNode(key), _nil);
		}
		const_iterator upper_bound(const key_type &key) const
		{
			return const_iterator(upperboundNode(key), _nil);
		}
		ft::pair<iterator, iterator> equal_range(const key_type &key)
		{
			return equalRange(key);
		}
		ft::pair<const_iterator, const_iterator> equal_range(const key_type &key) const
		{
			return equalRange(key);
		}
		allocator_type get_allocator() const
		{
			return _alloc;
		}

		// node functions
		node_pointer getRoot







		







		// -----operation insert, delete, search
		void insertNode(pair_t nvalue)
		{
			node_ptr node = makeNode(nvalue, RED);
			node_ptr now = root;
			node_ptr x = NULL; // 부모 노드 저장
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
			node_ptr x, y;  // y: 대체할 노드
			node_ptr z; // z: 지울 노드
			int y_origin_c;

			z = searchNode(dkey);
			if (isNil(z)) // key not found in tree
			{
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
		node_ptr searchNode(key_type skey)
		{
			node_ptr now = root;
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
		node_ptr makeNode(pair_t key, int color)
		{
			node_ptr res = _alloc.allocate(1);

			res->data = key;
			res->color = color;
			res->parent = nil;
			res->left = nil;
			res->right = nil;
			return res;
		}
		node_ptr makeNilNode()
		{
			node_ptr nil = _alloc.allocate(1);

			nil->data = pair_t();
			nil->color = BLACK;
			nil->parent = nil;
			nil->left = nil;
			nil->right = nil;
			return nil;
		}

		node_ptr getGrandNode(node_ptr curr)
		{
			if (isNil(curr->parent))
				return NULL;
			return curr->parent->parent;
		}
		node_ptr getUncleNode(node_ptr curr)
		{
			node_ptr grand = getGrandNode(curr);
			if (isNil(grand))
				return NULL;
			if (grand->left == curr->parent)
				return grand->right;
			return grand->left;
		}
		void leftRotate(node_ptr x)
		{
			node_ptr y = x->right;
			
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
		void rightRotate(node_ptr x)
		{
			node_ptr y = x->left;

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
		void insertFix(node_ptr node)
		{
			node_ptr tmp = getUncleNode(node);

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
		void deleteFix(node_ptr x)
		{
			node_ptr s; // x's sibling
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
		void nodeReplace(node_ptr u, node_ptr v)
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
			std::cout << "clr_1" << std::endl;
			while (root != NULL)
			{
				std::cout << "clr_iter" << std::endl;
				node_ptr del = minimum(root);
				std::cout << "clr_after iter" << std::endl;
				if (isNil(del)) 
				{

					std::cout << "clr_branch" << std::endl;
					break;
				}
					std::cout << "clr_2" << std::endl;
				deleteNode(del->data.first);
					std::cout << "clr_3" << std::endl;
			}
					std::cout << "clr_4" << std::endl;
			nil = makeNilNode();
					std::cout << "clr_5" << std::endl;
			root = nil;
		}
		int isNil(node_ptr node)
		{
			if (node == NULL)
				return 1;
			return node->right == NULL && node->left == NULL;
		}
		void printHelper(node_ptr root, std::string indent, bool last)
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