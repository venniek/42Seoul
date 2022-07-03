// #include <vector>
// #include <iostream>
// #include <utility>
// #include "map.hpp"
// #include "pair.hpp"
// #include "utils.hpp"
// #include <map>
// using namespace std;

// int main() {
//     map<int, int> std_int;
//     ft::map<int, int> ft_int;
    
//     // std_int===========================
//     std_int.insert(make_pair(1, 1));
//     std_int.insert(make_pair(2, 2));
//     std_int.insert(make_pair(3, 3));
//     std_int.insert(make_pair(4, 4));

//     // ft_int============================
//     ft_int.insert(ft::make_pair(1, 1));
//     ft_int.insert(ft::make_pair(2, 2));
//     ft_int.insert(ft::make_pair(3, 3));
//     ft_int.insert(ft::make_pair(4, 4));

//     // begin
//     cout << "begin------------" << endl;
//     cout << "std::begin(): " << std_int.begin()->second << endl;
//     cout << "ft::begin(): " << ft_int.begin()->second << endl;
//     cout << endl;
    
//     // rbegin
//     // cout << "rbegin------------" << endl;
//     // cout << "std::rbegin(): " << std_int.rbegin()->second << endl;
//     // cout << "ft::rbegin(): " << ft_int.rbegin()->second << endl;
//     // cout << endl;
    
//     // size
//     cout << "size------------" << endl;
//     cout << "std::size(): " << std_int.size() << endl;
//     cout << "ft::size(): " << ft_int.size() << endl;
//     cout << endl;
    
//     // max_size
//     cout << "max_size------------" << endl;
//     cout << "std::max_size(): " << std_int.max_size() << endl;
//     cout << "ft::max_size(): " << ft_int.max_size() << endl;
//     cout << endl;

//     // empty
//     cout << "empty------------" << endl;
//     cout << "std::empty(): " << std_int.empty() << endl;
//     cout << "ft::empty(): " << ft_int.empty() << endl;
//     cout << endl;

//     // operator[]
//     cout << "operator[]------------" << endl;
//     cout << "std::operator[2]: " << std_int[2] << endl;
//     cout << "ft::operator[2]: " << ft_int[2] << endl;
//     cout << endl;
    
//     // insert
//     cout << "insert------------" << endl;
//     std_int.insert(make_pair(5, 5));
//     ft_int.insert(ft::make_pair(5, 5));
//     cout << "-----------------after insert(begin(), 100)" << endl;
//     cout << "std::size(): " << std_int.size() << endl;
//     cout << "ft::size(): " << ft_int.size() << endl;
//     cout << "std::begin(): " << std_int.begin()->second << endl;
//     cout << "ft::begin(): " << ft_int.begin()->second << endl;
//     cout << endl;
    
//     // erase
//     cout << "erase------------" << endl;
//     cout << "-----------------after erase(end() - 1)" << endl;
//     std_int.erase(std_int.begin());
//     ft_int.erase(ft_int.begin());
//     cout << "std::size(): " << std_int.size() << endl;
//     cout << "ft::size(): " << ft_int.size() << endl;
//     cout << endl;

//     // swap
//     cout << "swap-------------" << endl;
//     ft::map<int, int> ft_swap;
//     cout << "after declare ft_swap" << endl;

//     ft_swap.insert(ft::make_pair(10, 10));
//     ft_swap.insert(ft::make_pair(20, 20));
//     ft_swap.insert(ft::make_pair(30, 30));
//     ft_int.swap(ft_swap);
//     cout << "ft_int.size(): " << ft_int.size() << endl;
//     cout << "ft_swap.size(): " << ft_swap.size() << endl;
//     cout << endl;

//     // clear
//     cout << "clear------------" << endl;
//     std_int.clear();
//     ft_int.clear();
//     cout << "after ft_int.clear()" << endl;
//     cout << "std::size(): " << endl;
//     cout << std_int.size() << endl;
//     cout << "ft::size(): " << ft_int.size() << endl;
//     cout << endl;

//     return 0;
// }

#include "common.hpp"
#include <list>

#define T1 int
#define T2 foo<int>
typedef TESTED_NAMESPACE::map<T1, T2>::value_type T3;
typedef TESTED_NAMESPACE::map<T1, T2>::iterator ft_iterator;
typedef TESTED_NAMESPACE::map<T1, T2>::const_iterator ft_const_iterator;

static int iter = 0;

template <typename MAP>
void	ft_bound(MAP &mp, const T1 &param)
{
	ft_iterator ite = mp.end(), it[2];
	_pair<ft_iterator, ft_iterator> ft_range;

	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	std::cout << "with key [" << param << "]:" << std::endl;
	it[0] = mp.lower_bound(param); it[1] = mp.upper_bound(param);
	ft_range = mp.equal_range(param);
	std::cout << "lower_bound: " << (it[0] == ite ? "end()" : printPair(it[0], false)) << std::endl;
	std::cout << "upper_bound: " << (it[1] == ite ? "end()" : printPair(it[1], false)) << std::endl;
	std::cout << "equal_range: " << (ft_range.first == it[0] && ft_range.second == it[1]) << std::endl;
}

template <typename MAP>
void	ft_const_bound(const MAP &mp, const T1 &param)
{
	ft_const_iterator ite = mp.end(), it[2];
	_pair<ft_const_iterator, ft_const_iterator> ft_range;

	std::cout << "\t-- [" << iter++ << "] (const) --" << std::endl;
	std::cout << "with key [" << param << "]:" << std::endl;
	it[0] = mp.lower_bound(param); it[1] = mp.upper_bound(param);
	ft_range = mp.equal_range(param);
	std::cout << "lower_bound: " << (it[0] == ite ? "end()" : printPair(it[0], false)) << std::endl;
	std::cout << "upper_bound: " << (it[1] == ite ? "end()" : printPair(it[1], false)) << std::endl;
	std::cout << "equal_range: " << (ft_range.first == it[0] && ft_range.second == it[1]) << std::endl;
}

int		main(void)
{
	std::list<T3> lst;
	unsigned int lst_size = 10;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(T3(i + 1, (i + 1) * 3));
	TESTED_NAMESPACE::map<T1, T2> mp(lst.begin(), lst.end());
	printSize(mp);

	ft_const_bound(mp, -10);
	ft_const_bound(mp, 1);
	ft_const_bound(mp, 5);
	ft_const_bound(mp, 10);
	ft_const_bound(mp, 50);

	printSize(mp);

	mp.lower_bound(3)->second = 404;
	mp.upper_bound(7)->second = 842;
	ft_bound(mp, 5);
	ft_bound(mp, 7);

	printSize(mp);
	return (0);
}
