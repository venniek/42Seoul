#ifndef __UTILS_HPP__
#define __UTILS_HPP__

namespace ft {
    // enable_if, is_integral
    template<bool cond, typename T = void>
    struct enable_if {};
    template<typename T>
    struct enable_if<true, T> {
        typedef T type;
    };
    template<typename T, bool _bool>
    struct integral_constant {
        typedef bool value_type;
        typedef T type;
        static const value_type value = _bool;
    };
    template<typename T>
    struct is_integral: public integral_constant<T, false> { };
    template <>
    struct is_integral<bool>: public integral_constant<bool, true> { };
    template <>
    struct is_integral<char>: public integral_constant<char, true> { };
    template <>
    struct is_integral<wchar_t>: public integral_constant<wchar_t, true> { };
    template <>
    struct is_integral<signed char>: public integral_constant<signed char, true> { };
    template <>
    struct is_integral<short>: public integral_constant<short, true> { };
    template <>
    struct is_integral<int>: public integral_constant<int, true> { };
    template <>
    struct is_integral<long int>: public integral_constant<long int, true> { };
    template <>
    struct is_integral<long long int>: public integral_constant<long long int, true>{ };
    template <>
    struct is_integral<unsigned char>: public integral_constant<unsigned char, true> { };
    template <>
    struct is_integral<unsigned short>: public integral_constant<unsigned short, true> { };
    template <>
    struct is_integral<unsigned int>: public integral_constant<unsigned int, true> { };
    template <>
    struct is_integral<unsigned long>: public integral_constant<unsigned long, true> { };
	template<>
	struct is_integral<unsigned long long int>: public integral_constant<unsigned long long, true> { };

    // binary function, less
    template<typename Arg1, typename Arg2, typename Return>
    struct binary_function {
        typedef Arg1 first_type;
        typedef Arg2 second_type;
        typedef Return return_type;
    };
    template<typename T>
    struct less: binary_function<T, T, bool> {
        bool operator()(const T &x, const T &y) const {
            return x < y;
        }
    };

    template<typename T>
    void swap(T &a, T &b) {
        T tmp = a;

        a = b;
        b = tmp;
    }

    template<typename size_type, typename value_type, typename Alloc>
    void array_clear(size_type &_size, size_type &_capacity, value_type **_array, Alloc _alloc) {
        if (*_array !=  NULL) {
            for (size_t i = 0; i < _size; i++)
                _alloc.destroy(*_array + i);
            _alloc.deallocate(*_array, _capacity);
            *_array = 0;
            _size = 0;
            _capacity = 0;
        }
    }

    // equal, lexicographical_compare
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
    template <class It1, class It2, class BinaryPredicate>
    bool equal(It1 first1, It1 last1, It2 first2, BinaryPredicate pred) {
        while (first1 != last1) {
            if (!pred(*first1, *first2))
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