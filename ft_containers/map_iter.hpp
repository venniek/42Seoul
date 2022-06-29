#ifndef __MAP_ITER_HPP__
# define __MAP_ITER_HPP__

# include "map_rbtree.hpp"
# include "pair.hpp"
# include "utils.hpp"

namespace ft
{
	template <typename T, typename Iter>
	class mapIter
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
		mapIter(): _now(ft::nil), _nil(ft::nil) { }
		mapIter(node_pointer now, node_pointer nil): _now(now), _nil(nil) { }
		mapIter(const mapIter& copy): _now(copy._now), _nil(copy._nil) { }
		~mapIter() { }

		mapIter& operator=(const mapIter& origin)
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
		mapIter& operator++()
		{
			_now = successor(_now, _nil);
			return *this;
		}
		mapIter& operator--()
		{
			_now = predecessor(_now, _nil);
			return *this;
		}
		mapIter& operator++(int)
		{
			mapIter tmp(*this);
			++(*this);
			return tmp;
		}
		mapIter& operator--(int)
		{
			mapIter tmp(*this);
			--(*this);
			return tmp;
		}

		// relational operators
		template<typename T>
		bool operator==(const mapIter& rhs) const
		{
			return _now == rhs.base();
		}
		template<typename T>
		bool operator!=(const mapIter& rhs) const
		{
			return !(*this == rhs);
		}
		template<typename T>
		bool operator==(const mapIter& rhs) const
		{
			return _now == rhs.base();
		}
	};

	// non member function
	template<typename T, typename Iter>
	bool operator==(const mapIter<T, Iter>& x, const mapIter<T, Iter>& y)
	{
		return x.base() == y.base();
	}
	template<typename T, typename Iter>
	bool operator!=(const mapIter<T, Iter>& x, const mapIter<T, Iter>& y)
	{
		return !(x == y);
	}
	
}



#endif