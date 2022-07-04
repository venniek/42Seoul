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
        container_type C_data;
    public:
        explicit stack(const container_type &cntr = container_type()): C_data(cntr) { }
        virtual ~stack() { }

        bool empty() const {
            return C_data.empty();
        }
        size_type size() const {
            return C_data.size();
        }
        value_type& top() {
            return C_data.back();
        }
        const value_type& top() const {
            return C_data.back();
        }
        void push(const value_type &val) {
            C_data.push_back(val);
        }
        void pop() {
            C_data.pop_back();
        }

        // non-member functions
        template <typename nT, typename nContainer>
        friend bool operator==(const ft::stack<nT, nContainer>& lhs, const ft::stack<nT, nContainer>& rhs) {
            return lhs.C_data == rhs.C_data;
        }
        template <typename nT, typename nContainer>
        friend bool operator!=(const ft::stack<nT, nContainer>& lhs, const ft::stack<nT, nContainer>& rhs) {
            return !(lhs == rhs);
        }
        template <typename nT, typename nContainer>
        friend bool operator<(const ft::stack<nT, nContainer>& lhs, const ft::stack<nT, nContainer>& rhs) {
            return lhs.C_data < rhs.C_data;
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