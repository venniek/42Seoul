#ifndef __ITERATOR_TRAITS_HPP__
#define __ITERATOR_TRAITS_HPP__

# include <cstddef>
# include <iterator>

namespace ft {
    template<typename Category, typename T, typename Distance = ptrdiff_t, typename Pointer = T*, typename Reference = T&>
    struct iterator {
        typedef T value_type;
        typedef Distance difference_type;
        typedef Pointer pointer;
        typedef Reference reference;
        typedef Category iterator_category;
    };

    template<typename iterator>
    struct iterator_traits {
        typedef typename iterator::value_type value_type;
        typedef typename iterator::difference_type difference_type;
        typedef typename iterator::pointer pointer;
        typedef typename iterator::reference reference;
        typedef typename iterator::iterator_category iterator_category;
    };

    template<typename T>
    struct iterator_traits<T *> {
        typedef T value_type;
        typedef T* pointer;
        typedef T& reference;
        typedef ptrdiff_t difference_type;
        typedef std::random_access_iterator_tag iterator_category;
    };

    template<typename T>
    struct iterator_traits<const T *> {
        typedef T value_type;
        typedef const T* pointer;
        typedef const T& reference;
        typedef ptrdiff_t difference_type;
        typedef std::random_access_iterator_tag iterator_category;
    };

    template<typename T, typename InputIterator>
    typename iterator_traits<T*>::difference_type new_distance(InputIterator first, InputIterator last) {
        typename iterator_traits<T*>::difference_type ret = 0;

        while (first != last) {
            first++;
            ret++;
        }
        return ret;
    }
}



#endif