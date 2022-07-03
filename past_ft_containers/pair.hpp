#ifndef __PAIR_HPP__
#define __PAIR_HPP__

#include <iostream>

namespace ft {
	template<typename T1, typename T2>
	struct pair {
		typedef T1 first_type;
		typedef T2 second_type;
		first_type first;
		second_type second;

		// ----- constructor
		pair(): first(first_type()), second(second_type()) { }
		pair(const first_type &a, const second_type &b): first(a), second(b) { }
		template<typename U, typename V> 
		pair(const pair<U, V>& pr): first(pr.first), second(pr.second) { }
		// ----- operator=
		pair& operator=(const pair &pr) {
			first = pr.first;
			second = pr.second;
			return *this;
		}
	};
	// ----- non-member function overload
	template<typename first_type, typename second_type>
	bool operator==(const pair<first_type, second_type>& lhs, const pair<first_type, second_type>& rhs) {
		return lhs.first == rhs.first && lhs.second == rhs.second;
	}
	template<typename first_type, typename second_type>
	bool operator!=(const pair<first_type, second_type>& lhs, const pair<first_type, second_type>& rhs) {
		return !(lhs == rhs);
	}
	template<typename first_type, typename second_type>
	bool operator< (const pair<first_type, second_type>& lhs, const pair<first_type, second_type>& rhs) {
		return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second);
	}
	template<typename first_type, typename second_type>
	bool operator<=(const pair<first_type, second_type>& lhs, const pair<first_type, second_type>& rhs) {
		return !(rhs < lhs);
	}
	template<typename first_type, typename second_type>
	bool operator> (const pair<first_type, second_type>& lhs, const pair<first_type, second_type>& rhs) {
		return rhs < lhs;
	}
	template<typename first_type, typename second_type>
	bool operator>=(const pair<first_type, second_type>& lhs, const pair<first_type, second_type>& rhs) {
		return !(lhs < rhs);
	}
	// ----- make_pair
	template<typename first_type, typename second_type>
	pair<first_type, second_type> make_pair(first_type x, second_type y) {
		return pair<first_type, second_type>(x, y);
	}
}

#endif