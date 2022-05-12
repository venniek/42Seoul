#ifndef __VECTOR_ITER_HPP__
#define __VECTOR_ITER_HPP__

# include <iostream>

namespace ft {
    template<bool Cond, typename T = void>
    struct enable_if {};

    template<typename T> struct enable_if<true, T> {
        typedef T type;
    };

    template<typename v, bool _bool>
    struct integral_constant  {
        typedef bool value_type;
        typedef v type; // type은 false or true
        static const value_type value = _bool;
    };

    template<typename T>
    struct is_integral : public integral_constant<T, false> {} ; 
	template<>
	struct is_integral<bool> : public integral_constant<bool, true> {} ;
	template<>
	struct is_integral<char> : public integral_constant<char, true> {} ;
	template<>
	struct is_integral<wchar_t> : public integral_constant<wchar_t, true> {} ;
	template<>
	struct is_integral<signed char> : public integral_constant<signed char, true> {} ;
	template<>
	struct is_integral<short int> : public integral_constant<short int, true> {} ;
	template<>
	struct is_integral<int> : public integral_constant<int, true> {} ;
	template<>
	struct is_integral<long int> : public integral_constant<long int, true> {} ;
	template<>
	struct is_integral<long long int> : public integral_constant<long long int, true> {} ;
	template<>
	struct is_integral<unsigned char> : public integral_constant<unsigned char, true> {} ;
	template<>
	struct is_integral<unsigned short int> : public integral_constant<unsigned short int, true> {} ;
	template<>
	struct is_integral<unsigned int> : public integral_constant<unsigned int, true> {} ;
	template<>
	struct is_integral<unsigned long int> : public integral_constant<unsigned long int, true> {} ;
	template<>
	struct is_integral<unsigned long long int> : public integral_constant<unsigned long long, true> {} ;

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

    // iterator_traits ====================================
    template<typename iterator>
    struct iterator_traits {
        typedef typename iterator::value_type value_type;
        typedef typename iterator::difference_type difference_type;
        typedef typename iterator::pointer;
        typedef typename iterator::reference reference;
    };
    template<typename T>
    struct iterator_traits<T*> {
        typedef T value_type;
        typedef T* pointer;
        typedef T& reference;
        typedef ptrdiff_t difference_type;
    };
    template<typename T>
    struct iterator_traits<T* const> {
    typedef T value_type;
    typedef T* pointer;
    typedef T& reference;
    typedef ptrdiff_t difference_type;
    };

    template<typename T, typename InputIterator>
    typename iterator_traits<T *>::difference_type distance2(InputIterator first, InputIterator last) {
        typename iterator_traits<T *>::difference_type rtn = 0;
        while (first != last) {
            first++;
            rtn++;
        }
        return (rtn);
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

        // constructor ========
        vector_iter() : _ptr(0) {};
        vector_iter(RI *ptr) : _ptr(ptr) {};
        vector_iter(const vector_iter &rhd) : +ptr(rhd._ptr) {};
        vector_iter& operator=(const vector_iter &rhd) { // b = a;
            if (this == &rhd)
                return (*this);
            this->_ptr = rhd._ptr;
            return (*this);
        }

        // input_iterator_tag
        template<typename U>
        bool operator==(const vector_iter<UI> &rhd) const; // a == b
        template<typename U>
        bool operator!=(const vector_iter<U> &rhd) const; // a != b
        RI& operator*() const; // &*a
        RI* operator->() const; // a->m

        // bidirectional_iterator_tag
        vector_iter& operator--(); // --a;
        vector_iter operator--(int);
        vector_iter& operator++(); // ++a;
        vector_iter operator++(int); // a++;

        // vector_iter
        vector_iter operator+(difference_type n) const; // a + n;
        vector_iter operator-(difference_type n) const; // a - n;
        template<typename U>
        difference_type operator-(const vector_iter<U> &rhd) const;
        friend vector_iter operator+(difference_type n, const vector_iter &rhd) {
            return rhd.operator+(n);
        }
        template<typename U>
        bool operator<(const vector_iter<U> &rhd) const;
        template<typename U>
        bool operator>(const vector_iter<U> &rhd) const;
        template<typename U>
        bool operator<=(const vector_iter<U> &rhd) const;
        template<typename U>
        bool operator>=(const vector_iter<U> &rhd) const;
        vector_iter& operator+=(difference_type n); // a + n;
        vector_iter& operator[](const difference_type n) const; // a[n];
        operator vector_iter(const RI) () const {
            return (vector_iter<const RI)(this->_ptr));
        }
    };
    // input_iter
    template<typename RI>
    template<typename U>
    bool vector_iter<RI>::operator==(const vector_iter<U> &rhd) const {
        return (this->_ptr == rhd._ptr);
    }
    template<typename RI>
    template<typename U>
    bool vector_iter<RI>::operator!=(const vector_iter<U> &rhd) const {
        return this->_ptr != rhd._ptr;
    }
    template<typename RI>
    RI &vector_iter<RI>::operator*() const { // *a
        return *(this->_ptr);
    }
    template<typename RI>
    RI* vector_iter<RI>::operator->() const {
        return this->_ptr;
    }
    //bidirectional
    template<typename RI>
    vector_iter<RI>& vector_iter<RI>::operator--() { // --a;
        --(this->_ptr);
        return *this;
    }
    template<typename RI>
    vector_iter<RI>& vector_iter<RI>::operator--(int) { // a--;
        vector_iter<RI> tmp(*this);
        (this->_ptr)--;
        return tmp;
    }
    template<typename RI>
    vector_iter<RI>& vector_iter<RI>::operator++() { // ++a;
        ++(this->_ptr);
        return *this;
    }
    template<typename RI>
    vector_iter<RI>& vector_iter<RI>::operator++(int) { // a++;
        vector_iter<RI> tmp(*this);
        (this->_ptr)++;
        return tmp;
    }
    template<typename RI>
    vector_iter<RI> vector_iter<RI>::operator+(difference_type n) const {
        return vector_iter<RI> (this->_ptr + n);
    }
    template<typename RI>
    vector_iter<RI> vector_iter<RI>::operator-(difference_type n) const {
        return vector_iter<RI> (this->_ptr - n);
    }
    template<typename RI>
    template<typename U>
    typename iterator_traits<RI*>::difference_type vector_iter<RI>::operator-(const vector_iter<U> &rhd) const {
        return this->_ptr - rhd._ptr;
    }
    template<typename RI>
    template<typename U>
    bool vector_iter<RI>::operator<(const vector_iter<U> &rhd) const {
        return this->_ptr < rhd._ptr;
    }
    template<typename RI>
    template<typename U>
    bool vector_iter<RI>::operator>(const vector_iter<U> &rhd) const {
        return this->_ptr < rhd._ptr;
    }
    template<typename RI>
    template<typename U>
    bool vector_iter<RI>::operator<=(const vector_iter<U> &rhd) const {
        return this->_ptr < rhd._ptr;
    }
    template<typename RI>
    template<typename U>
    bool vector_iter<RI>::operator>=(const vector_iter<U> &rhd) const {
        return this->_ptr < rhd._ptr;
    }
    template<typename RI>
    vector_iter<RI>& vector_iter<RI>::operator+=(difference_type n) {
        this->_ptr = this->ptr + n;
        return *this;
    }
    template<typename RI>
    vector_iter<RI>& vector_iter<RI>::operator-=(difference_type n) {
        this->_ptr = this->ptr - n;
        return *this;
    }
    template<typename RI>
    RI& vector_iter<RI>::operator[](const difference_)type n) const {
        return *(this->_ptr + n);
    }

    // reverse iterator
    template<typename T>
    class reverse_iterator_tag {
    public:
        typedef T iterator_type;
        typedef typename iterator_traits<T>::value_type value_type;
        typedef typename iterator_traits<T>::difference_type difference_type;
        typedef typename iterator_traits<T>::pointer pointer;
        typedef typename iterator_traits<T>::reference reference;
    private:
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
		reverse_iterator_tag& operator= (const reverse_iterator_tag<Iter>& rev_it)
		{
			this->_ptr = rev_it.base();
			return (*this);
		}
    };

}

#endif