#ifndef __MAP_HPP__
# define __MAP_HPP__

# include <iostream>
# include "pair.hpp"
# include "map_rbtree.hpp"
# include "map_iter.hpp"
# include "utils.hpp"
#include <typeinfo> 

namespace ft
{
	template <typename Key,                                           // map::key_type
			typename T,                                             // map::mapped_type
			typename Compare = less<Key>,                           // map::key_compare
			typename Alloc = std::allocator<ft::pair<const Key, T> > // map::allocator_type
			>
	class map
	{
	public:
		// ----- member types
		typedef Key key_type;
		typedef T mapped_type;
		typedef ft::pair<key_type, mapped_type> value_type;
		typedef Compare key_compare;

		typedef Alloc allocator_type;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
        class value_compare : binary_function<value_type, value_type, bool>
        {
            friend class map;
        protected:
            key_compare comp;
            value_compare(key_compare c) : comp(c) {}
        public:
            typedef value_type first_argument_type;
            typedef value_type second_argument_type;
            typedef bool result_type;
            result_type operator() (const first_argument_type& x, const second_argument_type& y) const
            {
                return comp(x.first, y.first);
            }
        };
		
		typedef ft::Rbtree<key_type, mapped_type, key_compare, allocator_type> tree_type;
		typedef tree_type::iterator iterator;
		typedef tree_type::const_iterator const_iterator;
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

		typedef ptrdiff_t difference_type;
		typedef size_t size_type;

	private:
		allocator_type _alloc;
		key_compare k_comp;
		value_compare v_comp;
		tree_type _tree;

	public:
		// ----- constructor, destructor, operator=
		// empty constructor
		explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
			: _alloc(alloc), k_comp(comp), v_comp(comp), _tree(v_comp, _alloc) { }
		// range constructor 
		template <typename InputIterator>
		map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
					: _alloc(alloc), k_comp(comp), v_comp(comp), _tree(v_comp, _alloc)
		{
			insert(first, last);
		}
		// copy constructor
		map(const map &ori) : _alloc(ori._alloc), k_comp(ori.key_comp), v_comp(ori.v_comp), _tree(ori._tree) { }
		// assignation operator
		map &operator=(const map &ori)
		{
			if (this != &ori)
			{
				k_comp = ori.k_comp;
				v_comp = ori.v_comp;
				_tree = ori.tree;
			}
			return *this;
		}
		// destructor
		~map() { }

		// ----- iterator
		iterator begin()
		{
			return _tree.begin();
		}
		const_iterator begin() const
		{
			return _tree.begin();
		}
		iterator end()
		{
			return _tree.end();
		}
		const_iterator end() const
		{
			return _tree.end();
		}
		reverse_iterator rbegin(void)
		{
			return reverse_iterator(end());
		}
		const_reverse_iterator rbegin(void) const
		{
			return reverse_iterator(end());
		}
		reverse_iterator rend(void)
		{
			return reverse_iterator(begin());
		}
		const_reverse_iterator rend(void) const
		{
			return reverse_iterator(begin());
		}

		// ----- capacity
		bool empty() const
		{
			return _tree.empty();
		}
		size_type size() const
		{
			return _tree.size();
		}
		size_type max_size() const
		{
			return _tree->max_size();
		}
		
		// ----- element access
		mapped_type &operator[](const key_type *key)
		{
			ft::pair<iterator, bool> ret = insert(ft::make_pair(key, mapped_type()));
			return ret.first->second;
		}
		mapped_type &at(const key_type &key)
		{
			iterator it = find(key);
			if (it == end())
				throw std::out_of_range("index is out of range");
			return it->second;
		}
		const mapped_type &at(const key_type& key) const
		{
			const_iterator it = find(key);
			if (it == end())
				throw std::out_of_range("index is out of range");
			return it->second;
		}
		
		// ----- modifier
		ft::pair<iterator, bool> insert(const value_type &value)
		{
			return _tree.insert(value);
		}
		iterator insert(iterator position, const value_type &value)
		{
			return _tree.insert(position, value);
		}
		template<typename InputIterator>
		void insert(InputIterator first, InputIterator last)
		{
			_tree.insert(first, last);
		}
		void erase(iterator position)
		{
			_tree.erase(position);
		}
		size_type erase(const key_type& key)
		{
			return _tree.erase(key);
		}
		void erase(iterator first, iterator last)
		{
			_tree.erase(first, last);
		}
		void swap(map& ori)
		{
			_tree.swap(ori._tree);
		}
		void clear()
		{
			_tree.clear();
		}

		// ----- observers
		key_compare key_comp() const
		{
			return k_comp;
		}
		value_compare value_comp() const
		{
			return v_comp;
		}

		// ----- lookup operation
		iterator find(const key_type& key)
		{
			return _tree.find(key);
		}
		const_iterator find(const key_type& key) const
		{
			return _tree.find(key);
		}
		size_type count(const key_type& key) const
		{
			return !(find(key) == end());
		}
		iterator lower_bound(const key_type& key)
		{
			return _tree.lower_bound(key);
		}
		const_iterator lower_bound(const key_type& key) const
		{
			return _tree.lower_bound(key);
		}
		iterator upper_bound(const key_type& key)
		{
			return _tree.upper_bound(key);
		}
		const_iterator upper_bound(const key_type& key) const
		{
			return _tree.upper_bound(key);
		}
		ft::pair<iterator, iterator> equal_range(const key_type& key)
		{
			return _tree.equal_range(key);
		}
		ft::pair<const_iterator, const_iterator> equal_range(const key_type& key) const
		{
			return _tree.equal_range(key);
		}

		// ----- allocator
		allocator_type get_allocator() const
		{
			return _alloc;
		}
	};

	// ----- non-member functions
	template <typename Key, typename T, typename Compare, typename Alloc>
	bool operator==(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs)
	{
		if (lhs.size() != rhs.size())
			return false;
		for (size_t i = 0; i < lhs.size(); ++i) {
			if (lhs[i] != rhs[i])
				return false;
		}
		return true;
	}
	template <typename Key, typename T, typename Compare, typename Alloc>
	bool operator!=(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs)
	{
		return !(lhs == rhs);
	}
	template <typename Key, typename T, typename Compare, typename Alloc>
	bool operator<(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs)
	{
		return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}
	template <typename Key, typename T, typename Compare, typename Alloc>
	bool operator<=(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs)
	{
		return !(lhs > rhs);
	}
	template <typename Key, typename T, typename Compare, typename Alloc>
	bool operator>(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs)
	{
		return (rhs < lhs);
	}
	template <typename Key, typename T, typename Compare, typename Alloc>
	bool operator>=(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs)
	{
		return !(lhs < rhs);
	}
	template <typename Key, typename T, typename Compare, typename Alloc>
	void swap(ft::map<Key, T, Compare, Alloc> & x, ft::map<Key, T, Compare, Alloc> & y)
	{
		x.swap(y);
	}
} // namespace ft

#endif