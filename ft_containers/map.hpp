#ifndef __MAP_H__
#define __MAP_H__

#include <iostream>
#include "pair.hpp"

namespace ft {

    template <class T> struct less : binary_function <T,T,bool> {
        bool operator() (const T& x, const T& y) const {return x<y;}
    };

    template< class Key,                                     // map::key_type
           class T,                                       // map::mapped_type
           class Compare = less<Key>,                     // map::key_compare
           class Alloc = std::allocator<ft::pair<const Key,T> >    // map::allocator_type
           >
    class map {
    typedef Key key_type;
    typedef T mapped_type;
    typedef pair<const key_type,mapped_type> value_type;
    typedef Compare key_compare;
    typedef value_compare	value_comp; // 만들자
    typedef Alloc allocator_type;
    typedef typename allocator_type::reference reference;
    typedef typename allocator_type::const_reference	const_reference;
    typedef typename allocator_type::pointer	pointer;
    typedef typename allocator_type::const_pointer const_pointer;

    typedef iterator 
    
    
    
    }
}





#endif