#include <vector>
#include <iostream>
#include <utility>
#include "map.hpp"
#include "pair.hpp"
#include "utils.hpp"
#include <map>
using namespace std;

int main() {
    map<int, int> std_int;
	std::cout << "after make map<int, int> std_int" << std::endl;
    ft::map<int, int> ft_int;
    std::cout << "after make ft::map<int, int> ft_int" << std::endl;

    // std_int===========================
    std_int.insert(make_pair(1, 1));
    std_int.insert(make_pair(2, 2));
    std_int.insert(make_pair(3, 3));
    std_int.insert(make_pair(4, 4));

    // ft_int============================
    ft_int.insert(ft::make_pair(1, 1));
    std::cout << "after insert (1, 1)" << std::endl;
    ft_int.insert(ft::make_pair(2, 2));
    std::cout << "after insert (2, 2)" << std::endl;
    ft_int.insert(ft::make_pair(3, 3));
    std::cout << "after insert (3, 3)" << std::endl;
    ft_int.insert(ft::make_pair(4, 4));
    std::cout << "after insert (4, 4)" << std::endl;

    // begin
    cout << "begin------------" << endl;
    cout << "std::begin(): " << std_int.begin()->second << endl;
    cout << "ft::begin(): " << ft_int.begin()->second << endl;
    cout << endl;
    
    // rbegin
    // cout << "rbegin------------" << endl;
    // cout << "std::rbegin(): " << std_int.rbegin()->second << endl;
    // cout << "ft::rbegin(): " << ft_int.rbegin()->second << endl;
    // cout << endl;
    
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

    // empty
    cout << "empty------------" << endl;
    cout << "std::empty(): " << std_int.empty() << endl;
    cout << "ft::empty(): " << ft_int.empty() << endl;
    cout << endl;

    // operator[]
    cout << "operator[]------------" << endl;
    cout << "std::operator[2]: " << std_int[2] << endl;
    cout << "ft::operator[2]: " << ft_int[2] << endl;
    cout << endl;
    
    // insert
    cout << "insert------------" << endl;
    std_int.insert(make_pair(5, 5));
    ft_int.insert(ft::make_pair(5, 5));
    cout << "-----------------after insert(begin(), 100)" << endl;
    cout << "std::size(): " << std_int.size() << endl;
    cout << "ft::size(): " << ft_int.size() << endl;
    cout << "std::begin(): " << std_int.begin()->second << endl;
    cout << "ft::begin(): " << ft_int.begin()->second << endl;
    cout << endl;
    
    // erase
    cout << "erase------------" << endl;
    cout << "-----------------after erase(end() - 1)" << endl;
    std_int.erase(std_int.begin());
    ft_int.erase(ft_int.begin());
    cout << "std::size(): " << std_int.size() << endl;
    cout << "ft::size(): " << ft_int.size() << endl;
    cout << endl;

    // swap
    cout << "swap-------------" << endl;
    ft::map<int, int> ft_swap;
    cout << "after declare ft_swap" << endl;

    ft_swap.insert(ft::make_pair(10, 10));
    ft_swap.insert(ft::make_pair(20, 20));
    ft_swap.insert(ft::make_pair(30, 30));
    ft_int.swap(ft_swap);
    cout << "ft_int.size(): " << ft_int.size() << endl;
    cout << "ft_swap.size(): " << ft_swap.size() << endl;
    cout << endl;

    // clear
    cout << "clear------------" << endl;
    std_int.clear();
    ft_int.clear();
    cout << "std::size(): " << std_int.size() << endl;
    cout << "ft::size(): " << ft_int.size() << endl;
    cout << endl;

    return 0;
}