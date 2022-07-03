#ifndef __RED_BLACK_TREE_HPP__
#define __RED_BLACK_TREE_HPP__

# include <memory>
# include <iostream>
# include "pair.hpp"
# include "map_iter.hpp"
# include "iterator_traits.hpp"
# include "reverse_iterator.hpp"

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
		Node(const type &d): data(d), color(RED), left(ft::nil), right(ft::nil), parent(ft::nil) { }
		Node(const Node& copy): data(copy.data), color(copy. color), left(copy.left), right(copy.right), parent(copy.parent) {}
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
	template<typename Key, typename T, typename Compare, typename Alloc>
	class Rbtree {
	public:
		typedef Key key_type;
		typedef T value_type;
		typedef ft::pair<const key_type, value_type> pair_t;
		typedef Node<pair_t> node_type;
		typedef Node<pair_t> *node_ptr;
		typedef treeIter<pair_t, node_type> iterator;
		typedef treeIter<const pair_t, node_type> const_iterator;

		typedef Compare key_compare;
		typedef Alloc allocator_type;
		typedef typename allocator_type::template rebind<node_type>::other node_allocator;
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
		Rbtree(const key_compare &comp, const allocator_type &alloc): _alloc(alloc), _comp(comp), _size(size_type())
		{
			_nil = _alloc.allocate(1);
			_alloc.construct(_nil, node_type());
			_nil->color = BLACK;
			_nil->parent = _nil;
			_nil->left = _nil;
			_nil->right = _nil;
			_end = makeNode(pair_t());
			_end->color = BLACK;
			_begin = _end;
		}
		Rbtree(const Rbtree& copy): _comp(copy._comp), _alloc(copy._alloc), _size(size_type())
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
			while (_end->left != _nil)
				deleteNode(_end->left);
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

		// iterator for map
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
			return iterator(_end, _nil);
		}
		const_iterator end() const
		{
			return const_tierator(_end, _nil);
		}
		// capacity for map
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
		// modifier for map
		ft::pair<iterator, bool> insert(const pair_t& value)
		{
			node_ptr ptr = searchParent(value);
			if (ptr != _end && isEqual(ptr->data, value, _comp))
				return ft::make_pair(iterator(ptr, _nil), false);
			return ft::make_pair(iterator(insertNode(value, ptr), _nil), true);
		}
		iterator insert(iterator position, const pair_t& value)
		{
			node_ptr ptr = searchParent(value, position.base());
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
			if (operator==(position, begin()))
				_begin = tmp.base();
			--_size;
			deleteNode(position.base());
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
		template<typename Tmp>
		void swap_tree(Tmp &a, Tmp &b)
		{
			Tmp tmp = a;

			a = b;
			b = tmp;
		}
		void swap(Rbtree& x)
		{
			swap_tree(_begin, x._begin);
			swap_tree(_end, x._end);
			swap_tree(_nil, x._nil);
			swap_tree(_alloc, x._alloc);
			swap_tree(_comp, x._comp);
			swap_tree(_size, x._size);
		}
		void clear()
		{
			Rbtree tmp(_comp, _alloc);
			swap(tmp);
		}
		// operation for map
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

		// tree functions
		node_ptr getRoot() const
		{
			return _end->left;
		}
		void setRoot(const node_ptr ptr)
		{
			ptr->parent = _end;
			_end->left = ptr;
		}
		node_ptr makeNode(const pair_t &value)
		{
			node_ptr ret = _alloc.allocate(1);

			_alloc.construct(ret, node_type(value));
			ret->color = RED;
			ret->parent = _nil;
			ret->left = _nil;
			ret->right = _nil;
			return ret;
		}
		void destructNode(node_ptr ptr)
		{
			_alloc.destroy(ptr);
			_alloc.deallocate(ptr, 1);
		}
		void destructAllNode(node_ptr ptr)
		{
			if (ptr == _nil)
				return;
			destructAllNode(ptr->left);
			destructAllNode(ptr->right);
			destructNode(ptr);
		}
		node_ptr findNode(const key_type &key) const
		{
			node_ptr ptr = getRoot();
			while (ptr != _nil)
			{
				if (_comp(key, ptr->data.first))
					ptr = ptr->left;
				else if (_comp(ptr->data.first, key))
					ptr = ptr->right;
				else
					return ptr;
			}
			return _end;
		}
		node_ptr lowerboundNode(const key_type &key)
		{
			node_ptr ptr = getRoot();
			node_ptr tmp = _end;

			while (ptr != _nil)
			{
				if (!_comp(ptr->data.first, key))
				{
					tmp = ptr;
					ptr = ptr->left;
				}
				else
					ptr = ptr->right;
			}
			return tmp;
		}
		node_ptr upperboundNode(const key_type &key) const
		{
			node_ptr ptr = getRoot();
			node_ptr tmp = _end;

			while (ptr != _nil)
			{
				if (_comp(key, ptr->data.first))
				{
					tmp = ptr;
					ptr = ptr->left;
				}
				else
					ptr = ptr->right;
			}
			return tmp;
		}
		template<typename U>
		ft::pair<iterator, iterator> equalRange(const U& value)
		{
			node_ptr ptr = getRoot();
			node_ptr tmp = _end;

			while (ptr != _nil)
			{
				if (_comp(value, ptr->data.first))
				{
					tmp = ptr;
					ptr = ptr->left;
				}
				else if (_comp(ptr->data.first, value))
					ptr = ptr->right;
				else
				{
					if (ptr->right != _nil)
						tmp = minNode(ptr->right, _nil);
					return ft::make_pair(iterator(ptr, _nil), iterator(tmp, _nil));
				}
			}
			return ft::make_pair(iterator(tmp, _nil), iterator(tmp, _nil));
		}
		template<typename U>
		ft::pair<const_iterator, const_iterator> equalRange(const U& value)
		{
			node_ptr ptr = getRoot();
			node_ptr tmp = _end;

			while (ptr != _nil)
			{
				if (_comp(value, ptr->data.first))
				{
					tmp = ptr;
					ptr = ptr->left;
				}
				else if (_comp(ptr->data.first, value))
					ptr = ptr->right;
				else
				{
					if (ptr->right != _nil)
						tmp = minNode(ptr->right, _nil);
					return ft::make_pair(const_iterator(ptr, _nil), const_iterator(tmp, _nil));
				}
			}
			return ft::make_pair(const_iterator(tmp, _nil), const_iterator(tmp, _nil));
		}
		void leftRotate(node_ptr ptr)
		{
			node_ptr child = ptr->right;
			node_ptr parent;

			ptr->right = child->left;
			if (ptr->right != _nil)
				ptr->right->parent = ptr;
			parent = ptr->parent;
			child->parent = parent;
			if (parent == _end)
				setRoot(child);
			else if (isLeftChild(ptr))
				parent->left = child;
			else
				parent->right = child;
			child->left = ptr;
			ptr->parent = child;
		}
		void rightRotate(node_ptr ptr)
		{
			node_ptr child = ptr->left;
			node_ptr parent;

			ptr->left = child->right;
			if (ptr->left != _nil)
				ptr->left->parent = ptr;
			parent = ptr->parent;
			child->parent = parent;
			if (parent == _end)
				setRoot(child);
			else if (isLeftChild(ptr))
				parent->left = child;
			else
				parent->right = child;
			child->right = ptr;
			ptr->parent = child;
		}
		void nodeReplace(node_ptr from, node_ptr to)
		{
			if (from->parent == _end) // from == root
				setRoot(to);
			else if (isLeftChild(from)) // from == left child
				from->parent->left = to;
			else // from == right child
				from->parent->right = to;
			to->parent = from->parent;
		}
		// insert, delete
		node_ptr insertNode(const pair_t &nvalue, node_ptr parent)
		{
			node_ptr ptr = makeNode(nvalue);
			if (parent == _end)
				setRoot(ptr);
			else if (_comp(nvalue, parent->data))
				parent->left = ptr;
			else
				parent->right = ptr;
			ptr->parent = parent;
			insertFix(ptr);
			if (_begin == _end || _comp(ptr->data, _begin->data))
				_begin = ptr;
			_size++;
			return ptr;
		}
		void insertFix(node_ptr ptr)
		{
			node_ptr uncle;

			while (ptr->parent->color == RED)
			{
				if (isLeftChild(ptr->parent))
				{
					uncle = ptr->parent->parent->right;
					if (uncle->color == RED)
					{
						ptr->parent->color = BLACK;
						uncle->color = BLACK;
						uncle->parent->color = RED;
						ptr = uncle->parent;
					}
					else
					{
						if (isRightChild(ptr))
						{
							ptr = ptr->parent;
							leftRotate(ptr);
						}
						ptr->parent->color = BLACK;
						ptr->parent->parent->color = RED;
						rightRotate(ptr->parent->parent);
					}
				}
				else
				{
					uncle = ptr->parent->parent->left;
					if (uncle->color == RED)
					{
						ptr->parent->color = BLACK;
						uncle->color = BLACK;
						uncle->parent->color = RED;
						ptr = uncle->parent;
					}
					else
					{
						if (isLeftChild(ptr))
						{
							ptr = ptr->parent;
							rightRotate(ptr);
						}
						ptr->parent->color = BLACK;
						ptr->parent->parent->color = RED;
						leftRotate(ptr->parent->parent);
					}
				}
			}
			getRoot()->color = BLACK;
		}
		void deleteNode(node_ptr ptr)
		{
			node_ptr recolor_node;
			node_ptr fix_node = ptr;
			int origin_color = ptr->color;

			if (ptr->left == _nil)
			{
				recolor_node = ptr->right;
				nodeReplace(ptr, ptr->right);
			}
			else if (ptr->right == _nil)
			{
				recolor_node = ptr->left;
				nodeReplace(ptr, ptr->left);
			}
			else
			{
				fix_node = minNode(ptr->right, _nil);
				origin_color = fix_node->color;
				recolor_node = fix_node->right;
				if (fix_node->parent == ptr)
					recolor_node->parent = fix_node;
				else
				{
					nodeReplace(fix_node, fix_node->right);
					fix_node->right = ptr->right;
					fix_node->right->parent = fix_node;
				}
				nodeReplace(ptr, fix_node);
				fix_node->left = ptr->left;
				fix_node->left->parent = fix_node;
				fix_node->color = ptr->color;
			}
			if (!origin_color)
				deleteFix(recolor_node);
		}
		void deleteFix(node_ptr ptr)
		{
			while (ptr != getRoot() && ptr->color == BLACK)
			{
				if (isLeftChild(ptr))
					deleteFix_left(ptr);
				else
					deleteFix_right(ptr);
			}
			ptr->color = BLACK;
		}
		void deleteFix_left(node_ptr ptr)
		{
			node_ptr sibling = ptr->parent->right;
			if (sibling->color == RED)
			{
				sibling->color = BLACK;
				ptr->parent->color = RED;
				leftRotate(ptr->parent);
				sibling = ptr->parent->right;
			}
			if (sibling->left->color == BLACK && sibling->right->color == BLACK)
			{
				sibling->color = RED;
				ptr = ptr->parent;
			}
			else if (sibling->right->color == BLACK)
			{
				sibling->left->color = BLACK;
				sibling->color = RED;
				rightRotate(sibling);
				sibling = ptr->parent->right;
			}
			if (sibling->right->color == RED)
			{
				sibling->color = ptr->parent->color;
				ptr->parent->color = BLACK;
				sibling->right->color = BLACK;
				leftRotate(ptr->parent);
				ptr = getRoot();
			}
		}
		void deleteFix_right(node_ptr ptr)
		{
			node_ptr sibling = ptr->parent->left;
			if (sibling->color == RED)
			{
				sibling->color = BLACK;
				ptr->parent->color = RED;
				rightRotate(ptr->parent);
				sibling = ptr->parent->left;
			}
			if (sibling->right->color == BLACK && sibling->left->color == BLACK)
			{
				sibling->color = RED;
				ptr = ptr->parent;
			}
			else if (sibling->left->color == BLACK)
			{
				sibling->right->color = BLACK;
				sibling->color = RED;
				leftRotate(sibling);
				sibling = ptr->parent->left;
			}
			if (sibling->left->color == RED)
			{
				sibling->color = ptr->parent->color;
				ptr->parent->color = BLACK;
				sibling->left->color = BLACK;
				rightRotate(ptr->parent);
				ptr = getRoot();
			}
		}
		template <typename U, typename V, class Comp>
		bool isEqual(const U& u, const V& v, Comp comp) {
			return !comp(u, v) && !comp(v, u);
		}
		node_ptr searchParent(const pair_t& value, node_ptr position = ft::nil)
		{
			if (position && position != _end)
			{
				if (_comp(value, position->data) && position->left == _nil)
				{
					iterator prev = iterator(position, _nil);
					if (operator==(prev, begin()) || _comp(*--prev, value))
						return position;
				}
				else if (position->right == _nil)
				{
					iterator next = iterator(position, _nil);
					if (operator==(next, end()) || _comp(value, *++next))
						return position;
				}
			}
			node_ptr cur = getRoot();
			node_ptr tmp = _end;
			for (; cur != _nil; )
			{
				tmp = cur;
				if (_comp(value, cur->data))
				{
					cur = cur->left;
				}
				else if (_comp(cur->data, value))
					cur = cur->right;
				else
					return cur;
			}
			return tmp;
		}
		// void printHelper(node_ptr root, std::string indent, bool last)
		// {
		// 	if (!isNil(root))
		// 	{
		// 		std::cout << indent;
		// 		if (last)
		// 		{
		// 			std::cout << "R----";
		// 			indent += "	 ";
		// 		}
		// 		else
		// 		{
		// 			std::cout << "L----";
		// 			indent += "|	";
		// 		}

		// 		std::string sColor = root->color ? "RED" : "BLACK";
		// 		std::cout << root->data.first << "(" << sColor << ")" << std::endl;
		// 		printHelper(root->left, indent, false);
		// 		printHelper(root->right, indent, true);
		// 	}
		// }
		// void printTree()
		// {
		// 	if (root)
		// 		printHelper(root, "", true);
		// }
	};

}


#endif