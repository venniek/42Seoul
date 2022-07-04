#ifndef __MAP_ITERATOR_HPP__
#define __MAP_ITERATOR_HPP__

# include "iterator_traits.hpp"
# include "reverse_iterator.hpp"
# include "avltree.hpp"

namespace ft {
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
		friend bool operator==(const map_iterator& lhs, const map_iterator& rhs) {
			return !(lhs == rhs);
		}
	};
}

#endif