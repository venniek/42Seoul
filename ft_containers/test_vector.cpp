#include <vector>
#include <iostream>
#include "vector.hpp"
using namespace std;

int main() {
    vector<int> std_int;
    ft::vector<int> ft_int;
    vector<string> std_str;
    ft::vector<string> ft_str;

    // std_int===========================
    std_int.push_back(1);
    std_int.push_back(2);
    std_int.push_back(3);
    std_int.push_back(4);

    // // cout << "1" << endl;
    // // ft_int============================
    ft_int.push_back(1);
    cout << "2" << endl;
    // ft_int.push_back(2);
    // ft_int.push_back(3);
    // ft_int.push_back(4);

    // // begin
    // cout << "begin: " << endl;
    // cout << "std::begin(): " << *std_int.begin() << endl;
    // cout << "ft::begin(): " << *ft_int.begin() << endl;
    // cout << endl;
    
    // // end
    // cout << "end: " << endl;
    // cout << "std::end(): " << *std_int.end() << endl;
    // cout << "ft::end(): " << *ft_int.end() << endl;
    // cout << endl;
    
    // // rbegin
    // cout << "rbegin: " << endl;
    // cout << "std::rbegin(): " << *std_int.rbegin() << endl;
    // cout << "ft::rbegin(): " << *ft_int.rbegin() << endl;
    // cout << endl;
    
    // // rend
    // cout << "rend: " << endl;
    // cout << "std::rend(): " << *std_int.rend() << endl;
    // cout << "ft::rend(): " << *ft_int.rend() << endl;
    // cout << endl;
    
    // // size
    // cout << "size: " << endl;
    // cout << "std::size(): " << *std_int.size() << endl;
    // cout << "ft::size(): " << *ft_int.size() << endl;
    // cout << endl;
    
    // // max_size
    // cout << "max_size: " << endl;
    // cout << "std::max_size(): " << *std_int.max_size() << endl;
    // cout << "ft::max_size(): " << *ft_int.max_size() << endl;
    // cout << endl;
    
    // // resize
    // cout << "resize: " << endl;
    // cout << "std::resize(): " << *std_int.resize() << endl;
    // cout << "ft::resize(): " << *ft_int.resize() << endl;
    // cout << endl;
    
    // // capacity
    // cout << "capacity: " << endl;
    // cout << "std::capacity(): " << *std_int.capacity() << endl;
    // cout << "ft::capacity(): " << *ft_int.capacity() << endl;
    // cout << endl;
    
    // // empty
    // cout << "empty: " << endl;
    // cout << "std::empty(): " << *std_int.empty() << endl;
    // cout << "ft::empty(): " << *ft_int.empty() << endl;
    // cout << endl;
    
    // // reserve
    // cout << "reserve: " << endl;
    // cout << "std::reserve(): " << *std_int.reserve() << endl;
    // cout << "ft::reserve(): " << *ft_int.reserve() << endl;
    // cout << endl;
    
    // // operator[]
    // cout << "operator[]: " << endl;
    // cout << "std::operator[](): " << *std_int.operator[]() << endl;
    // cout << "ft::operator[](): " << *ft_int.operator[]() << endl;
    // cout << endl;
    
    // // at
    // cout << "at: " << endl;
    // cout << "std::at(): " << *std_int.at() << endl;
    // cout << "ft::at(): " << *ft_int.at() << endl;
    // cout << endl;
    
    // // front
    // cout << "front: " << endl;
    // cout << "std::front(): " << *std_int.front() << endl;
    // cout << "ft::front(): " << *ft_int.front() << endl;
    // cout << endl;
    
    // // back
    // cout << "back: " << endl;
    // cout << "std::back(): " << *std_int.back() << endl;
    // cout << "ft::back(): " << *ft_int.back() << endl;
    // cout << endl;


    // cout << "std_int max_size: " << std_int.max_size() << endl;
    // cout << "ft_int max_size: " << ft_int.max_size() << endl;
    // cout << "std_str max_size: " << std_str.max_size() << endl;
    // cout << "ft_str max_size: " << ft_str.max_size() << endl;
    return 0;
}