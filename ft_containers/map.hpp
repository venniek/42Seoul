#ifndef __MAP_HPP__
#define __MAP_HPP__

# include <iostream>
# include <memory>
# include <map>
# include "./utils.hpp"
// # include "./map_iterator.hpp"
# include "./reverse_iterator.hpp"
# include "./avltree.hpp"
# include "./pair.hpp"

namespace ft {
	template<typename Key, typename Mapped, typename Compare = ft::less<Key>, typename Alloc = std::allocator<ft::pair<const Key, Mapped> > >
	class map {
	public:
		typedef Key key_type;
		typedef Mapped mapped_type;
		typedef ft::pair<const key_type, mapped_type> value_type;
		typedef Compare key_compare;

		typedef Alloc allocator_type;
		typedef value_type* pointer;
		typedef const value_type* const_pointer;
		typedef value_type& reference;
		typedef const value_type& const_reference;
		typedef size_t size_type;
		typedef ptrdiff_t difference_type;
		
		class value_compare: binary_function<value_type, value_type, bool> {
		friend class map;
		protected:
			key_compare comp;
		public:
			value_compare(key_compare c): comp(c) { }
			bool operator()(const value_type &x, const value_type &y) const {
				return comp(x.first, y.first);
			}
			bool operator()(const value_type &x, const key_type &y) const {
				return comp(x.first, y);
			}
			bool operator()(const key_type &x, const value_type &y) const {
				return comp(x, y.first);
			}
		};

		typedef typename ft::AVLtree<key_type, mapped_type, value_compare, allocator_type> tree_type;
		typedef typename tree_type::iterator iterator;
		typedef typename tree_type::const_iterator const_iterator;
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
		
	private:
		key_compare _k_comp;
		value_compare _v_comp;
		tree_type _tree;

	public:
		// constructor, destructor, operator=
		explicit map(const key_compare &comp = key_compare(), const allocator_type& alloc = allocator_type()): _k_comp(comp), _v_comp(comp), _tree(_v_comp, alloc) { }
		template<typename InputIterator>
		map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type &alloc = allocator_type()): _k_comp(comp), _v_comp(comp), _tree(_v_comp, alloc) {
			insert(first, last);
		}
		map(const map& copy): _k_comp(copy._k_comp), _v_comp(copy._v_comp), _tree(copy._tree) { }
		~map() { }
		map& operator=(const map& origin) {
			if (this != &origin) {
				_k_comp = origin._k_comp;
				_v_comp = origin._v_comp;
				_tree = origin._tree;
			}
			return *this;
		}

		// iterator
		iterator begin() {
			return _tree.begin();
		}
		const_iterator begin() const {
			return _tree.begin();
		}
		iterator end() {
			return _tree.end();
		}
		const_iterator end() const {
			return _tree.end();
		}
		reverse_iterator rbegin() {
			return reverse_iterator(end());
		}
		const_reverse_iterator rbegin() const {
			return reverse_iterator(end());
		}
		reverse_iterator rend() {
			return reverse_iterator(begin());
		}
		const_reverse_iterator rend() const {
			return reverse_iterator(begin());
		}

		// capacity
		bool empty() const {
			return _tree.empty();
		}
		size_type size() const {
			return _tree.size();
		}
		size_type max_size() const {
			return _tree.max_size();
		}

		// element access
		mapped_type &operator[](const key_type& key) {
			pair<iterator, bool> tmp = insert(ft::make_pair(key, mapped_type()));
			return tmp.first->second;
		}
		mapped_type& at(const key_type& key) {
			iterator it = find(key);
			if (it == end())
				throw std::out_of_range("index is out of range");
			return it->second;
		}
		const mapped_type& at(const key_type& key) const {
			const_iterator it = find(key);
			if (it == end())
				throw std::out_of_range("index is out of range");
			return it->second;
		}
		// modifier
		ft::pair<iterator, bool> insert(const value_type &value) {
			return _tree.insert(value);
		}
		iterator insert(iterator position, const value_type& value) {
			return _tree.insert(position, value);
		}
		template<typename InputIterator>
		void insert(InputIterator first, InputIterator last) {
			_tree.insert(first, last);
		}
		void erase(iterator position) {
			_tree.erase(position);
		}
		size_type erase(const key_type& key) {
			return _tree.erase(key);
		}
		void erase(iterator first, iterator last) {
			_tree.erase(first, last);
		}
		void swap(map& m) {
			_tree.swap(m._tree);
		}
		void clear() {
			_tree.clear();
		}

		// observer
		key_compare key_comp() const {
			return _k_comp;
		}
		value_compare value_comp() const {
			return value_compare(_k_comp);
		}
		// lookup
		iterator find(const key_type &key) {
			return _tree.find(key);
		}
		const_iterator find(const key_type &key) const {
			return _tree.find(key);
		}
		size_type count(const key_type &key) const {
			return !(find(key) == end());
		}
		iterator lower_bound(const key_type & key) {
			return _tree.lower_bound(key);
		}
		const_iterator lower_bound(const key_type & key) const {
			return _tree.lower_bound(key);
		}
		iterator upper_bound(const key_type & key) {
			return _tree.upper_bound(key);
		}
		const_iterator upper_bound(const key_type & key) const {
			return _tree.upper_bound(key);
		}
		pair<iterator, iterator> equal_range(const key_type& key) {
			return _tree.equal_range(key);
		}
		pair<const_iterator, const_iterator> equal_range(const key_type& key) const {
			return _tree.equal_range(key);
		}
		allocator_type get_allocator() const {
			return _tree.get_allocator();
		}
	};

	// non-member function
	template <typename key, typename mapped, class Compare, class Allocator>
	bool operator==(const ft::map<key, mapped, Compare, Allocator>& x, const ft::map<key, mapped, Compare, Allocator>& y) {
		return x.size() == y.size() && ft::equal(x.begin(), x.end(), y.begin());
	}

	template <typename key, typename mapped, class Compare, class Allocator>
	bool operator!=(const ft::map<key, mapped, Compare, Allocator>& x, const ft::map<key, mapped, Compare, Allocator>& y) {
		return !(x == y);
	}

	template <typename key, typename mapped, class Compare, class Allocator>
	bool operator<(const ft::map<key, mapped, Compare, Allocator>& x, const ft::map<key, mapped, Compare, Allocator>& y) {
		return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
	}

	template <typename key, typename mapped, class Compare, class Allocator>
	bool operator<=(const ft::map<key, mapped, Compare, Allocator>& x, const ft::map<key, mapped, Compare, Allocator>& y) {
		return !(y < x);
	}

	template <typename key, typename mapped, class Compare, class Allocator>
	bool operator>(const ft::map<key, mapped, Compare, Allocator>& x, const ft::map<key, mapped, Compare, Allocator>& y) {
		return y < x;
	}

	template <typename key, typename mapped, class Compare, class Allocator>
	bool operator>=(const ft::map<key, mapped, Compare, Allocator>& x, const ft::map<key, mapped, Compare, Allocator>& y) {
		return !(x < y);
	}

	/* non member function for util */
	template <typename key, typename mapped, class Compare, class Allocator>
	void swap(ft::map<key, mapped, Compare, Allocator>& x, ft::map<key, mapped, Compare, Allocator>& y) {
		x.swap(y);
	}
}




#endif