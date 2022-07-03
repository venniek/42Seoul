#include <vector>
#include <iostream>
#include "vector.hpp"
using namespace std;

int main() {
    vector<int> std_int;
    ft::vector<int> ft_int;
    // vector<string> std_str;
    // ft::vector<string> ft_str;

    // std_int===========================
    {
        std_int.push_back(1);
        std_int.push_back(2);
        std_int.push_back(3);
        std_int.push_back(4);
    }

    // ft_int============================
    ft_int.push_back(1);
    ft_int.push_back(2);
    ft_int.push_back(3);
    ft_int.push_back(4);

    // begin
    cout << "begin------------" << endl;
    cout << "std::begin(): " << *std_int.begin() << endl;
    cout << "ft::begin(): " << *ft_int.begin() << endl;
    cout << endl;
    
    // end
    cout << "end------------" << endl;
    cout << "std::end() - 1: " << *(std_int.end() - 1) << endl;
    cout << "ft::end() - 1: " << *(ft_int.end() - 1) << endl;
    cout << endl;
    
    // rbegin
    cout << "rbegin------------" << endl;
    cout << "std::rbegin(): " << *std_int.rbegin() << endl;
    cout << "ft::rbegin(): " << *ft_int.rbegin() << endl;
    cout << endl;
    
    // rend
    cout << "rend------------" << endl;
    cout << "std::rend() - 1: " << *(std_int.rend() - 1) << endl;
    cout << "ft::rend() - 1: " << *(ft_int.rend() - 1) << endl;
    cout << endl;
    
    // size
    cout << "size------------" << endl;
    cout << "std::size(): " << std_int.size() << endl;
    cout << "ft::size(): " << ft_int.size() << endl;
    cout << endl;
    
    // max_size
    cout << "max_size------------" << endl;
    cout << "std::max_size(): " << std_int.max_size() << endl;
    cout << "ft::max_size(): " << ft_int.max_size() << endl;
    cout << endl;
    
    // resize, capacity
    cout << "resize------------" << endl;
    cout << "std::capacity(): " << std_int.capacity() << endl;
    cout << "ft::capacity(): " << ft_int.capacity() << endl;
    std_int.resize(10, 5);
    ft_int.resize(10, 5);
    cout << "-----------after resize(10, 5)" << endl;
    cout << "std::size(): " << std_int.size() << endl;
    cout << "std::capacity(): " << std_int.capacity() << endl;
    cout << "ft::size(): " << ft_int.size() << endl;
    cout << "ft::capacity(): " << ft_int.capacity() << endl;
    cout << endl;

    // empty
    cout << "empty------------" << endl;
    cout << "std::empty(): " << std_int.empty() << endl;
    cout << "ft::empty(): " << ft_int.empty() << endl;
    cout << endl;
    
    // reserve
    cout << "reserve------------" << endl;
    std_int.reserve(100);
    ft_int.reserve(100);
    cout << "std::size(): " << std_int.size() << endl;
    cout << "std::capacity(): " << std_int.capacity() << endl;
    cout << "ft::size(): " << ft_int.size() << endl;
    cout << "ft::capacity(): " << ft_int.capacity() << endl;
    cout << endl;
    
    // operator[]
    cout << "operator[]------------" << endl;
    cout << "std::operator[2]: " << std_int[2] << endl;
    cout << "ft::operator[2]: " << ft_int[2] << endl;
    cout << endl;
    
    // at
    cout << "at------------" << endl;
    cout << "std::at(2): " << std_int.at(2) << endl;
    cout << "ft::at(2): " << ft_int.at(2) << endl;
    cout << endl;
    
    // front
    cout << "front------------" << endl;
    cout << "std::front(): " << std_int.front() << endl;
    cout << "ft::front(): " << ft_int.front() << endl;
    cout << endl;
    
    // back
    cout << "back------------" << endl;
    cout << "std::back(): " << std_int.back() << endl;
    cout << "ft::back(): " << ft_int.back() << endl;
    cout << endl;
    
    // assign
    cout << "assign------------" << endl;
    std_int.assign(50, 5);
    ft_int.assign(50, 5);
    cout << "-----------------after assign(50, 5)" << endl;
    cout << "std::size(): " << std_int.size() << endl;
    cout << "ft::size(): " << ft_int.size() << endl;
    cout << endl;
    
    // pop_back
    cout << "pop_back------------" << endl;
    std_int.pop_back();
    ft_int.pop_back();
    cout << "-----------------after pop_back()" << endl;
    cout << "std::size(): " << std_int.size() << endl;
    cout << "ft::size(): " << ft_int.size() << endl;
    cout << endl;
    
    // insert
    cout << "insert------------" << endl;
    std_int.insert(std_int.begin(), 100);
    ft_int.insert(ft_int.begin(), 100);
    cout << "-----------------after insert(begin(), 100)" << endl;
    cout << "std::size(): " << std_int.size() << endl;
    cout << "ft::size(): " << ft_int.size() << endl;
    cout << "std::begin(): " << *std_int.begin() << endl;
    cout << "ft::begin(): " << *ft_int.begin() << endl;
    cout << endl;
    
    // erase
    cout << "erase------------" << endl;
    cout << "-----------------after erase(end() - 1)" << endl;
    std_int.erase(std_int.end() - 1);
    ft_int.erase(ft_int.end() - 1);
    cout << "std::size(): " << std_int.size() << endl;
    cout << "ft::size(): " << ft_int.size() << endl;
    cout << "-----------------after erase(begin(), begin() + 3)" << endl;
    std_int.erase(std_int.begin(), std_int.begin() + 3);
    ft_int.erase(ft_int.begin(), ft_int.begin() + 3);
    cout << "std::size(): " << std_int.size() << endl;
    cout << "ft::size(): " << ft_int.size() << endl;
    cout << endl;

    // swap
    ft::vector<int> ft_swap(5, 50);
    ft_int.swap(ft_swap);
    cout << "swap------------" << endl;
    cout << "ft_int::size(): " << ft_int.size() << endl;
    cout << "ft_swap::size(): " << ft_swap.size() << endl;
    cout << endl;

    // clear
    cout << "clear------------" << endl;
    std_int.clear();
    ft_int.clear();
    ft_swap.clear();
    cout << "std::size(): " << std_int.size() << endl;
    cout << "ft::size(): " << ft_int.size() << endl;
    cout << endl;

    return 0;
}