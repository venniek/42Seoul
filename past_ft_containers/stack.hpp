#ifndef __STACK_HPP__
#define __STACK_HPP__

#include <iostream>
#include <string>
#include "vector.hpp"

namespace ft
{
    template<typename T, typename Container = ft::vector<T> >
    class stack
    {
    private:
        typedef T value_type;
        typedef Container container_type;
        typedef size_t size_type;

        container_type _ctnr;
    public:
        explicit stack(const container_type& ctnr = container_type()): _ctnr(ctnr) { }
        bool empty() const
        {
            return _ctnr.empty();
        }
        size_type size() const
        {
            return _ctnr.size();
        }
        value_type &top()
        {
            return _ctnr.back();
        }
        const value_type &top() const
        {
            return _ctnr.back();
        }
        void push(const value_type &val)
        {
            _ctnr.push_back(val);
        }
        void pop()
        {
            _ctnr.pop_back();
        }
    };
	template<class T, class Container>
	bool operator==(const ft::stack<T, Container>& left, const ft::stack<T, Container>& right) 
	{
        return (left._ctnr == right._ctnr);
    }
	template<class T, class Container>
	bool operator!=(const ft::stack<T, Container>& left, const ft::stack<T, Container>& right) 
	{
        return (left._ctnr != right._ctnr);
    }
	template<class T, class Container>
	bool operator<(const ft::stack<T, Container>& left, const ft::stack<T, Container>& right) 
	{
        return (left._ctnr < right._ctnr);
    }
	template<class T, class Container>
	bool operator<=(const ft::stack<T, Container>& left, const ft::stack<T, Container>& right) 
	{
        return (left._ctnr <= right._ctnr);
    }
	template<class T, class Container>
	bool operator>(const ft::stack<T, Container>& left, const ft::stack<T, Container>& right) 
	{
        return (left._ctnr > right._ctnr);
    }
	template<class T, class Container>
	bool operator>=(const ft::stack<T, Container>& left, const ft::stack<T, Container>& right) 
	{
        return (left._ctnr >= right._ctnr);
    }
}


#endif