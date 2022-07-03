#ifndef __UTILS_HPP__
#define __UTILS_HPP__

namespace ft {
    // enable_if =====================================================
    template<bool Cond, typename T = void>
    struct enable_if {};
    template<typename T> 
    struct enable_if<true, T> { typedef T type; };
    // ===============================================================

    // is_integral ===================================================
    template<typename T, bool _bool>
    struct integral_constant  {
        typedef bool value_type;
        typedef T type; // type은 false or true
        static const value_type value = _bool;
    };
    template<typename T>
    struct is_integral : public integral_constant<T, false> {} ; 
	template<>
	struct is_integral<bool> : public integral_constant<bool, true> {} ;
	template<>
	struct is_integral<char> : public integral_constant<char, true> {} ;
	template<>
	struct is_integral<wchar_t> : public integral_constant<wchar_t, true> {} ;
	template<>
	struct is_integral<signed char> : public integral_constant<signed char, true> {} ;
	template<>
	struct is_integral<short int> : public integral_constant<short int, true> {} ;
	template<>
	struct is_integral<int> : public integral_constant<int, true> {} ;
	template<>
	struct is_integral<long int> : public integral_constant<long int, true> {} ;
	template<>
	struct is_integral<long long int> : public integral_constant<long long int, true> {} ;
	template<>
	struct is_integral<unsigned char> : public integral_constant<unsigned char, true> {} ;
	template<>
	struct is_integral<unsigned short int> : public integral_constant<unsigned short int, true> {} ;
	template<>
	struct is_integral<unsigned int> : public integral_constant<unsigned int, true> {} ;
	template<>
	struct is_integral<unsigned long int> : public integral_constant<unsigned long int, true> {} ;
	template<>
	struct is_integral<unsigned long long int> : public integral_constant<unsigned long long, true> {} ;
    // ===============================================================

    // lexicographical_compare========================================
    template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
								InputIterator2 first2, InputIterator2 last2)
	{
		while (first1!=last1)
		{
			if (first2==last2 || *first2<*first1) return false;
			else if (*first1<*first2) return true;
			++first1; ++first2;
		}
		return (first2!=last2);
	}
	//custom (2)	
	template <class InputIterator1, class InputIterator2, class Compare>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
								InputIterator2 first2, InputIterator2 last2,
								Compare comp)
	{
		while (first1 != last1) {
			if (first2 == last2 || comp(*first2, *first1)) return false;
			else if (comp(*first1, *first2)) return true;
			++first1; ++first2;
		}
		return (first2 != last2);
	}
    // ===============================================================

    template <typename A1, typename A2, typename Result>
    struct binary_function
    {
        typedef A1 first_argument_type;
        typedef A2 second_argument_type;
        typedef Result result_type;
    };

	const class t_nullptr
	{
		private:
			void operator&() const;
		public:
			template<typename T>
			operator T*() const
			{
				return 0;
			}
			template<typename T, typename U>
			operator T U::*() const
			{
				return 0;
			}
	} nil = {};
}


#endif