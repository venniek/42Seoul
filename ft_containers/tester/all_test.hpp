#ifndef __TEST_HPP__
#define __TEST_HPP__

#include <iostream>
#include <stack>
#include <map>
#include <vector>
#include "../vector.hpp"
#include "../map.hpp"
#include "../stack.hpp"

#define NC "\e[0m"
#define GRN "\e[0;32m"
#define CYN "\e[0;36m"

# if !defined(USING_FT)
#  define TEST_NAMESPACE std
# else
#  define TEST_NAMESPACE ft
# endif /* !defined(STD) */


void test_vector() {

    std::cout << CYN "=============vector==============" << std::endl;
    std::cout << "=================================" NC << std::endl << std::endl;
    TEST_NAMESPACE::vector<int> v;

    // v===========================
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

    // begin
    std::cout << GRN"begin------------" NC<< std::endl;
    std::cout << "begin(): " << *v.begin() << std::endl;
    std::cout << std::endl;
    
    // end
    std::cout << GRN"end------------" NC<< std::endl;
    std::cout << "end() - 1: " << *(v.end() - 1) << std::endl;
    std::cout << std::endl;
    
    // rbegin
    std::cout << GRN"rbegin------------" NC<< std::endl;
    std::cout << "rbegin(): " << *v.rbegin() << std::endl;
    std::cout << std::endl;
    
    // rend
    std::cout << GRN"rend------------" NC<< std::endl;
    std::cout << "rend() - 1: " << *(v.rend() - 1) << std::endl;
    std::cout << std::endl;
    
    // size
    std::cout << GRN"size------------" NC<< std::endl;
    std::cout << "size(): " << v.size() << std::endl;
    std::cout << std::endl;
    
    // max_size
    std::cout << GRN"max_size------------" NC<< std::endl;
    std::cout << "max_size(): " << v.max_size() << std::endl;
    std::cout << std::endl;
    
    // resize, capacity
    std::cout << GRN"resize------------" NC<< std::endl;
    std::cout << "capacity(): " << v.capacity() << std::endl;
    v.resize(10, 5);
    std::cout << "-----------after resize(10, 5)" << std::endl;
    std::cout << "size(): " << v.size() << std::endl;
    std::cout << "capacity(): " << v.capacity() << std::endl;
    std::cout << std::endl;

    // empty
    std::cout << GRN"empty------------" NC<< std::endl;
    std::cout << "empty(): " << v.empty() << std::endl;
    std::cout << std::endl;
    
    // reserve
    std::cout << GRN"reserve------------" NC<< std::endl;
    v.reserve(100);
    std::cout << "size(): " << v.size() << std::endl;
    std::cout << "capacity(): " << v.capacity() << std::endl;
    std::cout << std::endl;
    
    // operator[]
    std::cout << GRN"operator[]------------" NC<< std::endl;
    std::cout << "operator[2]: " << v[2] << std::endl;
    std::cout << std::endl;
    
    // at
    std::cout << GRN"at------------" NC<< std::endl;
    std::cout << "at(2): " << v.at(2) << std::endl;
    std::cout << std::endl;
    
    // front
    std::cout << GRN"front------------" NC<< std::endl;
    std::cout << "front(): " << v.front() << std::endl;
    std::cout << std::endl;
    
    // back
    std::cout << GRN"back------------" NC<< std::endl;
    std::cout << "back(): " << v.back() << std::endl;
    std::cout << std::endl;
    
    // assign
    std::cout << GRN"assign------------" NC<< std::endl;
    v.assign(50, 5);
    std::cout << "-----------------after assign(50, 5)" << std::endl;
    std::cout << "size(): " << v.size() << std::endl;
    std::cout << std::endl;
    
    // pop_back
    std::cout << GRN"pop_back------------" NC<< std::endl;
    v.pop_back();
    std::cout << "-----------------after pop_back()" << std::endl;
    std::cout << "size(): " << v.size() << std::endl;
    std::cout << std::endl;
    
    // insert
    std::cout << GRN"insert------------" NC<< std::endl;
    v.insert(v.begin(), 100);
    std::cout << "-----------------after insert(begin(), 100)" << std::endl;
    std::cout << "size(): " << v.size() << std::endl;
    std::cout << "begin(): " << *v.begin() << std::endl;
    std::cout << std::endl;
    
    // erase
    std::cout << GRN"erase------------" NC<< std::endl;
    std::cout << "-----------------after erase(end() - 1)" << std::endl;
    v.erase(v.end() - 1);
    std::cout << "size(): " << v.size() << std::endl;
    std::cout << "-----------------after erase(begin(), begin() + 3)" << std::endl;
    v.erase(v.begin(), v.begin() + 3);
    std::cout << "size(): " << v.size() << std::endl;
    std::cout << std::endl;

    // swap
    TEST_NAMESPACE::vector<int> v_swap(5, 50);
    v.swap(v_swap);
    std::cout << GRN"swap------------" NC<< std::endl;
    std::cout << "v::size(): " << v.size() << std::endl;
    std::cout << "v_swap::size(): " << v_swap.size() << std::endl;
    std::cout << std::endl;

    // clear
    std::cout << GRN"clear------------" NC<< std::endl;
    v.clear();
    std::cout << "size(): " << v.size() << std::endl;
    std::cout << std::endl;
}

void test_map() {
    std::cout << CYN "===============map===============" << std::endl;
    std::cout << "=================================" NC << std::endl << std::endl;
    TEST_NAMESPACE::map<int, int> m;

    // m===========================
    m.insert(TEST_NAMESPACE::make_pair(1, 1));
    m.insert(TEST_NAMESPACE::make_pair(2, 1));
    m.insert(TEST_NAMESPACE::make_pair(3, 1));
    m.insert(TEST_NAMESPACE::make_pair(4, 1));

    // begin, end
    std::cout << GRN"begin, end------------" NC<< std::endl;
	for (TEST_NAMESPACE::map<int, int>::iterator i = m.begin(); i != m.end(); i++)
		std::cout << "(" << i->first << ", " << i->second << ") ";
	std::cout << std::endl;
    
    // rbegin, rend
    std::cout << GRN"rbegin, rend------------" NC<< std::endl;
	for (TEST_NAMESPACE::map<int, int>::reverse_iterator i = m.rbegin(); i != m.rend(); i++)
		std::cout << "(" << i->first << ", " << i->second << ") ";
    std::cout << std::endl;
    
    // empty
    std::cout << GRN"empty------------" NC<< std::endl;
    std::cout << "empty(): " << m.empty() << std::endl;
    std::cout << std::endl;
	
    // size
    std::cout << GRN"size------------" NC<< std::endl;
    std::cout << "size(): " << m.size() << std::endl;
    std::cout << std::endl;
    
    // max_size
    std::cout << GRN"max_size------------" NC<< std::endl;
    std::cout << "max_size(): " << m.max_size() << std::endl;
    std::cout << std::endl;
    
    // operator[]
    std::cout << GRN"operator[]------------" NC<< std::endl;
    std::cout << "operator[2]: " << m[2] << std::endl;
    std::cout << std::endl;
    
    // insert
    std::cout << GRN"insert------------" NC<< std::endl;
    std::cout << "-----------------before insert(begin(), {100, 100})" << std::endl;
    std::cout << "size(): " << m.size() << std::endl;
    m.insert(m.begin(), TEST_NAMESPACE::make_pair(100, 100));
    std::cout << "-----------------after insert(begin(), {100, 100})" << std::endl;
    std::cout << "size(): " << m.size() << std::endl;
    std::cout << std::endl;
    
    // erase
    std::cout << GRN"erase------------" NC<< std::endl;
    std::cout << "-----------------after erase(begin())" << std::endl;
    m.erase(m.begin());
    std::cout << "size(): " << m.size() << std::endl;
    std::cout << std::endl;

    // swap
    std::cout << GRN"swap------------" NC<< std::endl;
    TEST_NAMESPACE::map<int, int> m_swap(m.begin(), m.end());
    m_swap.erase(m_swap.begin());
    m_swap.erase(m_swap.begin());
    m_swap.erase(m_swap.begin());
    m.swap(m_swap);
    std::cout << "m::size(): " << m.size() << std::endl;
    std::cout << "m_swap::size(): " << m_swap.size() << std::endl;
    std::cout << std::endl;

    // clear
    std::cout << GRN"clear------------" NC<< std::endl;
    m.clear();
    m_swap.clear();
    std::cout << "size(): " << m.size() << std::endl;
    std::cout << std::endl;

}

void test_stack() {
    std::cout << CYN "==============stack==============" << std::endl;
    std::cout << "=================================" NC << std::endl << std::endl;
    TEST_NAMESPACE::stack<int> s;

    // push============================
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    
    // size
    std::cout << GRN"size------------" NC<< std::endl;
    std::cout << "size(): " << s.size() << std::endl;
    std::cout << std::endl;
 
    // empty
    std::cout << GRN"empty------------" NC<< std::endl;
    std::cout << "empty(): " << s.empty() << std::endl;
    std::cout << std::endl;

    // top
    std::cout << GRN"top------------" NC<< std::endl;
    std::cout << "top(): " << s.top() << std::endl;
    std::cout << std::endl;
    
    // pop
    std::cout << GRN"pop------------" NC<< std::endl;
    s.pop();
    std::cout << "-----------------after pop()" << std::endl;
    std::cout << "size(): " << s.size() << std::endl;
    std::cout << std::endl;
    
    // top
    std::cout << GRN"top------------" NC<< std::endl;
    std::cout << "top(): " << s.top() << std::endl;
    std::cout << std::endl;
}

#endif