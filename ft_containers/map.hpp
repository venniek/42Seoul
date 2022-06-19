#ifndef __MAP_H__
#define __MAP_H__

#include <iostream>
#include "pair.hpp"
#include "map_rbtree.hpp"
#include "map_iter.hpp"

namespace ft
{

	template <typename T>
	struct less : binary_function<T, T, bool>
	{
		bool operator()(const T &x, const T &y) const { return x < y; }
	};

	template <typename Key,                                           // map::key_type
			typename T,                                             // map::mapped_type
			typename Compare = less<Key>,                           // map::key_compare
			typename Alloc = std::allocator<ft::pair<const Key, T>> // map::allocator_type
			>
	class map
	{
	public:
		// ----- member types
		typedef Key key_type;
		typedef T mapped_type;
		typedef ft::pair<const Key, T> value_type;
		typedef Compare key_compare;
		typedef value_compare value_comp; // 만들자
		typedef Alloc allocator_type;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;

		typedef ft::mapIter<value_type> iterator;
		typedef ft::mapIter<const value_type> const_iterator;
		typedef ft::reverse_iterator_tag<iterator> reverse_iterator;
		typedef ft::reverse_iterator_tag<const_iterator> const_reverse_iterator;
		typedef ptrdiff_t difference_type;
		typedef size_t size_type;

		typedef ft::Rbtree<value_type> node_type;
		typedef node_type *node_ptr;
	private:
		node_ptr _node;
		std::allocator<node_type> _allocNode;
		allocator_type _alloc;
		key_compare k_comp;
		size_type _size;

	public:
		// ----- constructor, destructor, operator=
		explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
					: _node(0), _alloc(alloc), k_comp(comp), _size(0)
		{
			this->_node = _allocNode.allocate(1);
			allocNode_construct(&_node);
		}
		template <typename InputIterator>
		map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
					: _node(0), _alloc(alloc), k_comp(comp), _size(0)
		{
			this->_node = _allocNode.allocate(1);
			allocNode_construct(&_node);
			insert(first, last);
		}
		map(const map &x) : _node(0), _alloc(x._alloc), k_comp(x.k_comp), _size(0)
		{
			this->_node = _allocNode.allocate(1);
			allocNode_construct(&_node);
			*this = x;
		}
		map &operator=(const map &x)
		{
			if (this != &x)
			{
				this->clear();
				iterator first = x.begin();
				iterator last = x.end();
				for (iterator first = x.begin(); first != last; first++)
				{

					_size++;
				}
			}
			return *this;
		}
		~map()
		{
			clear();
			_allocNode.deallocate(_node, 1);
		}
		// ----- constructor, destructor, operator=

		// ----- iterators
		iterator begin()
		{
			return _node->minimum();
		}
		const_iterator begin() const
		{

		}
		iterator end()
		{

		}
		const_iterator end() const
		{

		}
		reverse_iterator rbegin() { return reverse_iterator(end()); }
		const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); };
		reverse_iterator rend() { return reverse_iterator(begin()); };
		const_reverse_iterator rend() const { return const_reverse_iterator(begin()); };

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
			return _allocNode.max_size();
		}
		// ------ capacity

		// ----- element access
		mapped_type &operator[](const key_type &k)
		{
			if (!_node->searchNode(k))
				insert(k);
			return find(k)->second;
		}
		// ----- element access

		// ----- modifiers
		ft::pair<iterator, bool> insert(const value_type &val)
		{
			ft::pair<iterator, bool> ret;

			ret.second = 1;
			if (_node->searchNode(val.first))
				ret.second = 0;
			else
			{
				_node->insertNode(val);
				++_size;
			}
			ret.first = find(val.first);
		}
		iterator insert(iterator position, const value_type &val)
		{

		}
		template <typename InputIterator>
		void insert(InputIterator first, InputIterator last);
		void erase(iterator position);
		size_type erase(const key_type &k);
		void erase(iterator first, iterator last);
		void swap(map &x);
		void clear();

		// ----- observers
		key_compare key_comp() const;
		value_compare value_comp() const;

		// ----- operations
		iterator find(const key_type &k);
		const_iterator find(const key_type &k) const;
		size_type count(const key_type &k) const;
		iterator lower_bound(const key_type &k);
		const_iterator lower_bound(const key_type &k) const;
		iterator upper_bound(const key_type &k);
		const_iterator upper_bound(const key_type &k) const;
		ft::pair<const_iterator, const_iterator> equal_range(const key_type &k) const;
		ft::pair<iterator, iterator> equal_range(const key_type &k);

		// ----- allocator
		allocator_type get_allocator() const
		{
			return _alloc;
		}
	};
} // namespace ft

#endif