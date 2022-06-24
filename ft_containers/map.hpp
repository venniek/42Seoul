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
			std::cout << "map constructor iterator range" << std::endl;
			tree_type tmp;
			_tree = _allocTree.allocate(1);
			*_tree = tmp;
			insert(first, last);
		}
		// copy constructor
		map(const map &x) : _alloc(x._alloc), k_comp(x.key_comp), _size(0)
		{
			std::cout << "map copy constructor" << std::endl;
			tree_type tmp;
			_tree = _allocTree.allocate(1);
			*_tree = tmp;
			*this = x;
		}
		// assignation operator
		map &operator=(const map &x)
		{
			std::cout << "map assignation operator" << std::endl;
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
			std::cout << "map desturctor" << std::endl;
			clear();
			_allocTree.deallocate(_tree, 1);
		}
		// ----- constructor, destructor, operator=

		// ----- iterators
		iterator begin()
		{
			std::cout << "map begin with iterator" << std::endl;
			return iterator(_tree, _tree->minimum(_tree->root));
		}
		const_iterator begin() const
		{
			std::cout << "map begin with const_iterator" << std::endl;
			return const_iterator(_tree, _tree->minimum(_tree->root));
		}
		iterator end()
		{
			std::cout << "map end with iterator" << std::endl;
			return iterator(_tree, NULL);
		}
		const_iterator end() const
		{
			std::cout << "map end with const_iterator" << std::endl;
			return const_iterator(_tree, NULL);
		}
		// reverse_iterator rbegin() { return reverse_iterator(this->end()); }
		// const_reverse_iterator rbegin() const { return const_reverse_iterator(this->end()); };
		// reverse_iterator rend() { return reverse_iterator(this->begin()); };
		// const_reverse_iterator rend() const { return const_reverse_iterator(this->begin()); };

		// ------ capacity
		bool empty() const
		{
			std::cout << "map empty" << std::endl;
			return _size == 0;
		}
		size_type size() const
		{
			std::cout << "map size" << std::endl;
			return _size;
		}
		size_type max_size() const
		{
			std::cout << "map max_size" << std::endl;
			return _allocTree.max_size();
		}
		// ------ capacity

		// ----- element access
		mapped_type &operator[](const key_type &k)
		{
			std::cout << "map operator[]" << std::endl;
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
			std::cout << "map insert with value" << std::endl;
			std::cout << "💀" << std::endl;
			ft::pair<iterator, bool> ret;
			std::cout << "💀" << std::endl;
			// iterator it = retit;
			ret.second = true;
			if (_tree->searchNode(val.first) != _tree->nil)
				ret.second = false;
			else
			{
				_tree->insertNode(val);
				++_size;
			}
			
			std::cout << "2" << std::endl;
			//std::cout<< "type : " <<typeof(ret) << std::endl;
			ret.first = this->find(val.first);		// 여기가 문제 ret.first 타입이 rbtree 인것 같음 
			std::cout << "3" << std::endl;
			return ret;
		}
		// insert2 hint
		iterator insert(iterator position, const value_type &val)
		{
			std::cout << "map insert with position, val" << std::endl;
			static_cast<void>(position);
			this->insert(val);
			return this->find(val.first);
		}
		// insert3 range
		template <typename InputIterator>
		void insert(InputIterator first, InputIterator last)
		{
			std::cout << "map insert with iterator range" << std::endl;
			for (; first < last; ++first)
				this->insert(*first);
		}
		// erase1 position
		void erase(iterator position)
		{
			std::cout << "map erase with position" << std::endl;
			this->erase((*position).first);
		}
		// erase2 single
		size_type erase(const key_type &k)
		{
			std::cout << "map erase with key" << std::endl;
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
			std::cout << "map erase with iterator range" << std::endl;
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
			std::cout << "map swap" << std::endl;
			tree_ptr tmp = x._tree;
			size_type tmp_size = x._size;

			x._tree = this->_tree;
			x._size = this->_size;

			this->_tree = tmp;
			this->_size = tmp_size;
		}
		void clear()
		{
			std::cout << "map clear1" << std::endl;
			_tree->clear();
			_size = 0;
		}
		// ----- observers
		key_compare key_comp() const
		{
			std::cout << "map key_comp" << std::endl;
			return key_compare();
		}
		value_compare value_comp() const
		{
			std::cout << "map value_comp" << std::endl;
			return value_compare();
		}

		// ----- operations
		iterator find(const key_type &k)
		{
			std::cout << "map find with iterator" << std::endl;
			std::cout << "tree root : " <<_tree->root << std::endl;
			iterator it(_tree, _tree->searchNode(k));
			std::cout << "map iterator finished" << std::endl;
			return it;
		}
		const_iterator find(const key_type &k) const
		{
			std::cout << "map find with const_iterator" << std::endl;
			
			return const_iterator(_tree, _tree->searchNode(k));
		}
		size_type count(const key_type &k) const
		{
			std::cout << "map count" << std::endl;
			if (this->find(k) != this->end())
				return 1;
			return 0;
		}
		iterator lower_bound(const key_type &k)
		{
			std::cout << "map lower_bound with iterator" << std::endl;
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
			std::cout << "map lower_bound with const_iterator" << std::endl;
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
			std::cout << "map upper_bound with iterator" << std::endl;
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
			std::cout << "map upper_bound with const_iterator" << std::endl;
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
			std::cout << "map equal_range" << std::endl;
			return make_pair<iterator, iterator>(this->lower_bound(k), this->upper_bound(k));
		}
		ft::pair<const_iterator, const_iterator> equal_range(const key_type &k) const
		{
			std::cout << "map equal_range" << std::endl;
			return make_pair<const_iterator, const_iterator>(this->lower_bound(k), this->upper_bound(k));
		}
		// ----- allocator
		allocator_type get_allocator() const
		{
			std::cout << "map get_allocator" << std::endl;
			return _alloc;
		}

		
	};

	// ----- non-member functions
	template <typename Key, typename T, typename Compare, typename Alloc>
	bool operator==(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs) {
		std::cout << "map operator==" << std::endl;
		if (lhs.size() != rhs.size())
			return false;
		for (size_t i = 0; i < lhs.size(); ++i) {
			if (lhs[i] != rhs[i])
				return false;
		}
		return true;
	}
	template <typename Key, typename T, typename Compare, typename Alloc>
	bool operator!=(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs) {
		std::cout << "map operator!=" << std::endl;
		return !(lhs == rhs);
	}
	template <typename Key, typename T, typename Compare, typename Alloc>
	bool operator<(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs) {
		std::cout << "map operator<" << std::endl;
		return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}
	template <typename Key, typename T, typename Compare, typename Alloc>
	bool operator<=(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs) {
		std::cout << "map operator<=" << std::endl;
		return !(lhs > rhs);
	}
	template <typename Key, typename T, typename Compare, typename Alloc>
	bool operator>(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs) {
		std::cout << "map operator>" << std::endl;
		return (rhs < lhs);
	}
	template <typename Key, typename T, typename Compare, typename Alloc>
	bool operator>=(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs) {
		std::cout << "map operator>=" << std::endl;
		return !(lhs < rhs);
	}
	template <typename Key, typename T, typename Compare, typename Alloc>
	void swap(ft::map<Key, T, Compare, Alloc> & x, ft::map<Key, T, Compare, Alloc> & y) {   
		std::cout << "map swap non-member" << std::endl;
		x.swap(y);
	}
} // namespace ft

#endif