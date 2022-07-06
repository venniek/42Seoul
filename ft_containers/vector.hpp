#ifndef __VECTOR_HPP__
#define __VECTOR_HPP__

# include <iostream>
# include <memory>
# include "vector_iterator.hpp"

namespace ft {
    template<typename T, typename Alloc = std::allocator<T> >
    class vector {
    public:
        typedef T value_type;
        typedef Alloc allocator_type;
        typedef typename allocator_type::reference reference;
        typedef typename allocator_type::const_reference const_reference;
        typedef typename allocator_type::pointer pointer;
        typedef typename allocator_type::const_pointer const_pointer;
        typedef vector_iterator<value_type> iterator;
        typedef vector_iterator<const value_type> const_iterator;
        typedef reverse_iterator_tag<iterator> reverse_iterator;
        typedef reverse_iterator_tag<const_iterator> const_reverse_iterator;
        typedef ptrdiff_t difference_type;
        typedef size_t size_type;
    protected:
        allocator_type _alloc;
        value_type *_array;
        size_type _size;
        size_type _capacity;
    public:
        explicit vector(const allocator_type& alloc = allocator_type()): _alloc(alloc), _array(0), _size(0), _capacity(0) {}
        explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()): _alloc(alloc), _array(0), _size(n), _capacity(n) {
            _array = _alloc.allocate(_capacity);
            for (size_type i = 0; i < _size; i++)
                _alloc.construct(_array + i, val);
        }
        template<typename InputIterator>
        vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type* = nullptr): _alloc(alloc), _array(0), _size(0), _capacity(0) {
            this->assign(first, last);
        } // !!! nullptr?
        vector(const vector& copy): _array(0), _size(0), _capacity(0) {
            *this = copy;
        }
        ~vector() {
            this->clear();
            if (_array != NULL)
                _alloc.deallocate(_array, this->capacity());
            _array = NULL;
        }
        vector& operator=(const vector& origin) {
            if (this != &origin) {
                array_clear(_size, _capacity, &_array, _alloc);
                this->_size = origin._size;
                this->_alloc = origin._alloc;
                this->_capacity = origin._capacity;
                _array = _alloc.allocate(origin._capacity);
                for (size_t i = 0; i < origin._size; i++)
                    _alloc.construct(_array + i, origin._array[i]);
            }
            return *this;
        }

        // iterator
        iterator begin() {
            return _array;
        }
        const_iterator begin() const {
            return _array;
        }
        iterator end() {
            return _array + _size;
        }
        const_iterator end() const {
            return _array + _size;
        }
        reverse_iterator rbegin()  {
            return reverse_iterator(end());
        }
        const_reverse_iterator rbegin() const {
            return const_reverse_iterator(end());
        }
        reverse_iterator rend() {
            return reverse_iterator(begin());
        }
        const_reverse_iterator rend() const {
            return const_reverse_iterator(begin());
        }

        // capacity
        size_type size() const {
            return _size;
        }
        size_type max_size() const {
            return _alloc.max_size();
        }
        void resize(size_type n, value_type val = value_type()) {
            if (n < _size)
                _size = n;
            else if (n > _size) {
                if (n > _capacity) {
                    for (; _size < n; )
                        push_back(val);
                }
                else if (n <= _capacity) {
                    for (; _size < n; _size++)
                        _array[_size] = val;
                }
                _size = n;
            }
        }
        size_type capacity() const {
            return _capacity;
        }
        bool empty() const {
            return _size == 0;
        }
        void reserve(size_type n) {
            if (_capacity < n) {
                value_type *tmp = _alloc.allocate(n);
                size_type tmp_size = _size;
                for (size_type i = 0; i < _size; i++)
                    _alloc.construct(tmp + i, *(_array + i));
                array_clear(_size, _capacity, &_array, _alloc);
                _array = tmp;
                _capacity = n;
                _size = tmp_size;
            }
        }

        // element access
        reference operator[](size_type n) {
            return (this->_array)[n];
        }
        const_reference operator[](size_type n) const {
            return (this->_array)[n];
        }
        reference at(size_type n) {
            if (n >= size())
                throw std::out_of_range("Out of Range");
            return *(this->_array + n);
        }
        const_reference at(size_type n) const {
            if (n >= size())
                throw std::out_of_range("Out of Range");
            return *(this->_array + n);
        }
        reference front() {
            return *begin();
        }
        const_reference front() const {
            return *begin();
        }
        reference back() {
            return *(end() - 1);
        }
        const_reference back() const {
            return *(end() - 1);
        }

    
        // modifier
        template<typename InputIterator>
        void assign(InputIterator first, InputIterator last, typename enable_if<!is_integral<InputIterator>::value>::type* = 0) {
            difference_type distance_value = new_distance<InputIterator>(first, last);
            pointer tmp_array = _alloc.allocate(distance_value);
            for (size_type i = 0; first != last; i++) {
                _alloc.construct(tmp_array + i, *first);
                first++;
            }
            array_clear(_size, _capacity, &_array, _alloc);
            _size = distance_value;
            _capacity = distance_value;
            _array = tmp_array;
        }
        void assign(size_type n, const value_type& val) {
            array_clear(_size, _capacity, &_array, _alloc);
            _size = n;
            _capacity = n;
            _array = _alloc.allocate(n);
            for (size_type i = 0; i < n; i++)
                _alloc.construct(_array + i, val);
        }
        void push_back(const value_type& val) {
            if (_size + 1 > _capacity) {
                size_t tmp = _capacity;
                if (tmp == 0)
                    tmp = 1;
                while (_size + 1 >= tmp)
                    tmp *= 2;
                reserve(tmp);
            }
            _alloc.construct(_array + _size, val);
            _size++;
        }
        void pop_back() {
            if (_size != 0)
                _size--;
            _alloc.destroy(_array + _size);
        }
        iterator insert(iterator position, const value_type& val) {
            size_type idx;
            int flag = 0;

            if (_capacity == 0)
                _capacity = 1;
            while (_size >= _capacity)
                _capacity *= 2;
            value_type *tmp = _alloc.allocate(_capacity);
            size_type tmp_capacity = _capacity;
            size_type tmp_size = _size;
            for (size_type i = 0; i < _size + 1; i++) {
                if (flag == 0 && _array + i == position._ptr) {
                    _alloc.construct(tmp + i, val);
                    flag = 1;
                    idx = i;
                }
                else
                    _alloc.construct(tmp + i, *(_array + i - flag));
            }
            array_clear(_size, _capacity, &_array, _alloc);
            _array = tmp;
            _size = tmp_size + 1;
            _capacity = tmp_capacity;
            return iterator(begin() + idx);
        }
        void insert(iterator position, size_type n, const value_type& val) {
            if (n != 0) {
                size_type idx = 0;
                int flag = 0;
                if (_capacity == 0)
                    _capacity = 1;
                while (_size + n >= _capacity)
                    _capacity *= 2;
                value_type *tmp = _alloc.allocate(_capacity);
                size_type tmp_capacity = _capacity;
                size_type tmp_size = _size;
                for (size_type i = 0; i < _size + n + 1; i++) {
                    if (flag == 0 && _array + i == position._ptr) {
                        for (idx = 0; idx < n; idx++)
                            _alloc.construct(tmp + i + idx, val);
                        flag = 1;
                        i += idx;
                    }
                    else
                        _alloc.construct(tmp + i - flag, *(_array + (i - idx) - flag));
                }
                array_clear(_size, _capacity, &_array, _alloc);
                _array = tmp;
                _capacity = tmp_capacity;
                _size = tmp_size + n;
            }
        }
        template<typename InputIterator>
        void insert(iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = nullptr) {
            size_type idx = 0;
            int flag = 0;
            difference_type cnt = new_distance<value_type, InputIterator>(first, last);
            size_type tmp_size = cnt + _size;
            size_type tmp_capacity = _capacity;
            if (tmp_capacity == 0)
                tmp_capacity = 1;
            while (_size + cnt >= tmp_capacity)
                tmp_capacity *= 2;
            value_type *tmp = _alloc.allocate(tmp_capacity);
            
            for (size_type i = 0; i < _size + cnt + 1; i++) {
                if (flag != 1 && _array + i == position._ptr) {
                    for (idx = 0; first != last; first++) {
                        _alloc.construct(tmp + i + idx, (*first));
                        idx++;
                    }
                    flag = 1;
                    i += idx;
                }
                else
                    _alloc.construct(tmp + i - flag, *(_array + i - idx - flag));
            }
            array_clear(_size, _capacity, &_array, _alloc);
            _array = tmp;
            _capacity = tmp_capacity;
            _size = tmp_size;
        }
        iterator erase(iterator position) {
            for (iterator i = position; i < end() - 1; ++i)
				_array[i - begin()] = _array[i - begin() + 1];
			pop_back();
			return position;
        }
        iterator erase(iterator first, iterator last) {
            size_type diff = last - first;
			for (size_type i = first - begin(); i < _size - diff; ++i)
				_array[i] = _array[i + diff];
			for (size_type i = 0; i < diff; ++i)
				pop_back();
			return first;
        }
        void swap(vector& x) {
			allocator_type tmp_alloc = x._alloc;
			value_type* tmp_array = x._array;
			size_type tmp_size = x._size;
			size_type tmp_capacity = x._capacity;
 
			x._alloc = this->_alloc;
			x._array = this->_array;
			x._size = this->_size;
			x._capacity = this->_capacity;

			this->_alloc = tmp_alloc;
			this->_array = tmp_array;
			this->_size = tmp_size;
			this->_capacity = tmp_capacity;
        }
        void clear() {
            for (size_type i = 0; i < _size; i++)
                _alloc.destroy(_array + i);
            _size = 0;
        }

        // allocator
        allocator_type get_allocator() const {
            return _alloc;
        }
    }; // class vector

    // non-member functions
    template<typename T, typename Alloc>
    void swap(ft::vector<T, Alloc> &x, ft::vector<T, Alloc> &y) {
        x.swap(y);
    }
    template <typename T, typename Alloc>
    bool operator==(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs) {
        if (lhs.size() != rhs.size())
            return false;
        return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
    }
    template <typename T, typename Alloc>
    bool operator!=(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs) {
        return !(lhs == rhs);
    }
    template <typename T, typename Alloc>
    bool operator<(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs) {
        return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
    }
    template <typename T, typename Alloc>
    bool operator>(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs) {
        return rhs < lhs;
    }
    template <typename T, typename Alloc>
    bool operator<=(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs) {
        return !(lhs > rhs);
    }
    template <typename T, typename Alloc>
    bool operator>=(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs) {
        return !(lhs < rhs);
    }
} // namespace ft


#endif