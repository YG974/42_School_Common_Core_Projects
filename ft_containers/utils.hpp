/* ************************************************************************** */
/* ygeslin                                                                    */
/* utils.hpp                                                                  */
/* ************************************************************************** */
#include <memory>
#include <cstddef>	//for ptrdiff_t

#ifndef UTILS_HPP
#define UTILS_HPP


namespace ft
{

	// SFINAE, to find the good overload
	/* https://en.cppreference.com/w/cpp/types/enable_if */
	template<bool B, class T = void>
		struct enable_if {};

	template<class T>
		struct enable_if<true, T> { typedef T type; };

	// To use enable if, to know if it's an iterator/pointer or not
	/* https://en.cppreference.com/w/cpp/types/is_integral */
	/* https://www.cplusplus.com/reference/type_traits/is_integral/ */
	template <class T>
		struct is_integral
		{ static const bool value = false;};

	template <>
		struct is_integral<bool>
		{ static const bool value = true; };

	template <>
		struct is_integral<char>
		{ static const bool value = true; };

	template <>
		struct is_integral<short int>
		{ static const bool value = true; };

	template <>
		struct is_integral<int>
		{ static const bool value = true; };

	template <>
		struct is_integral<long int>
		{ static const bool value = true; };

	template <>
		struct is_integral<long long int>
		{ static const bool value = true; };

	template <>
		struct is_integral<unsigned char>
		{ static const bool value = true; };

	template <>
		struct is_integral<unsigned short int>
		{ static const bool value = true; };

	template <>
		struct is_integral<unsigned int>
		{ static const bool value = true; };

	template <>
		struct is_integral<unsigned long int>
		{ static const bool value = true; };

	template <>
		struct is_integral<unsigned long long int>
		{ static const bool value = true; };

	/* lexicographical_compare */
	template <class InputIterator, class InputIterator2>
		bool lexicographical_compare(InputIterator first1, InputIterator last1,
				InputIterator2 first2, InputIterator2 last2)
		{
			while (first1 != last1)
			{
				if (first2 == last2 || *first2 < *first1)
					return false;
				else if (*first1 < *first2)
					return true;
				++first1;
				++first2;
			}
			return (first2 != last2);
		}
	

	template <class InputIterator, class InputIterator2, class Compare>
		bool lexicographical_compare(InputIterator first1, InputIterator last1,
				InputIterator2 first2, InputIterator2 last2,
				Compare comp)
		{
			while (first1 != last1)
			{
				if (first2 == last2 || comp(*first2, *first1))
					return false;
				else if (comp(*first1, *first2))
					return true;
				++first1;
				++first2;
			}
			return (first2 != last2);
		}


} // ft namespace

/* USEFULL */
#endif
