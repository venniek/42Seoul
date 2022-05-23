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

    // ft_int============================
    ft_int.push_back(1);
    ft_int.push_back(2);
    ft_int.push_back(3);
    ft_int.push_back(4);

    // begin
    cout << "begin: " << endl;
    cout << "std::begin(): " << *std_int.begin() << endl;
    cout << "ft::begin(): " << *ft_int.begin() << endl;
    cout << endl;
    
    // // end
    // cout << "end: " << endl;
    // cout << "std::end(): " << *std_int.end() << endl;
    // cout << "ft::end(): " << *ft_int.end() << endl;
    // cout << endl;
    
    // // begin
    // cout << "begin: " << endl;
    // cout << "std::begin(): " << *std_int.begin() << endl;
    // cout << "ft::begin(): " << *ft_int.begin() << endl;
    // cout << endl;
    
    // // begin
    // cout << "begin: " << endl;
    // cout << "std::begin(): " << *std_int.begin() << endl;
    // cout << "ft::begin(): " << *ft_int.begin() << endl;
    // cout << endl;
    
    // // begin
    // cout << "begin: " << endl;
    // cout << "std::begin(): " << *std_int.begin() << endl;
    // cout << "ft::begin(): " << *ft_int.begin() << endl;
    // cout << endl;
    
    // // begin
    // cout << "begin: " << endl;
    // cout << "std::begin(): " << *std_int.begin() << endl;
    // cout << "ft::begin(): " << *ft_int.begin() << endl;
    // cout << endl;
    
    // // begin
    // cout << "begin: " << endl;
    // cout << "std::begin(): " << *std_int.begin() << endl;
    // cout << "ft::begin(): " << *ft_int.begin() << endl;
    // cout << endl;
    
    // // begin
    // cout << "begin: " << endl;
    // cout << "std::begin(): " << *std_int.begin() << endl;
    // cout << "ft::begin(): " << *ft_int.begin() << endl;
    // cout << endl;


    // cout << "std_int max_size: " << std_int.max_size() << endl;
    // cout << "ft_int max_size: " << ft_int.max_size() << endl;
    // cout << "std_str max_size: " << std_str.max_size() << endl;
    // cout << "ft_str max_size: " << ft_str.max_size() << endl;
    return 0;
}