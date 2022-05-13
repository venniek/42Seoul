#ifndef __VECTOR_HPP__
#define __VECTOR_HPP__

# include "vector_iter.hpp"

namespace ft {
    template <typename T, typename Alloc = allocator<T> >
    class vector {
    private:
        typedef allocator_type::reference reference;
        typedef allocator_type::const_reference const_reference;
    public:
        explicit vector (const allocator_type& alloc = allocator_type());
        explicit vector (size_type n, const value_type& val = value_type(),
                        const allocator_type& alloc = allocator_type());
        template <class InputIterator>
                    vector (InputIterator first, InputIterator last,
                        const allocator_type& alloc = allocator_type());
        vector (const vector& x);
        ~vector();
        vector& operator=(const vector& x);
    
    iterator begin();
    const_iterator begin() const;

    iterator end();
    const_iterator end() const;

    reverse_iterator rbegin();
    const_reverse_iterator rbegin() const;

    reverse_iterator rend();
    const_reverse_iterator rend() const;



    
    
    
    
    
    
    
    
    
    
    
    }











}







#endif