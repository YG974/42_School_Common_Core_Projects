/* ************************************************************************** */
/* ygeslin                                                                    */
/* VECTOR.HPP                                                                 */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>

namespace ft
{

/* 
 *From https://www.cplusplus.com/reference/vector/vector/
 */
/* ************************************************************************** */
/* TEMPLATE PARAMETERS                                                        */
/* ************************************************************************** */
/*
 * std::vector
 * template < class T, class Alloc = allocator<T> > class vector;
 *
 * 2 Parameters : T and Alloc
 *		T : Type of the elements.
 *			Aliased as member type | vector::value_type |
 *		Alloc : Type of the allocator.
 *			Aliased as member type | vector::allocator_type |
 */

template < class T, class Alloc = std::allocator<T> > 
	class vector
	{

	};// Vector class


/* ************************************************************************** */
/* MEMBER TYPES                                                               */
/* ************************************************************************** */
/* 
 * Value type		: the first template parameter T
 *------------------------------------------------------------------------------
 * Allocator type	: The second template parameter (Alloc)
 * notes :						defaults to: allocator<value_type>
 *------------------------------------------------------------------------------
 * Reference		: allocator_type::reference
 * notes :						for the default allocator: value_type&
 *------------------------------------------------------------------------------
 * Const Reference	: allocator_type::const_reference
 * notes :						for the default allocator: const value_type&
 *------------------------------------------------------------------------------
 * Pointer			: allocator_type::reference 
 * notes :						for the default allocator: value_type*
 *------------------------------------------------------------------------------
 * const_pointer	: allocator_type::const_pointer
 * notes :						for the default allocator: const value_type*
 *------------------------------------------------------------------------------
 * iterator			: a random access iterator to value_type
 * notes :						convertible to const_iterator
 *------------------------------------------------------------------------------
 * const_iterator	: a random access iterator to const value_type	
 *------------------------------------------------------------------------------
 * reverse_iterator	: reverse_iterator<iterator>	
 *------------------------------------------------------------------------------
 * const_reverse_iterator : reverse_iterator<const_iterator>	
 *------------------------------------------------------------------------------
 * difference_type	: a signed integral type, identical to:	
 *					iterator_traits<iterator>::difference_type
 * notes :						usually the same as ptrdiff_t
 *------------------------------------------------------------------------------
 * size_type		: an unsigned integral type that can represent any 
 *					non-negative value of difference_type
 * notes :						usually the same as size_t
 *------------------------------------------------------------------------------
 */

/* ************************************************************************** */
/* MEMBER FUNCTIONS                                                           */
/* ************************************************************************** */
/* 
 *------------------------------------------------------------------------------
 * 4 Constructors : default, fill, range and copy :
 * 
 *------------------------------------------------------------------------------
 * default (1)	:
 * 		explicit vector (const allocator_type& alloc = allocator_type());
 *------------------------------------------------------------------------------
 * fill (2)	:
 *		explicit vector (size_type n, const value_type& val = value_type(),
                 const allocator_type& alloc = allocator_type());
 *------------------------------------------------------------------------------
 * range (3)	:
 *		template <class InputIterator>
 *          vector (InputIterator first, InputIterator last,
 *                  const allocator_type& alloc = allocator_type());
 *------------------------------------------------------------------------------
 * copy (4)		:
 *		vector (const vector& x);
 *------------------------------------------------------------------------------
 *
 */
} // ft namespace

/* USEFULL */
/* https://docs.microsoft.com/en-us/cpp/standard-library/vector-class?view=msvc-160 */
#endif
