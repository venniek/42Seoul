#ifndef __VECTOR_ITER_HPP__
#define __VECTOR_ITER_HPP__

# include "iterator_traits.hpp"
# include "reverse_iterator.hpp"
# include <iostream>

namespace ft {
    struct input_iterator_tag {};
    struct output_iterator_tag {};
    struct forward_iterator_tag : public input_iterator_tag, output_iterator_tag {};
    struct bidirectional_iterator_tag : public forward_iterator_tag {};
    struct random_access_iterator_tag : public bidirectional_iterator_tag {};

    template<typename Category, typename T, typename Distance = ptrdiff_t, typename Pointer = T*, typename Reference = T&>
    struct iterator {
        typedef T value_type;
        typedef Distance difference_type;
        typedef Pointer pointer;
        typedef Reference reference;
    };



    template<typename T, typename InputIterator>
    typename iterator_traits<T *>::difference_type distance2(InputIterator first, InputIterator last) {
        typename iterator_traits<T *>::difference_type cnt = 0;
        while (first != last) {
            first++;
            cnt++;
        }
        return (cnt);
    }

    // RI == Random Iterator
    template <typename RI>
    class vector_iter : public iterator<std::random_access_iterator_tag, RI> {
    public:
        typedef RI iterator_type;
        typedef typename iterator_traits<iterator_type*>::value_type value_type;
        typedef typename iterator_traits<iterator_type*>::difference_type difference_type;
        typedef typename iterator_traits<iterator_type*>::pointer pointer;
        typedef typename iterator_traits<iterator_type*>::reference reference;
        RI* _ptr;

        // ================ constructor ==============================================
        // default
        vector_iter() : _ptr(0) {};
        // with argument
        vector_iter(iterator_type *ptr) : _ptr(ptr) {};
        // copy
        vector_iter(const vector_iter &rhd) : _ptr(rhd._ptr) {};
        // operator= overload
        vector_iter& operator=(const vector_iter &rhd) {
            if (this == &rhd)
                return (*this);
            this->_ptr = rhd._ptr;
            return (*this);
        }

        // input_iterator_tag
        template<typename U>
        bool operator==(const vector_iter<U> &rhd) const {
            return this->_ptr == rhd._ptr;
        }
        template<typename U>
        bool operator!=(const vector_iter<U> &rhd) const {
            return this->_ptr != rhd._ptr;
        }
        RI& operator*() const {
            return *(this->_ptr);
        }
        RI* operator->() const {
            return this->_ptr;
        }

        // bidirectional_iterator_tag
        vector_iter& operator--() { // --a
            --(this->_ptr);
            return *this;
        }
        vector_iter operator--(int) { // a--
            vector_iter tmp(*this);
            --(this->_ptr);
            return tmp;
        }
        vector_iter& operator++() { // ++a
            ++(this->_ptr);
            return *this;
        }
        vector_iter operator++(int) { // a++
            vector_iter tmp(*this);
            ++(this->_ptr);
            return tmp;
        }

        // vector_iter
        vector_iter operator+(difference_type n) const {
            return this->_ptr + n;
        }

        vector_iter operator-(difference_type n) const {
            return this->_ptr - n;
        }
        template<typename U>
        difference_type operator-(const vector_iter<U> &rhd) const {
            return this->_ptr - rhd._ptr;
        }
        friend vector_iter operator+(difference_type n, const vector_iter &rhd) {
            return rhd.operator+(n);
        }
        template<typename U>
        bool operator<(const vector_iter<U> &rhd) const {
            return this->_ptr < rhd._ptr;
        }
        template<typename U>
        bool operator>(const vector_iter<U> &rhd) const {
            return this->_ptr > rhd._ptr;
        }
        template<typename U>
        bool operator<=(const vector_iter<U> &rhd) const {
            return this->_ptr <= rhd._ptr;
        }
        template<typename U>
        bool operator>=(const vector_iter<U> &rhd) const {
            return this->_ptr >= rhd._ptr;
        }
        vector_iter& operator+=(difference_type n) {
            this->_ptr += n;
            return *this;
        }
        vector_iter& operator-=(difference_type n) {
            this->_ptr -= n;
            return *this;
        }
        RI& operator[](const difference_type n) const {
            return *(this->_ptr + n);
        }
        operator vector_iter<const RI> () const {
            return (vector_iter<const RI>(this->_ptr));
        }
    };

    // reverse iterator
    template<typename T>
    class reverse_iterator_tag {
    public:
        typedef T iterator_type;
        typedef typename iterator_traits<T>::value_type value_type;
        typedef typename iterator_traits<T>::difference_type difference_type;
        typedef typename iterator_traits<T>::pointer pointer;
        typedef typename iterator_traits<T>::reference reference;

        iterator_type _ptr;
    public:
        reverse_iterator_tag(): _ptr() {};
        reverse_iterator_tag(iterator_type ptr): _ptr(ptr) {};
        template<typename iter>
        reverse_iterator_tag(const reverse_iterator_tag<iter>& rev_it): _ptr(rev_it.base()) {};
        virtual ~reverse_iterator_tag() {};

        reference operator*() const {
            iterator_type tmp = _ptr;
            return *(--tmp);
        }
        reverse_iterator_tag operator+(difference_type n) const {
		    return (reverse_iterator_tag(_ptr - n));
		}
        friend reverse_iterator_tag operator+(difference_type n, const reverse_iterator_tag &rhd) {
            return rhd.operator+(n);
        }
		reverse_iterator_tag& operator++() {
            --_ptr;
            return (*this);
		}
		reverse_iterator_tag operator++(int) {
            reverse_iterator_tag rhd = *this;
            ++(*this);
            return(rhd);
		}
		reverse_iterator_tag& operator+=(difference_type n) {
            _ptr -= n;
            return (*this);
		}
		reverse_iterator_tag operator-(difference_type n) const {
		    return (reverse_iterator_tag(_ptr + n));
		}
		reverse_iterator_tag& operator--() {
            ++_ptr;
            return (*this);
		}
		reverse_iterator_tag operator--(int) 
		{
            reverse_iterator_tag rhd = *this;
            ++(_ptr);
            return (rhd);
		}
		reverse_iterator_tag& operator-=(difference_type n) {
            _ptr += n;
            return (*this);
		}
		pointer operator->() const { 
            return &(operator*()); 
        }
		reference operator[](difference_type n) const { 
            return *this->operator+(n); 
        }
		iterator_type base() const {
			return (this->_ptr);
		}
		//설명 : operator= c+11에 있는데 사용하는 테스트기에 테스트가 있어서 만듬
		template <class Iter>
		reverse_iterator_tag& operator=(const reverse_iterator_tag<Iter>& rev_it)
		{
			this->_ptr = rev_it.base();
			return (*this);
		}
    };

	//===========================Non-member function overloads======================
	template <class Iterator>
	reverse_iterator_tag<Iterator> operator+ (
            typename reverse_iterator_tag<Iterator>::difference_type n,
             const reverse_iterator_tag<Iterator>& rev_it)
	{
		return (reverse_iterator_tag<Iterator>(rev_it.base() - n)); //base 이름 바꾸자.
	}
	 
	// 설명 : reverse_iterator - const_reverse_iterator
	// 설명 : 이거 c+11기능인데, 테스트케이스에 있어서 그냥 해줬음.
	// 설명 : c+98에는 left, right같은 타입만 받음.
	template <class Iterator_left, class Iterator_right>
	ptrdiff_t operator- (
            const reverse_iterator_tag<Iterator_left>& lhs,
             const reverse_iterator_tag<Iterator_right>& rhs)
	{
		return (rhs.base() - lhs.base()); //base 이름 바꾸자.
	}

	template <class Iterator1, class Iterator2>
	  bool operator== (const reverse_iterator_tag<Iterator1>& lhs,
					   const reverse_iterator_tag<Iterator2>& rhs)
		{ return (lhs.base() == rhs.base()); }
	template <class Iterator1, class Iterator2>
	  bool operator!= (const reverse_iterator_tag<Iterator1>& lhs,
					   const reverse_iterator_tag<Iterator2>& rhs)
		{ return (lhs.base() != rhs.base()); }

	template <class Iterator1, class Iterator2>
	  bool operator<  (const reverse_iterator_tag<Iterator1>& lhs,
					   const reverse_iterator_tag<Iterator2>& rhs)
		{ return (lhs.base() > rhs.base()); }
	template <class Iterator1, class Iterator2>
	  bool operator<= (const reverse_iterator_tag<Iterator1>& lhs,
					   const reverse_iterator_tag<Iterator2>& rhs)
		{ return (lhs.base() >= rhs.base()); }
	template <class Iterator1, class Iterator2>
	  bool operator>  (const reverse_iterator_tag<Iterator1>& lhs,
					   const reverse_iterator_tag<Iterator2>& rhs)
		{ return (lhs.base() < rhs.base()); }
	template <class Iterator1, class Iterator2>
	  bool operator>= (const reverse_iterator_tag<Iterator1>& lhs,
					   const reverse_iterator_tag<Iterator2>& rhs)
		{ return (lhs.base() <= rhs.base()); }

}

#endif