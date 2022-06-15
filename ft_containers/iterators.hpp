/* ************************************************************************** */
/* ygeslin                                                                    */
/* ITERATOR.HPP                                                                 */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

/* #include <memory> */
#include <cstddef>	//for ptrdiff_t
#include <iterator>
#include "utils.hpp"

namespace ft
{
	/* http://www.lirmm.fr/~ducour/Doc-objets/ISO+IEC+14882-1998.pdf */
	/* page 514 */
	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag : public input_iterator_tag {};
	struct bidirectional_iterator_tag : public forward_iterator_tag {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};

	/* page 518 */
	template< class Category, class T, class Distance = ptrdiff_t,
		class Pointer = T*, class Reference = T& >
			class iterator {
				public :
				typedef T         value_type;
				typedef Distance  difference_type;
				typedef Pointer   pointer;
				typedef Reference reference;
				typedef Category  iterator_category;
			};

	/* https://cplusplus.com/reference/iterator/iterator_traits/ */
	template < typename Iterator >
		class iterator_traits
		{
			public :
				typedef typename Iterator::value_type		value_type;
				typedef typename Iterator::difference_type	difference_type;
				typedef typename Iterator::pointer			pointer;
				typedef typename Iterator::reference		reference;
				typedef typename Iterator::iterator_category iterator_category;
		};

	template < class T >
		class iterator_traits< T* >
		{
			public :
				typedef T								value_type;
				typedef std::ptrdiff_t					difference_type;
				typedef T*								pointer;
				typedef T&								reference;
				typedef ft::random_access_iterator_tag 		iterator_category;
		};

	template < class T >
		class iterator_traits< const T* >
			{
			public :
				typedef T								value_type;
				typedef std::ptrdiff_t					difference_type;
				typedef const T*						pointer;
				typedef const T&						reference;
				typedef ft::random_access_iterator_tag 		iterator_category;
		};

	template < class Iterator >
		class rai : ft::iterator < random_access_iterator_tag, Iterator >
	{
		public :
			/* typedef Iterator	iterator_type; */
			typedef typename ft::iterator < ft::random_access_iterator_tag, Iterator >::value_type			value_type;
			typedef typename ft::iterator < ft::random_access_iterator_tag, Iterator >::difference_type		difference_type;
			typedef typename ft::iterator < ft::random_access_iterator_tag, Iterator >::pointer				pointer;
			typedef typename ft::iterator < ft::random_access_iterator_tag, Iterator >::reference			reference;
			typedef typename ft::iterator < ft::random_access_iterator_tag, Iterator >::iterator_category	iterator_category;
		
		private :
			pointer									_ptr;

		public :
			/* COPLIEN FORM */

			/* Default constructor */
			rai ( void )
				: _ptr( 0 )
			{ return ; };

			/* 1 param constructor */
			rai ( pointer ptr )
				: _ptr( ptr )
			{ return ; };

			// copy constructor
			rai ( const rai & lhs )
				: _ptr ( lhs._ptr )
			{ return ; };

			/* pointer base() const { return _ptr; } */

			/* To build a const Iterator from a regular iterator */
			operator rai < const value_type >() const
			{ return ( rai < const value_type > (_ptr) ); }

			/* copy constructor */
			// Use a getter to initialize the value, without a get, we should 
			// have assign the value inside the function, unoptimal,
			// it's better to initialize
			/* rai ( const rai< Iterator > & lhs_iterator ) */
			/* 	: _ptr( lhs_iterator.get_iterator_ptr() ) */
			/* { return ; }; */

			/* destructor */
			~rai ( void )
			{ return ; };

			/* assignation operator " = " */
			rai & operator = ( const rai & lhs_vector )
			{
				/* if (*this == lhs_vector) */
				/* 	return (*this); */
				_ptr = lhs_vector._ptr;
				return (*this);
			}

			/* GETTER */
			/* useful to initialise copy constructor */
			pointer get_iterator_ptr ( void ) const
			{ return ( _ptr ); }

			/* https://www.cplusplus.com/doc/tutorial/operators/ */
			/* OPERATORS */

			/* https://www.cplusplus.com/reference/iterator/RandomAccessIterator/ */
			/* random access iterator valid operations */

			/* Can be compared for equivalence using the equality/inequality operators */
			/* (meaningful when both iterator values iterate over the same underlying sequence). */

			/* a == b */
			bool operator == ( const rai & lhs_vector ) const
			{ return ( this->_ptr == lhs_vector._ptr ); }

			/* a != b */
			bool operator != ( const rai & lhs_vector ) const
			{ return ( this->_ptr != lhs_vector._ptr ); }

			/* Can be dereferenced as an rvalue (if in a dereferenceable state). */

			/*  *a  */
			reference operator * ( void ) const
			{ return ( *this->_ptr ); }

			/* a->m */
			pointer operator -> ( void ) const
			{
				return &(this->operator*());
				/* return ( *this->_ptr ); */
			}

			/* For mutable iterators (non-constant iterators): */
			/* Can be dereferenced as an lvalue (if in a dereferenceable state). */

			/* *a = t */
			/* OK -> addition de 2 overloads */ 

			/* Can be incremented (if in a dereferenceable state). */
			/* The result is either also dereferenceable or a past-the-end iterator. */
			/* Two iterators that compare equal, keep comparing equal after being both increased. */

			/* ++a */
			rai & operator ++ ( void )
			{
				this->_ptr++;
				return ( *this );
			}

			/* a++ */
			rai operator ++ ( int )
			{
				rai tmp = (*this);
				operator++();
				/* ++(*this); */
				return ( tmp );
			}

			/* *a++ */
			/* OK -> addition de 2 overloads */ 

			/* Can be decremented (if a dereferenceable iterator value precedes it). */

			/* --a */
			rai & operator -- ( void )
			{
				this->_ptr--;
				return ( *this );
			}

			/* a-- */
			rai operator -- ( int )
			{
				rai tmp = (*this);
				operator--();
				/* --(*this); */
				return ( tmp );
			}

			/* *a-- */
			/* OK -> addition de 2 overloads */ 

			/* Supports the arithmetic operators + and - between an iterator and an integer */ 
			/* value, or subtracting an iterator from another.  */

			/* a + n */
			rai operator + (const difference_type n ) const
			{ return _ptr + n; }

			/* n + a */
			difference_type operator + ( rai a )
			{ return ( this->_ptr + a._ptr ); }

			/* a - n */
			rai operator - ( difference_type n ) const
			{ return _ptr - n; }

			/* a - b */
			difference_type operator - (rai b) const
			{ return ( this->_ptr - b._ptr ); }

			difference_type operator - (const rai & rhs)
			{ return ( _ptr - rhs._ptr ); }

			/* Can be compared with inequality relational operators (<, >, <= and >=). */

			/* a < b */
			bool operator < ( const rai & lhs_vector ) const
			{ return (this->_ptr < lhs_vector._ptr ); }

			/* a > b */
			bool operator > ( const rai & lhs_vector ) const
			{ return (this->_ptr > lhs_vector._ptr ); }

			/* a <= b */
			bool operator <= ( const rai & lhs_vector ) const
			{ return (this->_ptr <= lhs_vector._ptr ); }

			/* a >= b */
			bool operator >= ( const rai & lhs_vector ) const
			{ return (this->_ptr >= lhs_vector._ptr ); }

			/* Supports compound assignment operations += and -= */

			/* a += n */
			rai & operator += ( const difference_type n )
			{
				this->_ptr += n;
				return ( *this );
			}

			/* a -= n */
			rai & operator -= ( difference_type n )
			{
				this->_ptr -= n;
				return ( *this );
			}

			/* Supports the offset dereference operator ([]) */

			/* a[n] */
			reference operator [] ( difference_type n ) const
			{ return ( this->_ptr[n] ); }

			/* friend rai < Iterator >	operator+(difference_type n, const rai & lhs) */
			/* { */ 
			/* 	return lhs._ptr + n; */
			/* }; */
			/* friend rai operator + (difference_type n, rai & lhs) */
			/* { */

			/* } */

			/* d'apres ce site pas de operator[] pour les random_access_iterator_tag */
			/* https://docs.microsoft.com/fr-fr/cpp/standard-library/iterator-operators?view=msvc-160 */
	}; // random_access_iterator rai

	// ft::distance
	template <class InputIterator>
		typename iterator_traits<InputIterator>::difference_type
		distance (InputIterator first, InputIterator last)
		{
			typename iterator_traits<InputIterator>::difference_type i = 0;
			for (i = 0 ; first != last ; ++first, ++i);
			return i;
		}

	/* non-member overloads */

	/* coparison bool */

	/* == */
	/* template < class Iterator > */
	/* 	bool operator == ( const ft::rai<Iterator> & lhs, const ft::rai<Iterator> & rhs ) */
	/* 	{ return ( lhs == rhs ); } */

	template < class Iterator1, class Iterator2 >
		bool operator == (const ft::rai<Iterator1>  lhs, const ft::rai<Iterator2>  rhs )
		{ return ( lhs.get_iterator_ptr() == rhs.get_iterator_ptr() ) ; }

	/* > */
	/* template < class Iterator > */
	/* 	bool operator > ( const rai<Iterator> & lhs, const rai<Iterator> & rhs ) */
	/* 	{ return ( lhs > rhs ); } */

	template < class Iterator1, class Iterator2 >
		bool operator > (const ft::rai<Iterator1>  lhs, const ft::rai<Iterator2>  rhs )
		{ return ( lhs.get_iterator_ptr() > rhs.get_iterator_ptr() ) ; }

	/* >= */
	/* template < class Iterator > */
	/* 	bool operator >= ( const rai<Iterator> & lhs, const rai<Iterator> & rhs ) */
	/* 	{ return ( lhs >= rhs ); } */

	template < class Iterator1, class Iterator2 >
		bool operator >= (const ft::rai<Iterator1>  lhs, const ft::rai<Iterator2>  rhs )
		{ return ( lhs.get_iterator_ptr() >= rhs.get_iterator_ptr() ) ; }

	/* < */
	/* template < class Iterator > */
	/* 	bool operator < ( const rai<Iterator> & lhs, const rai<Iterator> & rhs ) */
	/* 	{ return ( lhs < rhs ); } */

	template < class Iterator1, class Iterator2 >
		bool operator < (const ft::rai<Iterator1>  lhs, const ft::rai<Iterator2>  rhs )
		{ return ( lhs.get_iterator_ptr() < rhs.get_iterator_ptr() ) ; }

	/* <= */
	/* template < class Iterator > */
	/* 	bool operator <= ( const rai<Iterator> & lhs, const rai<Iterator> & rhs ) */
	/* 	{ return ( lhs <= rhs ); } */

	template < class Iterator1, class Iterator2 >
		bool operator <= (const ft::rai<Iterator1>  lhs, const ft::rai<Iterator2>  rhs )
		{ return ( lhs.get_iterator_ptr() <= rhs.get_iterator_ptr() ) ; }

	/* != */
	/* template < class Iterator > */
	/* 	bool operator != ( const ft::rai<Iterator> & lhs, const ft::rai<Iterator> & rhs ) */
	/* 	{ return ( lhs != rhs ); } */

	template < class Iterator1, class Iterator2 >
		bool operator != (const ft::rai<Iterator1>  lhs, const ft::rai<Iterator2>  rhs )
		{ return ( lhs.get_iterator_ptr() != rhs.get_iterator_ptr() ) ; }


	/* operator - */
	/* n = it - it; */
	template < class Iterator >
		typename ft::rai < Iterator >::difference_type operator -
		( const rai < Iterator > & lhs, const rai < Iterator > & rhs )
		{ return ( lhs - rhs ); }

	/* n = it1 - it2; */
	template < class iterator1, class iterator2 >
		typename ft::rai < iterator1 >::difference_type operator -
		( const ft::rai < iterator1 > lhs, const ft::rai < iterator2 > rhs )
		{ return ( lhs.get_iterator_ptr() - rhs.get_iterator_ptr() ) ; }

	/* it = it - n; */
	template < class Iterator >
		ft::rai < Iterator > operator -
		( typename rai < Iterator >::difference_type n, const ft::rai < Iterator > & lhs)
		{ return ( lhs - n); }

	/* operator + */
	/* n = it + it; */
	template < class Iterator >
		typename ft::rai < Iterator >::difference_type operator +
		( const ft::rai < Iterator > & lhs, const ft::rai < Iterator > & rhs )
		{ return ( lhs + rhs ); }

	/* n = it1 + it2; */
	template < class Iterator1, class Iterator2 >
		typename rai < Iterator1 >::difference_type operator +
		( const ft::rai < Iterator1 > lhs, const ft::rai < Iterator2 > rhs )
		{ return ( lhs.get_iterator_ptr() + rhs.get_iterator_ptr() ) ; }

	/* it = it + n; */
	template < class Iterator >
		ft::rai < Iterator > operator +
		(typename rai < Iterator >::difference_type n, const ft::rai < Iterator > & lhs )
		{ return ( lhs + n); }


	/* REVERSE_VECTOR_ITERATOR */
	/* page 520 */

	template < class Iterator >
		class reverse_iterator : public
      ft::iterator<typename iterator_traits<Iterator>::iterator_category,
               typename iterator_traits<Iterator>::value_type,
               typename iterator_traits<Iterator>::difference_type,
               typename iterator_traits<Iterator>::pointer,
               typename iterator_traits<Iterator>::reference>
		{
			protected :
				Iterator									_ptr;

			public:
				typedef Iterator iterator_type;
				typedef typename ft::iterator_traits<Iterator>::iterator_category iterator_category;
				typedef typename ft::iterator_traits < Iterator >::value_type value_type;
				typedef typename ft::iterator_traits < Iterator >::difference_type difference_type;
				typedef typename ft::iterator_traits < Iterator >::pointer pointer;
				typedef typename ft::iterator_traits < Iterator >::reference reference;


			public :
				/* COPLIEN FORM */

				/* Default constructor */
				reverse_iterator( void )
					: _ptr( 0 )
				{ return ; };

				/* norme iso page 520 */
				/* 1 param constructor */
				explicit reverse_iterator( Iterator ptr )
					: _ptr( ptr )
				{ return ; };

				template <class U>
					reverse_iterator  (const reverse_iterator<U>& u)
					: _ptr( u.base())
					{ return ;}

				template< class U >
					reverse_iterator& operator=( const reverse_iterator<U> & u )
					{
						_ptr = u.base();
						return *this;
					}

				Iterator base () const
				{ return _ptr ; }

				// casse les reverse_iterator
				//
				/* To build a const Iterator from a regular iterator */
				/* operator reverse_iterator < const value_type >() const */
				/* { */
				/* 	return (reverse_iterator< const value_type >(_ptr)); */
				/* } */


				/* destructor */
				~reverse_iterator ( void )
				{ return ; };

				/* assignation operator " = " */
				reverse_iterator & operator = ( const reverse_iterator & lhs_vector )
				{
					_ptr = lhs_vector._ptr;
					return (*this);
				}

				/* GETTER */
				/* useful to initialise copy constructor */
				/* pointer get_iterator_ptr ( void ) const */
				/* { return (this->_ptr); } */

				/* https://www.cplusplus.com/doc/tutorial/operators/ */
				/* OPERATORS */

				/* https://www.cplusplus.com/reference/iterator/RandomAccessIterator/ */
				/* random access iterator valid operations */

				/* Can be compared for equivalence using the equality/inequality operators */
				/* (meaningful when both iterator values iterate over the same underlying sequence). */

				/* a == b */
				bool operator == ( const reverse_iterator & lhs_vector ) const
				{ return ( this->_ptr == lhs_vector._ptr ); }

				/* a != b */
				bool operator != ( const reverse_iterator & lhs_vector ) const
				{ return ( this->_ptr != lhs_vector._ptr ); }

				/* Can be dereferenced as an rvalue (if in a dereferenceable state). */

				/*  *a  */
				reference operator * ( void ) const
				{
					Iterator it = _ptr;
					return ( *--it );
				}

				/* a->m */
				pointer operator -> ( void ) const
				{ return   &(operator*()) ; }

				/* For mutable iterators (non-constant iterators): */
				/* Can be dereferenced as an lvalue (if in a dereferenceable state). */

				/* *a = t */
				/* OK -> addition de 2 overloads */ 

				/* Can be incremented (if in a dereferenceable state). */
				/* The result is either also dereferenceable or a past-the-end iterator. */
				/* Two iterators that compare equal, keep comparing equal after being both increased. */

				/* ++a */
				reverse_iterator & operator ++ ( void )
				{
					--_ptr;
					return ( *this );
				}

				/* a++ */
				reverse_iterator operator ++ ( int )
				{
					reverse_iterator tmp = (*this);
					++(*this);
					return ( tmp );
				}

				/* *a++ */
				/* OK -> addition de 2 overloads */ 

				/* Can be decremented (if a dereferenceable iterator value precedes it). */

				/* --a */
				reverse_iterator & operator -- ( void )
				{
					this->_ptr++;
					return ( *this );
				}

				/* a-- */
				reverse_iterator operator -- ( int )
				{
					reverse_iterator tmp = (*this);
					--(*this);
					return ( tmp );
				}

				/* *a-- */
				/* OK -> addition de 2 overloads */ 

				/* Supports the arithmetic operators + and - between an iterator and an integer */ 
				/* value, or subtracting an iterator from another.  */

				/* a + n */
				reverse_iterator operator + ( difference_type n ) const
				{ return reverse_iterator(_ptr - n); }

				/* n + a */
				/* difference_type operator + ( reverse_iterator a ) */
				/* { return ( this->_ptr + a._ptr ); } */

				/* a - n */
				reverse_iterator operator - ( difference_type n ) const
				{ return reverse_iterator(_ptr + n); }

				/* a - b */
				/* difference_type operator - (reverse_iterator b) */
				/* { return ( this->_ptr - b._ptr ); } */

				/* Can be compared with inequality relational operators (<, >, <= and >=). */

				/* a < b */
				bool operator < ( const reverse_iterator & lhs_vector ) const
				{ return (this->_ptr > lhs_vector._ptr ); }

				/* a > b */
				bool operator > ( const reverse_iterator & lhs_vector ) const
				{ return (this->_ptr < lhs_vector._ptr ); }

				/* a <= b */
				bool operator <= ( const reverse_iterator & lhs_vector ) const
				{ return (this->_ptr >= lhs_vector._ptr ); }

				/* a >= b */
				bool operator >= ( const reverse_iterator & lhs_vector ) const
				{ return (this->_ptr <= lhs_vector._ptr ); }

				/* Supports compound assignment operations += and -= */

				/* a += n */
				reverse_iterator & operator += ( difference_type n )
				{
					this->_ptr -= n;
					return ( *this );
				}

				/* a -= n */
				reverse_iterator & operator -= ( difference_type n )
				{
					this->_ptr += n;
					return ( *this );
				}

				/* Supports the offset dereference operator ([]) */

				/* a[n] */
				reference operator [] ( difference_type n ) const
				{ return *operator+(n); }

				/* friend reverse_iterator operator + (difference_type n, reverse_iterator & lhs) */
				/* { */

				/* } */

				/* d'apres ce site pas de operator[] pour les random_access_iterator_tag */
				/* https://docs.microsoft.com/fr-fr/cpp/standard-library/iterator-operators?view=msvc-160 */

		}; // reverse_iterator

	/* non-member overloads */

	/* coparison bool */

	/* == */
	/* template < class Iterator > */
	/* 	bool operator == ( const ft::reverse_iterator<Iterator> & lhs, const ft::reverse_iterator<Iterator> & rhs ) */
	/* 	{ return ( lhs.base() == rhs.base() ); } */

	template < class Iterator1, class Iterator2 >
		bool operator == (const ft::reverse_iterator<Iterator1>  lhs, const ft::reverse_iterator<Iterator2>  rhs )
		{ return ( lhs.base() == rhs.base() ) ; }

	/* > */
	/* template < class Iterator > */
	/* 	bool operator > ( const reverse_iterator<Iterator> & lhs, const reverse_iterator<Iterator> & rhs ) */
	/* 	{ return ( rhs.base() > lhs.base() ); } */

	template < class Iterator1, class Iterator2 >
		bool operator > (const ft::reverse_iterator<Iterator1>  lhs, const ft::reverse_iterator<Iterator2>  rhs )
		{ return ( rhs.base() > lhs.base() ); }

	/* >= */
	/* template < class Iterator > */
	/* 	bool operator >= ( const reverse_iterator<Iterator> & lhs, const reverse_iterator<Iterator> & rhs ) */
	/* 	{ return ( rhs.base() >= lhs.base() ); } */

	template < class Iterator1, class Iterator2 >
		bool operator >= (const ft::reverse_iterator<Iterator1>  lhs, const ft::reverse_iterator<Iterator2>  rhs )
		{ return ( rhs.base() >= lhs.base() ); }

	/* < */
	/* template < class Iterator > */
	/* 	bool operator < ( const reverse_iterator<Iterator> & lhs, const reverse_iterator<Iterator> & rhs ) */
	/* 	{ return ( rhs.base() < lhs.base() ); } */

	template < class Iterator1, class Iterator2 >
		bool operator < (const ft::reverse_iterator<Iterator1>  lhs, const ft::reverse_iterator<Iterator2>  rhs )
		{ return ( rhs.base() < lhs.base() ); }

	/* <= */
	/* template < class Iterator > */
	/* 	bool operator <= ( const reverse_iterator<Iterator> & lhs, const reverse_iterator<Iterator> & rhs ) */
	/* 	{ return ( rhs.base() <= lhs.base() ); } */

	template < class Iterator1, class Iterator2 >
		bool operator <= (const ft::reverse_iterator<Iterator1>  lhs, const ft::reverse_iterator<Iterator2>  rhs )
		{ return ( rhs.base() <= lhs.base() ); }

	/* != */
	/* template < class Iterator > */
	/* 	bool operator != ( const ft::reverse_iterator<Iterator> & lhs, const ft::reverse_iterator<Iterator> & rhs ) */
	/* 	{ return ( lhs.base() != rhs.base() ); } */

	template < class Iterator1, class Iterator2 >
		bool operator != (const ft::reverse_iterator<Iterator1>  lhs, const ft::reverse_iterator<Iterator2>  rhs )
		{ return ( lhs.base() != rhs.base() ) ; }


	/* operator - */
	/* n = it - it; */
	template < class Iterator >
		typename ft::reverse_iterator < Iterator >::difference_type operator -
		( const reverse_iterator < Iterator > & lhs, const reverse_iterator < Iterator > & rhs )
		{ return ( lhs - rhs ); }

	/* n = it1 - it2; */
	template < class Iterator1, class Iterator2 >
		typename ft::reverse_iterator < Iterator1 >::difference_type operator -
		( const ft::reverse_iterator < Iterator1 > lhs, const ft::reverse_iterator < Iterator2 > rhs )
		{ return ( rhs.base() - lhs.base() ) ; }

	/* it = it - n; */
	template < class Iterator >
		ft::reverse_iterator < Iterator > operator -
		( typename reverse_iterator < Iterator >::difference_type n, const ft::reverse_iterator < Iterator > & lhs)
		{ return ( lhs - n); }

	/* operator + */
	/* n = it + it; */
	template < class Iterator >
		typename ft::reverse_iterator < Iterator >::difference_type operator +
		( const ft::reverse_iterator < Iterator > & lhs, const ft::reverse_iterator < Iterator > & rhs )
		{ return ( lhs + rhs ); }

	/* n = it1 + it2; */
	template < class Iterator1, class Iterator2 >
		typename reverse_iterator < Iterator1 >::difference_type operator +
		( const ft::reverse_iterator < Iterator1 > lhs, const ft::reverse_iterator < Iterator2 > rhs )
		{ return ( lhs.base() + rhs.base() ) ; }

	/* it = it + n; */
	template < class Iterator >
		ft::reverse_iterator < Iterator > operator +
		(typename reverse_iterator < Iterator >::difference_type n, const ft::reverse_iterator < Iterator > & lhs )
		{ return ( lhs + n); }



} // ft namespace

/* USEFULL */
#endif
