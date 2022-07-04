#ifndef __VECTOR_ITERATOR_HPP__
#define __VECTOR_ITERATOR_HPP__

# include <iostream>
# include "utils.hpp"
# include "iterator_traits.hpp"

namespace ft {
    template<typename RandomIterator>
    class vector_iterator: public iterator<std::random_access_iterator_tag, RandomIterator> {
    public:
        typedef RandomIterator iterator_type;
        typedef typename iterator_traits<iterator_type *>::value_type value_type;
        typedef typename iterator_traits<iterator_type *>::difference_type difference_type;
        typedef typename iterator_traits<iterator_type *>::pointer pointer;
        typedef typename iterator_traits<iterator_type *>::reference reference;
        RandomIterator *_ptr;

        vector_iterator(): _ptr(0) { };
        vector_iterator(RandomIterator *ptr): _ptr(ptr) { };
        vector_iterator(const vector_iterator &copy): _ptr(copy._ptr) { };
        vector_iterator& operator=(const vector_iterator &origin) {
            if (this != &origin)
                this->_ptr = origin._ptr;
            return *this;
        }
        template<typename T>
        bool operator==(const vector_iterator<T> &rhs) const {
            return this->_ptr == rhs._ptr;
        }
        template<typename T>
        bool operator!=(const vector_iterator<T> &rhs) const {
            return this->_ptr != rhs._ptr;
        }
        RandomIterator& operator*() const {
            return *(this->_ptr);
        }
        RandomIterator* operator->() const {
            return this->_ptr;
        }
        vector_iterator& operator--() {
            --(this->_ptr);
            return *this;
        }
        vector_iterator operator--(int) {
            vector_iterator<RandomIterator> tmp(*this);
            --(*this);
            return tmp;
        }
        vector_iterator& operator++() {
            ++(this->_ptr);
            return *this;
        }
        vector_iterator operator++(int) {
            vector_iterator tmp(*this);
            ++(*this);
            return tmp;
        }
        friend vector_iterator	operator+(difference_type n, const vector_iterator &rhd) {
			return rhd.operator+(n);
		}
        vector_iterator operator+(difference_type n) const {
            return vector_iterator<RandomIterator>(this->_ptr + n);
        }
        vector_iterator operator-(difference_type n) const {
            return vector_iterator<RandomIterator>(this->_ptr - n);
        }
        vector_iterator& operator+=(difference_type n) {
            this->_ptr = this->_ptr + n;
            return *this;
        }
        vector_iterator& operator-=(difference_type n) {
            this->_ptr = this->_ptr - n;
            return *this;
        }
        template<typename T>
        difference_type operator-(const vector_iterator<T> &rhs) const {
            return this->_ptr - rhs._ptr;
        }
        template<typename T>
        bool operator<(const vector_iterator<T> &rhs) const {
            return this->_ptr < rhs._ptr;
        }
        template<typename T>
        bool operator<=(const vector_iterator<T> &rhs) const {
            return this->_ptr <= rhs._ptr;
        }
        template<typename T>
        bool operator>(const vector_iterator<T> &rhs) const {
            return this->_ptr > rhs._ptr;
        }
        template<typename T>
        bool operator>=(const vector_iterator<T> &rhs) const {
            return this->_ptr >= rhs._ptr;
        }
        RandomIterator& operator[](const difference_type n) const {
            return *(this->_ptr + n);
        }

        operator vector_iterator<const RandomIterator>() const {
            return vector_iterator<const RandomIterator>(this->_ptr);
        }
    }; // class vector_iterator

    template<typename Iterator>
    class reverse_iterator_tag {
    public:
        typedef Iterator iterator_type;
        typedef typename iterator_traits<Iterator>::value_type value_type;
        typedef typename iterator_traits<Iterator>::difference_type difference_type;
        typedef typename iterator_traits<Iterator>::pointer pointer;
        typedef typename iterator_traits<Iterator>::reference reference;
    private:
        iterator_type _ptr;
    public:
        reverse_iterator_tag(): _ptr() { };
        reverse_iterator_tag(iterator_type ptr): _ptr(ptr) { };
        template<typename T>
        reverse_iterator_tag(const reverse_iterator_tag<T> &copy): _ptr(copy.base()) { };
        virtual ~reverse_iterator_tag() { };

        reference operator*() const {
            iterator_type tmp = _ptr;
            return *(--tmp);
        }
        pointer operator->() const {
            return &operator*();
        }
        reference operator[](difference_type n) const {
            return *operator+(n);
        }
        reverse_iterator_tag operator+(difference_type n) const {
            return reverse_iterator_tag(_ptr - n);
        }
        reverse_iterator_tag& operator++() {
            --_ptr;
            return *this;
        }
        reverse_iterator_tag operator++(int) {
            reverse_iterator_tag tmp = *this;
            ++(*this);
            return tmp;
        }
        reverse_iterator_tag& operator+=(difference_type n) {
            _ptr -= n;
            return *this;
        }
        
        reverse_iterator_tag operator-(difference_type n) const {
            return reverse_iterator_tag(_ptr + n);
        }
        reverse_iterator_tag& operator--() {
            ++_ptr;
            return *this;
        }
        reverse_iterator_tag operator--(int) {
            reverse_iterator_tag tmp = *this;
            --(*this);
            return tmp;
        }
        reverse_iterator_tag& operator-=(difference_type n) {
            _ptr += n;
            return *this;
        }
        iterator_type base() const {
            return this->_ptr;
        }
    }; // class reverse_iterator_tag
    template <typename iterator>
    reverse_iterator_tag<iterator> operator+ (typename reverse_iterator_tag<iterator>::difference_type n, const reverse_iterator_tag<iterator>& rit) {
        return (reverse_iterator_tag<iterator>(rit.base() - n));
    }
    template <typename it1, typename it2>
	ptrdiff_t operator-(const reverse_iterator_tag<it1>& lhs, const reverse_iterator_tag<it2>& rhs) {
		return rhs.base() - lhs.base(); 
	}
    template <typename it1, typename it2>
    bool operator==(const reverse_iterator_tag<it1> & lhs, const reverse_iterator_tag<it2> & rhs) {
        return lhs.base() == rhs.base();
    }
    template <typename it1, typename it2>
    bool operator!=(const reverse_iterator_tag<it1> & lhs, const reverse_iterator_tag<it2> & rhs) {
        return lhs.base() != rhs.base();
    }
    template <typename it1, typename it2>
    bool operator>(const reverse_iterator_tag<it1> & lhs, const reverse_iterator_tag<it2> & rhs) {
        return lhs.base() < rhs.base();
    }
    template <typename it1, typename it2>
    bool operator>=(const reverse_iterator_tag<it1> & lhs, const reverse_iterator_tag<it2> & rhs) {
        return lhs.base() <= rhs.base();
    }
    template <typename it1, typename it2>
    bool operator<(const reverse_iterator_tag<it1> & lhs, const reverse_iterator_tag<it2> & rhs) {
        return lhs.base() > rhs.base();
    }
    template <typename it1, typename it2>
    bool operator<=(const reverse_iterator_tag<it1> & lhs, const reverse_iterator_tag<it2> & rhs) {
        return lhs.base() >= rhs.base();
    }

} // namespace ft

#endif