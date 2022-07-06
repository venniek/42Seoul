#ifndef __STACK_HPP__
#define __STACK_HPP__

# include <iostream>
# include <string>
# include "vector.hpp"

namespace ft {
    template<typename T, typename Container = ft::vector<T> >
    class stack {
    public:
        typedef T value_type;
        typedef Container container_type;
        typedef size_t size_type;
    protected:
        container_type c;
    public:
        explicit stack(const container_type &cntr = container_type()): c(cntr) { }
        virtual ~stack() { }

        bool empty() const {
            return c.empty();
        }
        size_type size() const {
            return c.size();
        }
        value_type& top() {
            return c.back();
        }
        const value_type& top() const {
            return c.back();
        }
        void push(const value_type &val) {
            c.push_back(val);
        }
        void pop() {
            c.pop_back();
        }

        // non-member functions
        template <typename nT, typename nContainer>
        friend bool operator==(const ft::stack<nT, nContainer>& lhs, const ft::stack<nT, nContainer>& rhs) {
            return lhs.c == rhs.c;
        }
        template <typename nT, typename nContainer>
        friend bool operator!=(const ft::stack<nT, nContainer>& lhs, const ft::stack<nT, nContainer>& rhs) {
            return !(lhs == rhs);
        }
        template <typename nT, typename nContainer>
        friend bool operator<(const ft::stack<nT, nContainer>& lhs, const ft::stack<nT, nContainer>& rhs) {
            return lhs.c < rhs.c;
        }
        template <typename nT, typename nContainer>
        friend bool operator<=(const ft::stack<nT, nContainer>& lhs, const ft::stack<nT, nContainer>& rhs) {
            return !(rhs < lhs);
        }
        template <typename nT, typename nContainer>
        friend bool operator>(const ft::stack<nT, nContainer>& lhs, const ft::stack<nT, nContainer>& rhs) {
            return rhs < lhs;
        }
        template <typename nT, typename nContainer>
        friend bool operator>=(const ft::stack<nT, nContainer>& lhs, const ft::stack<nT, nContainer>& rhs) {
            return !(lhs < rhs);
        }
    };
}


#endif