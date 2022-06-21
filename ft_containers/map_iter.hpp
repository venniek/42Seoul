#ifndef __MAP_ITER_HPP__
# define __MAP_ITER_HPP__

# include "map_rbtree.hpp"
# include "pair.hpp"
# include "utils.hpp"

namespace ft
{
	class OutOfRangeException: public std::exception
	{
	public:
		const char* what(void) const throw()
		{
			return "Iterator is out of range";
		}
	};

	template<typename Key, typename T, typename Compare = ft::less<Key> >
	class mapIter
	{
	private:
		typedef ft::pair<Key, T> pair_t;
		typedef Rbtree<Key, T, Compare> *tree_type;
		typedef Node<pair_t> *RbtNode;
		typedef ptrdiff_t difference_type;

		tree_type _tree;
		RbtNode _now;

	public:

		mapIter(): _tree(NULL), _now(NULL) { }
		mapIter(tree_type src, RbtNode now): _tree(src), _now(now)
		{ 
			std::cout << "mapIter with tree_type, RbtNode" << std::endl;
		}
		template<typename RmapIter>
		mapIter(RmapIter &src)
		{
			*this = src;
		}
		mapIter &operator=(mapIter const &rhs)
		{
			if (this != &rhs)
			{
				*(this->_tree) = *rhs._tree;
				*(this->_now) = *rhs._now;
			}
			return *this;
		}
		~mapIter() {
			std::cout << "mapIter destructor" << std::endl;
		 }

		template<typename U, typename V>
		bool operator==(const mapIter<U, V, Compare> &rhs) const
		{
			return this->_now == rhs._now;
		}
		template<typename U, typename V>
		bool operator!=(const mapIter<U, V, Compare> &rhs) const
		{
			return this->_now != rhs._now;
		}

		mapIter &operator++()
		{
			_now = _tree->successor(_now);
			return *this;
		}
		mapIter operator++(int)
		{
			mapIter tmp(*this);
			++(*this);
			return tmp;
		}
		mapIter &operator--()
		{
			_now = _tree->predecessor(_now);
			return *this;
		}
		mapIter operator--(int)
		{
			mapIter tmp(*this);
			--(*this);
			return tmp;
		}
	
		pair_t& operator*() const
		{
			return _now->data;
		}
		
		pair_t* operator->() const
		{
			return &(this->operator*());
		}
		
		operator mapIter<const Key, T, Compare>() const
		{
			return mapIter<const Key, T, Compare>(this->_tree, this->_now);
		}
	};

	template<typename Key, typename T, typename Compare = ft::less<Key> >
	class mapConstIter
	{
	private:
		typedef ft::pair<Key, T> pair_t;
		typedef Rbtree<Key, T, Compare> *tree_type;
		typedef Node<pair_t> *RbtNode;
		typedef ptrdiff_t difference_type;
		typedef pair_t &reference;
		typedef pair_t *pointer;

		tree_type _tree;
		RbtNode _now;

	public:

		mapConstIter(): _tree(NULL), _now(NULL) { }
		mapConstIter(tree_type *src, RbtNode now): _tree(src), _now(now) { }
		template<typename RmapConstIter>
		mapConstIter(RmapConstIter &src)
		{
			*this = src;
		}
		mapConstIter &operator=(mapConstIter const &rhs)
		{
			if (this != &rhs)
			{
				*(this->_tree) = *rhs._tree;
				*(this->now) = *rhs._now;
			}
			return *this;
		}
		~mapConstIter() { }

		template<typename U, typename V>
		bool operator==(const mapConstIter<U, V, Compare> &rhs) const
		{
			return this->_now == rhs._now;
		}
		template<typename U, typename V>
		bool operator!=(const mapConstIter<U, V, Compare> &rhs) const
		{
			return this->_now != rhs._now;
		}

		mapConstIter &operator++()
		{
			_now = _tree->successor(_now);
			return *this;
		}
		mapConstIter operator++(int)
		{
			mapConstIter tmp(*this);
			++(*this);
			return tmp;
		}
		mapConstIter &operator--()
		{
			_now = _tree->predecessor(_now);
			return *this;
		}
		mapConstIter operator--(int)
		{
			mapConstIter tmp(*this);
			--(*this);
			return tmp;
		}
		const pair_t& operator*() const
		{
			return _now->data;
		}
		const pair_t* operator->() const
		{
			return &(this->operator*());
		}
		operator mapConstIter<const Key, T, Compare>() const
		{
			return mapConstIter<const Key, T, Compare>(this->_tree, this->_now);
		}
	};
}



#endif