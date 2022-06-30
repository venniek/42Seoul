#ifndef __REVERSE_ITERATOR_HPP__
#define __REVERSE_ITERATOR_HPP__

#include "iterator_traits.hpp"

namespace ft
{
    template<typename Iterator>
    class reverse_iterator
    {
    public:
        typedef Iterator iterator_type;
        typedef iterator_traits<Iterator>::iterator_category iterator_category;
        typedef iterator_traits<Iterator>::value_type value_type;
        typedef iterator_traits<Iterator>::difference_type difference_type;
        typedef iterator_traits<Iterator>::pointer pointer;
        typedef iterator_traits<Iterator>::reference reference;
    private:
        iterator_type iterator;
    public:
        // --- constructor, destructor
        reverse_iterator(): iterator(iterator_type()) { }
        explicit reverse_iterator(iterator_type it): iterator(it) { }
        template <typename T>
        reverse_iterator(const reverse_iterator<T> &copy): iterator(copy.base()) { }
        ~reverse_iterator() { }

        // --- member function
        template<typename T>
        reverse_iterator &operator=(const reverse_iterator<T> &ori)
        {
            iterator = ori.base();
            return *this;
        }
        iterator_type base() const
        {
            return iterator;
        }
        reference operator*() const
        {
            iterator_type tmp = iterator;
            return *--tmp;
        }
        reference operator[](difference_type n) const
        {
            return *(*this + n);
        }
        pointer operator->() const
        {
            return &operator*();
        }
        reverse_iterator& operator++()
        {
            --iterator;
            return *this;
        }
        reverse_iterator& operator--()
        {
            ++iterator;
            return *this;
        }
        reverse_iterator& operator++(int)
        {
            reverse_iterator tmp(*this);
            --iterator;
            return tmp;
        }
        reverse_iterator& operator++()
        {
            reverse_iterator tmp(*this);
            ++iterator;
            return tmp;
        }

        // arithmetic operator
        reverse_iteratror operator+(difference_type n) const
        {
            return reverse_iterator(iterator - n);
        }
        reverse_iteratror operator-(difference_type n) const
        {
            return reverse_iterator(iterator + n);
        }
        reverse_iteratror operator+=(difference_type n) const
        {
            iterator -= n;
            return *this;
        }
        reverse_iteratror operator-(difference_type n) const
        {
            iterator += n;
            return *this;
        }
    };

    // non-member function
    template<typename Iterator>
    reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator> &it)
    {
        return reverse_iterator<Iterator>(it.base() - n);
    }
    template<typename It1, typename It2>
    typename reverse_iterator<It1>::difference_type operator-(const reverse_iterator<It1> &it1, const reverse_iterator<It2> &it2)
    {
        return it2.base() - it1.base();
    }
    template<typename It1, typename It2>
    bool operator==(const reverse_iterator<It1> &it1, const reverse_iterator<It2> &it2)
    {
        return it1.base() == it2.base();
    }
    template<typename It1, typename It2>
    bool operator!=(const reverse_iterator<It1> &it1, const reverse_iterator<It2> &it2)
    {
        return it1.base() != it2.base();
    }
    template<typename It1, typename It2>
    bool operator<(const reverse_iterator<It1> &it1, const reverse_iterator<It2> &it2)
    {
        return it1.base() > it2.base();
    }
    template<typename It1, typename It2>
    bool operator<=(const reverse_iterator<It1> &it1, const reverse_iterator<It2> &it2)
    {
        return it1.base() >= it2.base();
    }
    template<typename It1, typename It2>
    bool operator>(const reverse_iterator<It1> &it1, const reverse_iterator<It2> &it2)
    {
        return it1.base() < it2.base();
    }
    template<typename It1, typename It2>
    bool operator>=(const reverse_iterator<It1> &it1, const reverse_iterator<It2> &it2)
    {
        return it1.base() <= it2.base();
    }
}

#endif