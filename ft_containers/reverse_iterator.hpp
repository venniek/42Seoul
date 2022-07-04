#ifndef __REVERSE_ITERATOR_HPP__
#define __REVERSE_ITERATOR_HPP__

# include "./iterator_traits.hpp"

namespace ft {
	template<typename Iterator>
	class reverse_iterator {
	public:
		typedef Iterator iterator_type;
		typedef typename iterator_traits<iterator_type>::difference_type difference_type;
		typedef typename iterator_traits<iterator_type>::value_type value_type;
		typedef typename iterator_traits<iterator_type>::pointer pointer;
		typedef typename iterator_traits<iterator_type>::reference reference;
		typedef typename iterator_traits<iterator_type>::iterator_category iterator_category;

		reverse_iterator(): iterator(iterator_type()) { }
		explicit reverse_iterator(iterator_type it): iterator(it) { }
		template<typename other>
		reverse_iterator(const reverse_iterator<other>& copy): iterator(copy.base()) { }
		~reverse_iterator() { }
	private:
		iterator_type iterator;
	public:
		iterator_type base() const {
			return iterator;
		}
		template<typename U>
		reverse_iterator& operator=(const reverse_iterator<U>& it) {
			iterator = it.base();
			return *this;
		}
		reference operator*() const {
			iterator_type tmp = iterator;
			return *--tmp;
		}
		reference operator[](difference_type n) const {
			return *(*this + n);
		}
		pointer operator->() const {
			return &operator*();
		}

		reverse_iterator& operator++() {
			--iterator;
			return *this;
		}
		reverse_iterator operator++(int) {
			reverse_iterator tmp(*this);
			--iterator;
			return tmp;
		}
		reverse_iterator& operator--() {
			++iterator;
			return *this;
		}
		reverse_iterator operator--(int) {
			reverse_iterator tmp(*this);
			++iterator;
			return tmp;
		}
		reverse_iterator operator+(difference_type n) const {
			return reverse_iterator(iterator - n);
		}
		reverse_iterator operator-(difference_type n) const {
			return reverse_iterator(iterator + n);
		}
		reverse_iterator& operator+=(difference_type n) {
			iterator -= n;
			return *this;
		}
		reverse_iterator& operator-=(difference_type n) {
			iterator += n;
			return *this;
		}
	};

	template <class Iterator>
	reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& it) {
		return reverse_iterator<Iterator>(it.base() - n);
	}

	template <class It1, class It2>
	typename reverse_iterator<It1>::difference_type operator-(const reverse_iterator<It1>& x, const reverse_iterator<It2>& y) {
		return y.base() - x.base();
	}

	/* relational operators */
	template <class It1, class It2>
	bool operator==(const reverse_iterator<It1>& x, const reverse_iterator<It2>& y) {
		return x.base() == y.base();
	}

	template <class It1, class It2>
	bool operator!=(const reverse_iterator<It1>& x, const reverse_iterator<It2>& y) {
		return x.base() != y.base();
	}

	template <class It1, class It2>
	bool operator<(const reverse_iterator<It1>& x, const reverse_iterator<It2>& y) {
		return x.base() > y.base();
	}

	template <class It1, class It2>
	bool operator<=(const reverse_iterator<It1>& x, const reverse_iterator<It2>& y) {
		return x.base() >= y.base();
	}

	template <class It1, class It2>
	bool operator>(const reverse_iterator<It1>& x, const reverse_iterator<It2>& y) {
		return x.base() < y.base();
	}

	template <class It1, class It2>
	bool operator>=(const reverse_iterator<It1>& x, const reverse_iterator<It2>& y) {
		return x.base() <= y.base();
	}
}

#endif