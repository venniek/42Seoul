#ifndef __MAP_ITER_HPP__
# define __MAP_ITER_HPP__

# include "map_rbtree.hpp"
# include "iterator_traits.hpp"
# include "reverse_iterator.hpp"
# include "pair.hpp"
# include "utils.hpp"

namespace ft
{
	template <typename T, typename Iter>
	class treeIter
	{
	public:
		typedef T value_type;
		typedef value_type* pointer;
		typedef value_type& reference;
		typedef Iter* iterator_type;
		typedef typename ft::iterator_traits<iterator_type>::difference_type difference_type;
		typedef typename ft::iterator_traits<iterator_type>::value_type node_type;
		typedef typename ft::iterator_traits<iterator_type>::pointer node_pointer;
		typedef typename ft::iterator_traits<iterator_type>::reference node_reference;
		typedef typename ft::iterator_traits<iterator_type>::iterator_category iterator_category;
	private:
		node_pointer _now;
		node_pointer _nil;

	public:
		treeIter(): _now(ft::nil), _nil(ft::nil) { }
		treeIter(node_pointer now, node_pointer nil): _now(now), _nil(nil) { }
		treeIter(const treeIter& copy): _now(copy._now), _nil(copy._nil) { }
		~treeIter() { }

		treeIter& operator=(const treeIter& origin)
		{
			if (this != &origin)
			{
				_now = origin._now;
				_nil = origin._nil;
			}
			return *this;
		}
		// element access
		node_pointer base() const
		{
			return _now;
		}
		pointer operator->() const
		{
			return &(_now->data);
		}
		reference operator*() const
		{
			return _now->data;
		}
		// increment & decrement
		treeIter& operator++()
		{
			_now = successor(_now, _nil);
			return *this;
		}
		treeIter& operator--()
		{
			_now = predecessor(_now, _nil);
			return *this;
		}
		treeIter& operator++(int)
		{
			treeIter tmp(*this);
			++(*this);
			return tmp;
		}
		treeIter& operator--(int)
		{
			treeIter tmp(*this);
			--(*this);
			return tmp;
		}

		// relational operators
		template<typename U>
		bool operator==(const treeIter<U, node_type>& rhs) const
		{
			return _now == rhs.base();
		}
		template<typename U>
		bool operator!=(const treeIter<U, node_type>& rhs) const
		{
			return !(*this == rhs);
		}
		operator treeIter<const value_type, node_type>() const
		{
			return treeIter<const value_type, node_type>(_now, _nil);
		}
	};

	// non member function
	template<typename T, typename Iter>
	bool operator==(const treeIter<T, Iter>& x, const treeIter<T, Iter>& y)
	{
		return x.base() == y.base();
	}
	template<typename T, typename Iter>
	bool operator!=(const treeIter<T, Iter>& x, const treeIter<T, Iter>& y)
	{
		return !(x == y);
	}
	
}

#endif