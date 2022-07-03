#ifndef __UTILS_HPP__
#define __UTILS_HPP__

namespace ft {
    template<typename T>
    void swap(T &a, T &b) {
        T tmp = a;

        a = b;
        b = tmp;
    }

    size_t increase_capacity(size_t _size, size_t n, size_t _capacity) {
        if (_capacity == 0)
            _capacity = 1;
        while (_size + n >= _capacity)
            _capacity *= 2;
        return _capacity;
    }

    template<typename size_type, typename value_type, typename Alloc>
    void array_clear(size_type &_size, size_type &_capacity, value_type **_array, Alloc _alloc) {
        if (*_array !=  NULL) {
            for (size_t i = 0; i < _size; i++)
                _alloc.destory(*_array + i);
            _alloc.deallocate(*_array, _capacity);
            *_array = 0;
            _size = 0;
            _capacity = 0;
        }
    }

    template<typename It1, typename It2>
    bool equal(It1 first1, It1 last1, It2 first2) {
        while (first1 != last1) {
            if (*first1 != *first2)
                return false;
            ++first1;
            ++first2;
        }
        return true;
    }

    template <typename It1, typename It2>
    bool lexicographical_compare (It1 first1, It1 last1, It2 first2, It2 last2) {
        while (first1 != last1) {
            if (first2 == last2 || *first2 < *first1)
                return false;
            else if (*first1 < *first2)
                return true;
            ++first1; 
            ++first2;
        }
        return first2 != last2;
    }

    template <typename It1, typename It2, typename Compare>
    bool lexicographical_compare (It1 first1, It1 last1, It2 first2, It2 last2, Compare comp) {
        while (first1 != last1) {
            if (first2 == last2 || comp(*first2, *first1))
                return false;
            else if (comp(*first1 < *first2))
                return true;
            ++first1; 
            ++first2;
        }
        return first2 != last2;
    }




}


#endif