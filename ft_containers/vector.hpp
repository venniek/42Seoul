#ifndef __VECTOR_HPP__
#define __VECTOR_HPP__

# include "vector_iter.hpp"
# include <iostream>

namespace ft {
    template <typename T, typename Alloc = std::allocator<T> >
    class vector {
    public:
        typedef T value_type;
        typedef Alloc<value_type> allocator_type;
        typedef typename allocator_type::reference reference;
        typedef typename allocator_type::const_reference const_reference;
        typedef typename allocator_type::pointer pointer;
        typedef typename allocator_type::const_pointer const_pointer;
        ptrdiff_t difference_type;
        size_t size_type;
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
            _array = allocate(n);
            for (int i = 0; i < n; i++)
                _alloc.construct(_array + i, val);
        }
        template <class InputIterator>
        vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()): _alloc(alloc) {
            difference_type diff = last - first;
            _array = allocate(diff);
            _size = diff;
            _capacity = diff;
            for (int i = 0; i < diff; i++)
                _alloc.construct(_array + i, *(first + i));
        }
        vector(const vector& x) {
            *this = x;
        }
        ~vector() {
            deallocate(_array, _capacity);
        }
        vector& operator=(const vector& x) {
            if (this != &x) {
                this->_alloc = x._alloc;
                if (this->_array)
                    deallocate(this->_array, this->_capacity);
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
            return _size();
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
                for (size_t i = 0; i < _size; i++)
                    _alloc.construct(tmp + i, _array[i]);
                // free_array(_size, _capacity, &_array, _alloc);
                _array = tmp;
                _capacity = n;
                _size = tmp_size;
            }
        }
        // ================================================================

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
        // ================================================================
        
        template <class InputIterator>
        void assign (InputIterator first, InputIterator last);
        void assign (size_type n, const value_type& val);

        void push_back(const value_type& val);
        void pop_back();

        iterator insert (iterator position, const value_type& val);
            void insert (iterator position, size_type n, const value_type& val);
        template <class InputIterator>
            void insert (iterator position, InputIterator first, InputIterator last);
        iterator erase (iterator position);
        iterator erase (iterator first, iterator last);

        void swap (vector& x);
        void clear();

        allocator_type get_allocator() const;

        bool operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
        bool operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
        bool operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
        bool operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
        bool operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
        bool operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

        void swap (vector<T,Alloc>& x, vector<T,Alloc>& y);




    
    
    }











}







#endif