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
        // 변환 생성자
        operator vector_iterator<const RandomIterator>() const {
            return vector_iterator<const RandomIterator>(this->_ptr);
        }
    }; // class vector_iterator

} // namespace ft

#endif