#ifndef __VECTOR_HPP__
#define __VECTOR_HPP__

# include "vector_iter.hpp"
# include <iostream>
# include <memory>

namespace ft {
    template <typename T, typename Alloc = std::allocator<T> >
    class vector {
    public:
        typedef T value_type;
        typedef Alloc allocator_type;
        typedef typename allocator_type::reference reference;
        typedef typename allocator_type::const_reference const_reference;
        typedef typename allocator_type::pointer pointer;
        typedef typename allocator_type::const_pointer const_pointer;
        typedef ptrdiff_t difference_type;
        typedef size_t size_type;
    protected:
        allocator_type _alloc;
        value_type* _array;
        size_type _size;
        size_type _capacity;
    public:
        typedef vector_iter<value_type> iterator;
        typedef vector_iter<const value_type> const_iterator;
        typedef reverse_iterator_tag<iterator> reverse_iterator;
        typedef reverse_iterator_tag<const_iterator> const_reverse_iterator;

        // constructor, destructor, operator=---------------------------------------
        explicit vector(const allocator_type& alloc = allocator_type()) : _alloc(alloc), _array(0), _size(0), _capacity(0) {};        
        explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()): _alloc(alloc), _size(n), _capacity(n) {
            _array = _alloc.allocate(n);
            for (size_type i = 0; i < n; i++)
                _alloc.construct(_array + i, val);
        }
        vector(iterator first, iterator last, const allocator_type& alloc = allocator_type()): _alloc(alloc) {
            difference_type diff = last - first;
            _array = _alloc.allocate(diff);
            _size = diff;
            _capacity = diff;
            for (int i = 0; i < diff; i++)
                _alloc.construct(_array + i, first + i);
        }
        vector(const vector& x) {
            *this = x;
        }
        ~vector() {
            _alloc.deallocate(_array, _capacity);
        }
        vector& operator=(const vector& x) {
            if (this != &x) {
                this->_alloc = x._alloc;
                if (this->_array)
                    _alloc.deallocate(this->_array, this->_capacity);
                this->_array = allocate(x._size);
                this->_size = x._size;
                for (int i = 0; i < this->_size; i++)
                    this->_alloc.construct(this->_array + i, *(x.begin() + i));
                this->_capacity = x._capacity;
            }
            return *this;
        }
        // ===============================================================
    
        // iterator ======================================================
        iterator begin() { return _array; }
        const_iterator begin() const { return _array; }
        iterator end() { return _array + _size; }
        const_iterator end() const { return _array + _size; }
        reverse_iterator rbegin() { return reverse_iterator(end()); }
        const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); };
        reverse_iterator rend() { return reverse_iterator(begin()); };
        const_reverse_iterator rend() const { return const_reverse_iterator(begin()); };
        // ================================================================

        // capacity =======================================================
        size_type size() const {
            return _size;
        }
        size_type max_size() const {
            return _alloc.max_size();
        }
        void resize (size_type n, value_type val = value_type()) {
            if (n < _size) {
                
                _size = n;

            }
            else if (n > _size) {
                if (n > _capacity) {
                    while (_size < n)
                        push_back(val);
                }
                else {
                    while (_size < n)
                        _array[_size++] = val;
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
        void reserve (size_type n) {
            if (n > _capacity) {
                T* tmp = _alloc.allocate(n);
                size_type tmp_size = _size;
                for (size_t i = 0; i < _size; i++) {
                    _alloc.construct(tmp + i, _array[i]);
                }
				// _alloc.deallocate(_array);
                // free_array(_size, _capacity, &_array, _alloc);
                _array = tmp;
                _capacity = n;
                _size = tmp_size;
            }
        }
        // capacity =======================================================

        // element access =================================================
        reference operator[](size_type n) {
            return _array[n];
        }
        const_reference operator[](size_type n) const {
            return _array[n];
        }
        reference at(size_type n) {
            if (n >= _size)
                throw std::out_of_range("vector");
            return _array[n];
        }
        const_reference at(size_type n) const {
            if (n >= _size)
                throw std::out_of_range("vector");
            return _array[n];
        }
        reference front() {
            return _array[0];
        }
        const_reference front() const {
            return _array[0];
        }
        reference back() {
            return _array[_size - 1];
        }
        const_reference back() const {
            return _array[_size - 1];
        }
        // element access =================================================
        
        // modifier========================================================
        template <class InputIterator>
        void assign (InputIterator first, InputIterator last) {
            clear();
            for (InputIterator i = first; i < last; ++i)
                push_back(*i);
        }
        void assign (size_type n, const value_type& val) {
            clear();
            for (size_type i = 0; i < n; ++i)
                push_back(val);
        }
        void push_back(const value_type& val) {
            if (_size == _capacity)
                reserve(_capacity == 0 ? 1 : _capacity * 2);
            insert(end(), val);
        }
        void pop_back() {
            _alloc.destroy(end() - 1);
            --_size;
        }
        iterator insert (iterator position, const value_type& val) {
            if (_size + 1 > _capacity)
                reserve(_capacity * 2);
            for (size_type i = _size; i > size_type(position - begin()); --i)
                _array[i] = _array[i - 1];
			_array[position - begin()] = val;
            ++_size;
            return position;
        }
        void insert (iterator position, size_type n, const value_type& val) {
            if (_size + n > _capacity)
                reserve(_capacity * 2);
            for (size_type i = _size + n - 1; i > position - begin(); --i)
                _array[i] = _array[i - n];
            for (iterator i = position; i < position + n; ++i)
                insert(i, val);
        }
        template <class InputIterator>
            void insert (iterator position, InputIterator first, InputIterator last) {
            size_type n = last - first;
            if (_size + n > _capacity)
                reserve(_capacity * 2);
            for (size_type i = _size + n - 1; i > position - begin(); --i)
                _array[i] = _array[i - n];
            for (size_type i = 0; i < n; ++i)
                insert(position + i, *(first + i));
            }
        iterator erase (iterator position) {
            for (iterator i = position; i < end() - 1; ++i)
                _array[i - begin()] = _array[i - begin() + 1];
            pop_back();
        }
        iterator erase (iterator first, iterator last) {
            size_type diff = last - first;
            for (size_type i = first - begin(); i < _size - diff; ++i)
                _array[i] = _array[i + diff];
            for (size_type i = 0; i < diff; ++i)
                pop_back();
        }
        void swap (vector<value_type>& x) {
            for (size_type i = 0; i < std::min(_size, x.size()); ++i) {
                value_type tmp = x[i];
                x[i] = _array[i];
                _array[i] = tmp;
            }
            if (_size >= x.size()) {
                size_type size_tmp = x.size();
                for (size_type i = size_tmp; i < _size; ++i)
                    x.push_back(_array[i]);
                while (_size != size_tmp)
                    pop_back();
            }
            else {
                size_type size_tmp = _size;
                for (size_type i = size_tmp; i < x.size(); ++i)
                    push_back(x[i]);
                while (x.size() != size_tmp)
                    x.pop_back();
            }
        }
        void clear() {
            while (_size > 0)
                pop_back();
        }
        // modifier========================================================

        // allocator=======================================================
        allocator_type get_allocator() const {
            return _alloc;
        }
        // allocator=======================================================

    
    };
    // nonmember function overload=====================================
    template <typename T, typename Alloc>
    bool operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
        if (lhs.size() != rhs.size())
            return false;
        for (size_t i = 0; i < lhs.size(); ++i) {
            if (lhs[i] != rhs[i])
                return false;
        }
        return true;
    }
    template <typename T, typename Alloc>
    bool operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
        return !(lhs == rhs);
    }
    template <typename T, typename Alloc>
    bool operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
        while (lhs.begin() != lhs.end()) {
            if (rhs.begin() == rhs.end() || *lhs.begin() >= *rhs.begin()) 
                return false;
            else if (*lhs.begin() < *rhs.begin())
                return true;
            ++lhs.begin();
            ++rhs.begin();
        }
        return (rhs.begin() != rhs.end());
    }
    template <typename T, typename Alloc>
    bool operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
        return !(lhs > rhs);

    }
    template <typename T, typename Alloc>
    bool operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
        return (rhs < lhs);
    }
    template <typename T, typename Alloc>
    bool operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
        return !(lhs < rhs);
    }
    template <typename T, typename Alloc>
    void swap(vector<T,Alloc>& x, vector<T,Alloc>& y) {   
        // for (size_type i = 0; i < std::min(x.size(), y.size()); ++i) {
        //     value_type tmp = x[i];
        //     x[i] = y[i];
        //     y[i] = tmp;
        // }
        // if (y.size() >= x.size()) {
        //     size_type size_tmp = x.size();
        //     for (size_type i = size_tmp; i < y.size(); ++i)
        //         x.push_back(y[i]);
        //     while (y.size() != size_tmp)
        //         pop_back();
        // }
        // else {
        //     size_type size_tmp = y.size();
        //     for (size_type i = size_tmp; i < x.size(); ++i)
        //         y.push_back(x[i]);
        //     while (x.size() != size_tmp)
        //         x.pop_back();
        // }
        x.swap(y);
    }
    // nonmember function overload=====================================
}

#endif