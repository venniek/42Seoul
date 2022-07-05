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
// 	std::cout << ft_int.size() << std::endl;
//     ft_int.insert(ft::make_pair(2, 1));
// 	std::cout << ft_int.size() << std::endl;
//     ft_int.insert(ft::make_pair(3, 1));
// 	std::cout << ft_int.size() << std::endl;
//     ft_int.insert(ft::make_pair(4, 1));
// 	std::cout << ft_int.size() << std::endl;

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

#define T1 int
#define T2 std::string
typedef TESTED_NAMESPACE::map<T1, T2>::value_type T3;

static int iter = 0;

template <typename MAP>
void	ft_erase(MAP &mp, const T1 param)
{
	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	mp.erase(param);
	printSize(mp);
}

int		main(void)
{
	TESTED_NAMESPACE::map<T1, T2> mp;

	mp[42] = "c";
	std::cout << mp.begin()->second << std::endl;

	mp[50] = "mdr";
	mp[25] = "funny";

	mp[46] = "bunny";
	mp[21] = "fizz";
	mp[30] = "buzz";
	mp[55] = "fuzzy";

	mp[18] = "bee";
	mp[23] = "coconut";
	mp[28] = "diary";
	mp[35] = "fiesta";
	mp[44] = "hello";
	mp[48] = "world";
	mp[53] = "this is a test";
	mp[80] = "hey";

	mp[12] = "no";
	mp[20] = "idea";
	mp[22] = "123";
	mp[24] = "345";
	mp[27] = "27";
	mp[29] = "29";
	mp[33] = "33";
	mp[38] = "38";

	mp[43] = "1";
	mp[45] = "2";
	mp[47] = "3";
	mp[49] = "4";
	mp[51] = "5";
	mp[54] = "6";
	mp[60] = "7";
	mp[90] = "8";

	printSize(mp);

	/* A classic btree should give this:
	 *                                      42
	 *                     /                                            \
	 *                    25                                            50
	 *           /                 \                         /                       \
	 *          21                 30                       46                       55
	 *      /       \           /      \                /       \             /           \
	 *     18       23        28        35            44         48         53             80
	 *   /   \    /    \    /    \     /   \        /   \       /   \     /    \         /     \
	 *  12   20  22    24  27    29  33    38     43    45    47    49   51    54       60      90
	 *
	 * */

	ft_erase(mp, 25); // right != NULL; left != NULL
	ft_erase(mp, 55); // right != NULL; left != NULL

	/* After deleting 25 and 55, I would get:
	 *                                      42
	 *                     /                                            \
	 *                    24                                            50
	 *           /                 \                         /                      \
	 *          21                 30                       46                      54
	 *      /       \           /      \                /       \             /           \
	 *     18       23        28        35            44         48         53             80
	 *   /   \    /         /    \     /   \        /   \       /   \     /              /     \
	 *  12   20  22        27    29  33    38     43    45    47    49   51             60      90
	 *
	 * */

	ft_erase(mp, 24); // right != NULL; left != NULL
	ft_erase(mp, 54); // right != NULL; left != NULL

	/* After deleting 24 and 54, I would get:
	 *                                      42
	 *                     /                                            \
	 *                    23                                            50
	 *           /                 \                         /                      \
	 *          21                 30                       46                      53
	 *      /       \           /      \                /       \             /           \
	 *     18       22        28        35            44         48         51             80
	 *   /   \              /    \     /   \        /   \       /   \                    /     \
	 *  12   20            27    29  33    38     43    45    47    49                  60      90
	 *
	 * */

	ft_erase(mp, 22); // right == NULL; left == NULL
	ft_erase(mp, 51); // right == NULL; left == NULL

	ft_erase(mp, 21); // right == NULL; left != NULL
	ft_erase(mp, 53); // right != NULL; left == NULL

	/* After deleting 22, 51 and then 21, 53, I would get:
	 *                                      42
	 *                     /                                            \
	 *                    23                                            50
	 *           /                 \                         /                      \
	 *          20                 30                       46                      80
	 *      /                   /      \                /       \                /        \
	 *     18                 28        35            44         48             60         90
	 *   /                  /    \     /   \        /   \       /   \
	 *  12                 27    29  33    38     43    45    47    49
	 *
	 * */

	ft_erase(mp, 20); // right == NULL; left != NULL

	/* After deleting 20, I would get:
	 *                                      42
	 *                     /                                            \
	 *                    23                                            50
	 *           /                 \                         /                      \
	 *          18                 30                       46                      80
	 *      /                   /      \                /       \                /        \
	 *     12                 28        35            44         48             60         90
	 *                      /    \     /   \        /   \       /   \
	 *                     27    29  33    38     43    45    47    49
	 *
	 * */

	ft_erase(mp, 23); // right != NULL; left != NULL

	/* After deleting 23, I would get:
	 *                                      42
	 *                     /                                            \
	 *                    18                                            50
	 *           /                 \                         /                      \
	 *          12                 30                       46                      80
	 *                          /      \                /       \                /        \
	 *                        28        35            44         48             60         90
	 *                      /    \     /   \        /   \       /   \
	 *                     27    29  33    38     43    45    47    49
	 *
	 * */

	ft_erase(mp, 42); // right != NULL; left != NULL; parent == NULL

	/* After deleting 42, I would get:
	 *                                      38
	 *                     /                                            \
	 *                    18                                            50
	 *           /                 \                         /                      \
	 *          12                 30                       46                      80
	 *                          /      \                /       \                /        \
	 *                        28        35            44         48             60         90
	 *                      /    \     /            /   \       /   \
	 *                     27    29  33           43    45    47    49
	 *
	 * */

	ft_erase(mp, 38); // right != NULL; left != NULL; parent == NULL

	/* After deleting 38, I would get:
	 *                                      35
	 *                     /                                            \
	 *                    18                                            50
	 *           /                 \                         /                      \
	 *          12                 30                       46                      80
	 *                          /      \                /       \                /        \
	 *                        28        33            44         48             60         90
	 *                      /    \                  /   \       /   \
	 *                     27    29               43    45    47    49
	 *
	 * */

	ft_erase(mp, 35); // right != NULL; left != NULL; parent == NULL

	/* After deleting 35, I would get:
	 *                                      33
	 *                     /                                            \
	 *                    18                                            50
	 *           /                 \                         /                      \
	 *          12                 30                       46                      80
	 *                          /                       /       \                /        \
	 *                        28                      44         48             60         90
	 *                      /    \                  /   \       /   \
	 *                     27    29               43    45    47    49
	 *
	 * */

	ft_erase(mp, 33); // right != NULL; left != NULL; parent == NULL

	/* After deleting 33, I would get:
	 *                                      30
	 *                     /                                            \
	 *                    18                                            50
	 *           /                 \                         /                      \
	 *          12                 28                       46                      80
	 *                          /      \                /       \                /        \
	 *                        27       29             44         48             60         90
	 *                                              /   \       /   \
	 *                                            43    45    47    49
	 *
	 * */

	return (0);
}
