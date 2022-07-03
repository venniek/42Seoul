#ifndef __PAIR_HPP__
#define __PAIR_HPP__

namespace ft {
    template<typename T1, typename T2>
    struct pair {
    public:
        typedef T1 first_type;
        typedef T2 second_type;
        first_type first;
        second_type second;

        pair(): first(), second() { }
        pair(const first_type& f, const second_type& s): first(f), second(s) { }
        template<typename U, typename V>
        pair(const pair<U, V> &pr): first(pr.first), second(pr.second) { }
        pair& operator=(const pair &pr) {
            first = p.first;
            second = p.second;
            return *this;
        }
    };

    // relational perators
    template <typename T1, typename T2>
    bool operator==(const pair<T1,T2>& a, const pair<T1,T2>& b) {
        return a.first == b.first && a.second == b.second;
    }
    template <typename T1, typename T2>
    bool operator!=(const pair<T1,T2>& a, const pair<T1,T2>& b) {
        return !(a == b);
    }
    template <typename T1, typename T2>
    bool operator<(const pair<T1,T2>& a, const pair<T1,T2>& b) {
        return a.first < b.first || (!(b.first < a.first) && a.second < b.second);
    }
    template <typename T1, typename T2>
    bool operator<=(const pair<T1,T2>& a, const pair<T1,T2>& b) {
        return !(b < a);
    }
    template <typename T1, typename T2>
    bool operator>(const pair<T1,T2>& a, const pair<T1,T2>& b) {
        return b < a;
    }
    template <typename T1, typename T2>
    bool operator>=(const pair<T1,T2>& a, const pair<T1,T2>& b) {
        return !(a < b);
    }
    template<typename T1, typename T2>
    pair<T1, T2> make_pair(T1 x, T2 y) {
        return pair<T1, T2>(x, y);
    }

}

#endif