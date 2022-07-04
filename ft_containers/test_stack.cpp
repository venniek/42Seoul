#include <stack>
#include <iostream>
#include "stack.hpp"
using namespace std;

int main() {
    stack<int> std_int;
    ft::stack<int> ft_int;

    // std_int===========================
    std_int.push(1);
    std_int.push(2);
    std_int.push(3);
    std_int.push(4);

    // ft_int============================
    ft_int.push(1);
    ft_int.push(2);
    ft_int.push(3);
    ft_int.push(4);
    
    // size
    cout << "size------------" << endl;
    cout << "std::size(): " << std_int.size() << endl;
    cout << "ft::size(): " << ft_int.size() << endl;
    cout << endl;
 
    // empty
    cout << "empty------------" << endl;
    cout << "std::empty(): " << std_int.empty() << endl;
    cout << "ft::empty(): " << ft_int.empty() << endl;
    cout << endl;

    // top
    cout << "top------------" << endl;
    cout << "std::top(): " << std_int.top() << endl;
    cout << "ft::top(): " << ft_int.top() << endl;
    cout << endl;
    
    // pop
    cout << "pop------------" << endl;
    std_int.pop();
    ft_int.pop();
    cout << "-----------------after pop()" << endl;
    cout << "std::size(): " << std_int.size() << endl;
    cout << "ft::size(): " << ft_int.size() << endl;
    cout << endl;
    
    // top
    cout << "top------------" << endl;
    cout << "std::top(): " << std_int.top() << endl;
    cout << "ft::top(): " << ft_int.top() << endl;
    cout << endl;

    return 0;
}
