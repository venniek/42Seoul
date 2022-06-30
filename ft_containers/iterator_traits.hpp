#ifndef __ITER_TRAITS_HPP__   
#define __ITER_TRAITS_HPP__   

#include <iterator>

namespace ft
{
    template<typename iterator>
    struct iterator_traits {
        typedef typename iterator::value_type value_type;
        typedef typename iterator::difference_type difference_type;
        typedef typename iterator::pointer pointer;
        typedef typename iterator::reference reference;
        typedef typename iterator::iterator_category iterator_category;
    };
    
    template<typename T>
    struct iterator_traits<T*> {
        typedef T value_type;
        typedef T* pointer;
        typedef T& reference;
        typedef std::ptrdiff_t difference_type;
        typedef std::random_access_iterator_tag iterator_category;
    };

    template<typename T>
    struct iterator_traits<const T*> {
        typedef T value_type;
        typedef const T* pointer;
        typedef const T& reference;
        typedef ptrdiff_t difference_type;
        typedef std::random_access_iterator_tag iterator_category;
    };
}


#endif