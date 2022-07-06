#ifndef __AVLTREE_HPP__
#define __AVLTREE_HPP__

# include "pair.hpp"
# include "iterator_traits.hpp"

namespace ft {
	template<typename T>
	struct Node {
		T data;
		Node *parent;
		Node *left;
		Node *right;

		Node(const T &_data = T()): data(_data), parent(NULL), left(NULL), right(NULL) { }
		template<typename pair_t>
		Node& operator=(const Node<pair_t>& origin) {
			if (this != &origin) {
				this->data = origin.data;
				this->parent = origin.parent;
				this->left = origin.left;
				this->right = origin.right;
			}
			return *this;
		}
	};
	// non-member function for Node
	template<typename node_ptr>
	bool isLeftChild(const node_ptr& node) {
		return node == node->parent->left;
	}
	template<typename node_ptr>
	bool isRightChild(const node_ptr& node) {
		return node == node->parent->right;
	}
	template<typename node_ptr>
	node_ptr minNode(node_ptr node) {
		if (node == NULL)
			return NULL;
		while (node->left != NULL)
			node = node->left;
		return node;
	}
	template<typename node_ptr>
	node_ptr maxNode(node_ptr node) {
		if (node == NULL)
			return NULL;
		while (node->right != NULL)
			node = node->right;
		return node;
	}
	template<typename node_ptr>
	int getHeight(node_ptr node) {
		if (node == NULL)
			return 0;
		int left_height = getHeight(node->left);
		int right_height = getHeight(node->right);
		return max(left_height, right_height) + 1;
	}
	template<typename node_ptr>
	int calculateBF(node_ptr node) {
		return getHeight(node->left) - getHeight(node->right);
	}
	template<typename node_ptr>
	node_ptr getNextNode(node_ptr node) {
		if (node->right != NULL)
			return minNode(node->right);
		while (node->parent != NULL && !isLeftChild(node))
			node = node->parent;
		return node->parent;
	}
	template<typename node_ptr>
	node_ptr getPrevNode(node_ptr node) {
		if (node->left != NULL)
			return maxNode(node->left);
		while (node->parent != NULL && !isRightChild(node))
			node = node->parent;
		return node->parent;
	}

	template<typename U, typename V>
    class map_iterator {
    public:
        typedef U value_type;
		typedef value_type* pointer;
		typedef value_type& reference;
		typedef V* iterator_type;
		typedef typename ft::iterator_traits<iterator_type>::difference_type difference_type;
		typedef typename ft::iterator_traits<iterator_type>::value_type node_type;
		typedef typename ft::iterator_traits<iterator_type>::pointer node_pointer;
		typedef typename ft::iterator_traits<iterator_type>::reference node_reference;
		typedef typename ft::iterator_traits<iterator_type>::iterator_category iterator_category;
	private:
		node_pointer _now;
	public:
		// constructor, destructor, operator=
		map_iterator(): _now(NULL) { }
		map_iterator(node_pointer now): _now(now) { }
		map_iterator(const map_iterator& copy): _now(copy._now) { }
		~map_iterator() { }

		map_iterator& operator=(const map_iterator& origin) {
			if (this != &origin)
				_now = origin._now;
			return *this;
		}

		// element access
		node_pointer base() const {
			return _now;
		}
		pointer operator->() const {
			return &_now->data;
		}
		reference operator*() const {
			return _now->data;
		}
		// increment, decrement
		map_iterator& operator++() {
			_now = ft::getNextNode(_now);
			return *this;
		}
		map_iterator operator++(int) {
			map_iterator tmp(*this);
			++(*this);
			return tmp;
		}
		map_iterator& operator--() {
			_now = ft::getPrevNode(_now);
			return *this;
		}
		map_iterator operator--(int) {
			map_iterator tmp(*this);
			--(*this);
			return tmp;
		}
		// relational operator
		template<typename T>
		bool operator==(const map_iterator<T, node_type>& rhs) const {
			return _now == rhs.base();
		}
		template<typename T>
		bool operator!=(const map_iterator<T, node_type>& rhs) const {
			return !(*this == rhs);
		}
		// const type overload
		operator map_iterator<const value_type, node_type>() const {
			return map_iterator<const value_type, node_type>(_now);
		}
		// non-member function
		friend bool operator==(const map_iterator& lhs, const map_iterator& rhs) {
			return lhs.base() == rhs.base();
		}
		friend bool operator!=(const map_iterator& lhs, const map_iterator& rhs) {
			return !(lhs == rhs);
		}
	};

	template<typename Key, typename Value, typename Comp, typename Allocator>
	class AVLtree {
	public:
		typedef Key key_type;
		typedef Value mapped_type;
		typedef ft::pair<const key_type, mapped_type> value_type;
		typedef Comp compare_type;

		typedef Node<value_type> node_type;
		typedef node_type* node_pointer;
		typedef map_iterator<value_type, node_type> iterator;
		typedef map_iterator<const value_type, node_type> const_iterator;

		typedef Allocator allocator_type;
		typedef typename allocator_type::template rebind<node_type>::other node_allocator;
		typedef size_t size_type;
		typedef ptrdiff_t difference_type;
	private:
		node_pointer _begin;
		node_pointer _end;
		compare_type _comp;
		node_allocator _alloc;
		size_type _size;
	public:
		// constructor, destructor, operator=
		AVLtree(const compare_type& comp, const allocator_type& alloc): _comp(comp), _alloc(alloc), _size(size_type()) {
			_end = makeNode(value_type());
			_begin = _end;
		}
		AVLtree(const AVLtree& copy): _comp(copy._comp), _alloc(copy._alloc), _size(size_type()) {
			_end = makeNode(value_type());
			_begin = _end;
			insert(copy.begin(), copy.end());
		}
		~AVLtree() {
			destructNodeAll(_end);
		}
		AVLtree operator=(const AVLtree& origin) {
			if (this != &origin) {
				AVLtree tmp(origin);
				swap(tmp);
			}
			return *this;
		}
		// for tree
		// iterator
		iterator begin() {
			return iterator(_begin);
		}
		const_iterator begin() const {
			return const_iterator(_begin);
		}
		iterator end() {
			return iterator(_end);
		}
		const_iterator end() const {
			return const_iterator(_end);
		}
		// capacity
		size_type size() const {
			return _size;
		}
		size_type max_size() const {
			return _alloc.max_size();
		}
		bool empty() const {
			return _size == 0;
		}
		// modifier
		ft::pair<iterator, bool> insert(const value_type &value) {
			node_pointer tmp = searchNode(_end->left, value.first);
			if (tmp != end())
				return ft::make_pair(iterator(tmp), false);
			return ft::make_pair(iterator(insertNode(_end->left, _end, value)), true);
		}
		iterator insert(iterator position, const value_type &value) {
			(void)position;
			return insert(value).first;
		}
		template<typename InputIterator>
		void insert(InputIterator first, InputIterator last) {
			for (; first != last; ++first) {
				insert(*first);
			}
		}
		iterator erase(iterator position) {
			if (_size == 0)
				return iterator();
			iterator tmp(position);
			++tmp;
			if (position == begin())
				_begin = tmp.base();
			--_size;
			node_pointer node = deleteNode(position.base());
			while (node != NULL && node->parent != _end) {
				node = node->parent;
				node = balanceFix(node);
			}
			destructNode(position.base());
			return tmp;
		}
		template<typename U>
		size_type erase(const U& value) {
			iterator it(searchNode(_end->left, value));
			if (it == end())
				return 0;
			if (it == begin()) {
				iterator tmp(it);
				++tmp;
				_begin = tmp.base();
			}
			erase(it);
			return 1;
		}
		void erase(iterator first, iterator last) {
			for (; first != last; )
				first = erase(first);
		}
		void swap(AVLtree& tree) {
			ft::swap(_begin, tree._begin);
			ft::swap(_end, tree._end);
			ft::swap(_comp, tree._comp);
			ft::swap(_alloc, tree._alloc);
			ft::swap(_size, tree._size);
		}
		void clear() {
			AVLtree tmp(_comp, _alloc);
			swap(tmp);
		}
		// lookup operator
		iterator find(const key_type &key) {
			return iterator(searchNode(_end->left, key));
		}
		const_iterator find(const key_type &key) const {
			return const_iterator(searchNode(_end->left, key));
		}
		iterator lower_bound(const key_type &key) {
			return iterator(lowerboundNode(key));
		}
		const_iterator lower_bound(const key_type &key) const {
			return const_iterator(lowerboundNode(key));
		}
		iterator upper_bound(const key_type &key) {
			return iterator(upperboundNode(key));
		}
		const_iterator upper_bound(const key_type &key) const {
			return const_iterator(upperboundNode(key));
		}
		pair<iterator, iterator> equal_range(const key_type &key) {
			node_pointer node = getRoot();
			node_pointer tmp = _end;

			while (node != NULL) {
				if (_comp(key, node->data)) {
					tmp = node;
					node = node->left;
				}
				else if (_comp(node->data, key))
					node = node->right;
				else {
					if (node->right != NULL)
						tmp = minNode(node->right);
					return ft::make_pair(iterator(node), iterator(tmp));
				}
			}
			return ft::make_pair(iterator(tmp), iterator(tmp));
		}
		pair<const_iterator, const_iterator> equal_range(const key_type &key) const {
			node_pointer node = getRoot();
			node_pointer tmp = _end;

			while (node != NULL) {
				if (_comp(key, node->data)) {
					tmp = node;
					node = node->left;
				}
				else if (_comp(node->data, key))
					node = node->right;
				else {
					if (node->right != NULL)
						tmp = minNode(node->right);
					return ft::make_pair(const_iterator(node), const_iterator(tmp));
				}
			}
			return ft::make_pair(const_iterator(tmp), const_iterator(tmp));
		}
		allocator_type get_allocator() const {
			return _alloc;
		}
		
		// for node
		node_pointer getRoot() const {
			return _end->left;
		}
		void setRoot(const node_pointer node) {
			node->parent = _end;
			_end->left = node;
		}
		node_pointer makeNode(const value_type &value) {
			node_pointer node = _alloc.allocate(1);
			_alloc.construct(node, value);
			// 따로 설정 안 해줘도 생성자 불러오는 건가?
			return node;
		}
		void destructNode(node_pointer node) {
			_alloc.destroy(node);
			_alloc.deallocate(node, 1);
		}
		void destructNodeAll(node_pointer node) {
			if (node == NULL)
				return ;
			destructNodeAll(node->left);
			destructNodeAll(node->right);
			destructNode(node);
		}

		// node functions
		node_pointer LL(node_pointer node) {
			node_pointer child = node->left;

			node->left = child->right;
			if (child->right != NULL)
				child->right->parent = node;
			child->right = node;
			child->parent = node->parent;
			if (isLeftChild(node))
				node->parent->left = child;
			else
				node->parent->right = child;
			node->parent = child;
			
			return child;
		}
		node_pointer RR(node_pointer node) {
			node_pointer child = node->right;

			node->right = child->left;
			if (child->left != NULL)
				child->left->parent = node;
			child->left = node;
			child->parent = node->parent;
			if (isLeftChild(node))
				node->parent->left = child;
			else
				node->parent->right = child;
			node->parent = child;

			return child;
		}
		node_pointer LR(node_pointer node) {
			node->left = RR(node->left);
			return LL(node);
		}
		node_pointer RL(node_pointer node) {
			node->right = LL(node->right);
			return RR(node);
		}
		node_pointer balanceFix(node_pointer node) {
			if (node == NULL)
				return NULL;
			int factor = calculateBF(node);
			if (factor > 1) {
				factor = calculateBF(node->left);
				if (factor > 0)
					node = LL(node);
				else
					node = LR(node);
			}
			else if (factor < -1) {
				factor = calculateBF(node->right);
				if (factor < 0)
					node = RR(node);
				else
					node = RL(node);
			}
			return node;
		}
		node_pointer insertNode(node_pointer node, node_pointer parent, const value_type &data) {
			while (node != NULL) {
				parent = node;
				if (_comp(data, node->data))
					node = node->left;
				else if (_comp(node->data, data))
					node = node->right;
			}
			node = makeNode(data);
			if (parent == _end)
				setRoot(node);
			else if (_comp(data, parent->data))
				parent->left = node;
			else
				parent->right = node;
			node->parent = parent;
			node_pointer tmp = node;

			while (node != NULL && node->parent != _end) {
				node_pointer tmp = node->parent;
				node = node->parent;
				node = balanceFix(node);
				if (node != tmp)
					break;
			}
			insertNodeUpdate(tmp);
			return tmp;
		}
		void insertNodeUpdate(const node_pointer &node) {
			if (_begin == _end || _comp(node->data, _begin->data))
				_begin = node;
			++_size;
		}
		node_pointer getMinNode(node_pointer node, node_pointer parent) {
			while (node->left != NULL)
				node = node->left;
			if (node->parent != NULL) {
				if (parent != node->parent)
					node->parent->left = node->right;
				else
					node->parent->right = node->right;
				if (node->right != NULL)
					node->right->parent = node->parent;
			}
			return node;
		}
		node_pointer deleteNode(node_pointer node) {
			if (node == NULL) 
				return NULL;
			if (node->left == NULL && node->right == NULL) {
				if (isLeftChild(node))
					node->parent->left = NULL;
				else
					node->parent->right = NULL;
				node = NULL;
			}
			else if (node->left != NULL && node->right == NULL) {
				node->left->parent = node->parent;
				if (isLeftChild(node))
					node->parent->left = node->left;
				else
					node->parent->right = node->left;
				node = node->left;
			}
			else if (node->left == NULL && node->right != NULL) {
				node->right->parent = node->parent;
				if (isLeftChild(node))
					node->parent->left = node->right;
				else
					node->parent->right = node->right;
				node = node->right;
			}
			else {
				node_pointer deleteN = node;
				node_pointer minN = getMinNode(node->right, deleteN);
				minN->parent = node->parent;
				if (isLeftChild(node))
					node->parent->left = minN;
				else
					node->parent->right = minN;
				minN->left = deleteN->left;
				if (deleteN->left != NULL)
					deleteN->left->parent = minN;
				minN->right = deleteN->right;
				if (deleteN->right != NULL)
					deleteN->right->parent = minN;
				node = minN;
			}
			return node;
		}
		node_pointer searchNode(node_pointer node, const key_type &key) const {
			while (node != NULL && key != node->data.first) {
				if (_comp(key, node->data))
					node = node->left;
				else
					node = node->right;
			}
			return node == NULL ? _end : node;
		}
		// for tree function
		node_pointer lowerboundNode(const key_type& key) const {
			node_pointer node = getRoot();
			node_pointer tmp = _end;

			while (node != NULL) {
				if (!_comp(node->data, key)) {
					tmp = node;
					node = node->left;
				}
				else
					node = node->right;
			}
			return tmp;
		}
		node_pointer upperboundNode(const key_type& key) const {
			node_pointer node = getRoot();
			node_pointer tmp = _end;

			while (node != NULL) {
				if (_comp(key, node->data)) {
					tmp = node;
					node = node->left;
				}
				else
					node = node->right;
			}
			return tmp;
		}
		void printHelper(node_pointer root, std::string indent, bool last)
		{
			if (root != NULL)
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
				std::cout << "(" << root->data.first << ", " << root->data.second << ")" << std::endl;
				printHelper(root->left, indent, false);
				printHelper(root->right, indent, true);
			}
		}
		void printTree()
		{
			if (_end->left)
				printHelper(_end->left, "", true);
		}
	
	
	};
}



#endif