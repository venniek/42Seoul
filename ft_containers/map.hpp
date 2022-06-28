#ifndef __MAP_H__
# define __MAP_H__

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
		
		typedef ft::Rbtree<key_type, mapped_type, key_compare> tree_type;
		typedef tree_type *tree_ptr;
		typedef ptrdiff_t difference_type;
		typedef size_t size_type;

	private:
		tree_ptr _tree;
		std::allocator<tree_type> _allocTree;
		allocator_type _alloc;
		key_compare k_comp;
		size_type _size;
		
    public:
        typedef mapIter<key_type, mapped_type, key_compare> iterator;
		typedef mapConstIter<key_type, mapped_type, key_compare> const_iterator;
		// typedef mapReverseIter<key_type, mapped_type, key_compare> reverse_iterator;
		// typedef mapConstReverseIter<key_type, mapped_type, key_compare> const_reverse_iterator;

	public:
		// ----- constructor, destructor, operator=
		// empty constructor
		explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
					: _alloc(alloc), k_comp(comp), _size(0)
		{
			tree_type tmp;
			_tree = _allocTree.allocate(1);
			*_tree = tmp;
		}
		// range constructor 
		template <typename InputIterator>
		map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
					: _alloc(alloc), k_comp(comp), _size(0)
		{
			tree_type tmp;
			_tree = _allocTree.allocate(1);
			*_tree = tmp;
			insert(first, last);
		}
		// copy constructor
		map(const map &x) : _alloc(x._alloc), k_comp(x.key_comp), _size(0)
		{
			tree_type tmp;
			_tree = _allocTree.allocate(1);
			*_tree = tmp;
			*this = x;
		}
		// assignation operator
		map &operator=(const map &x)
		{
			if (this != &x)
			{
				this->clear();
				for (iterator first = x.begin(); first != x.end(); first++)
                    insert(*first);
			}
			return *this;
		}
		// destructor
		~map()
		{
			clear();
			_allocTree.deallocate(_tree, 1);
		}
		// ----- constructor, destructor, operator=

		// ----- iterators
		iterator begin()
		{
			return iterator(_tree, _tree->minimum(_tree->root));
		}
		const_iterator begin() const
		{
			return const_iterator(_tree, _tree->minimum(_tree->root));
		}
		iterator end()
		{
			return iterator(_tree, NULL);
		}
		const_iterator end() const
		{
			return const_iterator(_tree, NULL);
		}
		// reverse_iterator rbegin() { return reverse_iterator(this->end()); }
		// const_reverse_iterator rbegin() const { return const_reverse_iterator(this->end()); };
		// reverse_iterator rend() { return reverse_iterator(this->begin()); };
		// const_reverse_iterator rend() const { return const_reverse_iterator(this->begin()); };

		// ------ capacity
		bool empty() const
		{
			return _size == 0;
		}
		size_type size() const
		{
			return _size;
		}
		size_type max_size() const
		{
			return _allocTree.max_size();
		}
		// ------ capacity

		// ----- element access
		mapped_type &operator[](const key_type &k)
		{
			if (!_tree->searchNode(k))
			{
				value_type tmp = value_type();
				tmp.first = k;
				this->insert(tmp);
			}
			return this->find(k)->second;
		}
		// ----- element access

		// ----- modifiers
		// insert1 single element
		ft::pair<iterator, bool> insert(const value_type &val)
		{
			ft::pair<iterator, bool> ret;
			// iterator it = retit;
			ret.second = true;
			if (_tree->searchNode(val.first) != _tree->nil)
				ret.second = false;
			else
			{
				_tree->insertNode(val);
				++_size;
			}
			ret.first = this->find(val.first);		// 여기가 문제 ret.first 타입이 rbtree 인것 같음 
			return ret;
		}
		// insert2 hint
		iterator insert(iterator position, const value_type &val)
		{
			static_cast<void>(position);
			this->insert(val);
			return this->find(val.first);
		}
		// insert3 range
		template <typename InputIterator>
		void insert(InputIterator first, InputIterator last)
		{
			for (; first < last; ++first)
				this->insert(*first);
		}
		// erase1 position
		void erase(iterator position)
		{
			this->erase((*position).first);
		}
		// erase2 single
		size_type erase(const key_type &k)
		{
			iterator tmp = (iterator)find(k);

			if (tmp == this->end())
				return 0;
			_tree->deleteNode(tmp->first);
			--_size;
			return 1;
		}
		// erase3 range
		void erase(iterator first, iterator last)
		{
			while (first != last)
			{
				iterator next = first;
				++next;
				erase(first);
				first = next;
			}
		}
		void swap(map &x)
		{
			std::cout << "swap start!" << std::endl;
			tree_ptr tmp = x._tree;
			size_type tmp_size = x._size;
			std::cout << "after make tmps" << std::endl;

			x._tree = this->_tree;
			x._size = this->_size;
			std::cout << "x_tree, size = this->tree, size" << std::endl;

			this->_tree = tmp;
			this->_size = tmp_size;
			std::cout << "this->tree, size = tmp.tree, size" << std::endl;
		}
		void clear()
		{
			_tree->clear();
			_size = 0;
		}
		// ----- observers
		key_compare key_comp() const
		{
			return key_compare();
		}
		value_compare value_comp() const
		{
			return value_compare();
		}

		// ----- operations
		iterator find(const key_type &k)
		{
			iterator it(_tree, _tree->searchNode(k));
			return it;
		}
		const_iterator find(const key_type &k) const
		{
			
			return const_iterator(_tree, _tree->searchNode(k));
		}
		size_type count(const key_type &k) const
		{
			if (this->find(k) != this->end())
				return 1;
			return 0;
		}
		iterator lower_bound(const key_type &k)
		{
			iterator its = this->begin();
			iterator ite = this->end();

			while (its != ite)
			{
				if (!this->key_comp(its->first, k))
					break;
				++its;
			}
			return its;
		}
		const_iterator lower_bound(const key_type &k) const
		{
			const_iterator its = this->begin();
			const_iterator ite = this->end();

			while (its != ite)
			{
				if (!this->key_comp(its->first, k))
					break;
				++its;
			}
			return its;
		}
		iterator upper_bound(const key_type &k)
		{
			iterator its = this->begin();
			iterator ite = this->end();

			while (its != ite)
			{
				if (this->key_comp(k, its->first))
					break;
				++its;
			}
			return its;
		}
		const_iterator upper_bound(const key_type &k) const
		{
			const_iterator its = this->begin();
			const_iterator ite = this->end();

			while (its != ite)
			{
				if (this->key_comp(k, its->first))
					break;
				++its;
			}
			return its;
		}
		ft::pair<iterator, iterator> equal_range(const key_type &k)
		{
			return make_pair<iterator, iterator>(this->lower_bound(k), this->upper_bound(k));
		}
		ft::pair<const_iterator, const_iterator> equal_range(const key_type &k) const
		{
			return make_pair<const_iterator, const_iterator>(this->lower_bound(k), this->upper_bound(k));
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