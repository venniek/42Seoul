// #include <map>
// #include <iostream>
// #include "map.hpp"
// using namespace std;

// int main() {
//     map<int, int> std_int;
//     ft::map<int, int> ft_int;

//     // std_int===========================
//     {
//         std_int.insert(make_pair(1, 1));
//         std_int.insert(make_pair(2, 1));
//         std_int.insert(make_pair(3, 1));
//         std_int.insert(make_pair(4, 1));
//     }

//     // ft_int============================
//     ft_int.insert(ft::make_pair(1, 1));
//     ft_int.insert(ft::make_pair(2, 1));
//     ft_int.insert(ft::make_pair(3, 1));
//     ft_int.insert(ft::make_pair(4, 1));

//     // begin, end
//     cout << "begin, end------------" << endl;
// 	for (std::map<int, int>::iterator i = std_int.begin(); i != std_int.end(); i++)
// 		cout << "(" << i->first << ", " << i->second << ") ";
// 	cout << endl;
// 	for (ft::map<int, int>::iterator i = ft_int.begin(); i != ft_int.end(); i++)
// 		cout << "(" << i->first << ", " << i->second << ") ";
// 	cout << endl;
//     cout << endl;
    
//     // // rbegin, rend
//     // cout << "rbegin, rend------------" << endl;
// 	// for (std::map<int, int>::reverse_iterator i = std_int.rend(); i != std_int.rbegin(); i++)
// 	// 	cout << "(" << i->first << ", " << i->second << ") ";
// 	// cout << endl;
// 	// for (ft::map<int, int>::reverse_iterator i = ft_int.rend(); i != ft_int.rbegin(); i++)
// 	// 	cout << "(" << i->first << ", " << i->second << ") ";
// 	// cout << endl;
//     // cout << endl;
    
//     // // empty
//     // cout << "empty------------" << endl;
//     // cout << "std::empty(): " << std_int.empty() << endl;
//     // cout << "ft::empty(): " << ft_int.empty() << endl;
//     // cout << endl;
	
//     // // size
//     // cout << "size------------" << endl;
//     // cout << "std::size(): " << std_int.size() << endl;
//     // cout << "ft::size(): " << ft_int.size() << endl;
//     // cout << endl;
    
//     // // max_size
//     // cout << "max_size------------" << endl;
//     // cout << "std::max_size(): " << std_int.max_size() << endl;
//     // cout << "ft::max_size(): " << ft_int.max_size() << endl;
//     // cout << endl;
    
//     // // operator[]
//     // cout << "operator[]------------" << endl;
//     // cout << "std::operator[2]: " << std_int[2] << endl;
//     // cout << "ft::operator[2]: " << ft_int[2] << endl;
//     // cout << endl;
    
//     // // insert
//     // cout << "insert------------" << endl;
//     // std_int.insert(std_int.begin(), make_pair(100, 100));
//     // ft_int.insert(ft_int.begin(), ft::make_pair(100, 100));
//     // cout << "-----------------after insert(begin(), 100)" << endl;
//     // cout << "std::size(): " << std_int.size() << endl;
//     // cout << "ft::size(): " << ft_int.size() << endl;
//     // cout << endl;
    
//     // // erase
//     // cout << "erase------------" << endl;
//     // cout << "-----------------after erase(end() - 1)" << endl;
//     // std_int.erase(std_int.end() - 1);
//     // ft_int.erase(ft_int.end() - 1);
//     // cout << "std::size(): " << std_int.size() << endl;
//     // cout << "ft::size(): " << ft_int.size() << endl;
//     // cout << "-----------------after erase(begin(), begin() + 3)" << endl;
//     // std_int.erase(std_int.begin(), std_int.begin() + 3);
//     // ft_int.erase(ft_int.begin(), ft_int.begin() + 3);
//     // cout << "std::size(): " << std_int.size() << endl;
//     // cout << "ft::size(): " << ft_int.size() << endl;
//     // cout << endl;

//     // // swap
//     // ft::map<int, int> ft_swap(5, 50);
//     // ft_int.swap(ft_swap);
//     // cout << "swap------------" << endl;
//     // cout << "ft_int::size(): " << ft_int.size() << endl;
//     // cout << "ft_swap::size(): " << ft_swap.size() << endl;
//     // cout << endl;

//     // // clear
//     // cout << "clear------------" << endl;
//     // std_int.clear();
//     // ft_int.clear();
//     // ft_swap.clear();
//     // cout << "std::size(): " << std_int.size() << endl;
//     // cout << "ft::size(): " << ft_int.size() << endl;
//     // cout << endl;

//     return 0;
// }
#include "common.hpp"
#include <list>

#define T1 int
#define T2 int
typedef _pair<const T1, T2> T3;

int		main(void)
{
	std::list<T3> lst;
	std::cout << "1" << std::endl;
	unsigned int lst_size = 7;
	std::cout << "2" << std::endl;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(T3(lst_size - i, i));
	std::cout << "3" << std::endl;

	TESTED_NAMESPACE::map<T1, T2> mp(lst.begin(), lst.end());
	std::cout << "4" << std::endl;
	TESTED_NAMESPACE::map<T1, T2>::iterator it = mp.begin(), ite = mp.end();
	std::cout << "5" << std::endl;

	TESTED_NAMESPACE::map<T1, T2> mp_range(it, --(--ite));
	std::cout << "6" << std::endl;
	for (int i = 0; it != ite; ++it)
		it->second = ++i * 5;
	std::cout << "7" << std::endl;

	it = mp.begin(); ite = --(--mp.end());
	std::cout << "8" << std::endl;
	TESTED_NAMESPACE::map<T1, T2> mp_copy(mp);
	std::cout << "9" << std::endl;
	for (int i = 0; it != ite; ++it)
		it->second = ++i * 7;

	std::cout << "10" << std::endl;
	std::cout << "\t-- PART ONE --" << std::endl;
	printSize(mp);
	printSize(mp_range);
	printSize(mp_copy);

	mp = mp_copy;
	mp_copy = mp_range;
	mp_range.clear();

	std::cout << "\t-- PART TWO --" << std::endl;
	printSize(mp);
	printSize(mp_range);
	printSize(mp_copy);
	return (0);
}
