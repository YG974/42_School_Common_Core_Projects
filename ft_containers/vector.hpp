/* ************************************************************************** */
/* ygeslin                                                                    */
/* VECTOR.HPP                                                                 */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iterator>
#include <memory>
#include <iostream>
#include <stdexcept>
#include "utils.hpp"
#include "iterators.hpp"

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
		public :
			typedef T									value_type;
			typedef Alloc								allocator_type;
			typedef typename Alloc::reference			reference;
			typedef typename Alloc::const_reference		const_reference;
			typedef typename Alloc::pointer				pointer;
			typedef typename Alloc::const_pointer		const_pointer;


			// ITERATORS
			/* typedef std::random_access_iterator_tag */
			typedef ft::rai<value_type>							iterator;
			typedef ft::rai< const value_type >				const_iterator;
			typedef ft::reverse_iterator<iterator>			reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

			typedef ptrdiff_t							difference_type;
			typedef size_t								size_type;

			/* ATTRIBUTES */
		private :
			allocator_type								_allocator;
			pointer										_ptr;
			size_type									_size;
			size_type									_capacity;


		public :
/* Constructor */
/* default (1) */	
			/* 0 parameter */
			vector (const allocator_type& alloc = allocator_type())
				: _allocator(alloc),
				_ptr(0),
				_size(0),
				_capacity(0)
			{ return ; };

			/* Allocator */
			allocator_type	get_allocator() const
			{ return ( _allocator ); }

/* fill (2) */	
			/* 2 parameter */
			explicit vector (size_type n,
					const value_type& val = value_type(),
					const allocator_type& alloc = allocator_type()) :
				_allocator(alloc),
				_ptr(0),
				_size(n),
				_capacity(n)
			{
				if ( _capacity )
					this->_ptr = alloconstruct(n, this->_ptr, val);
				for ( size_type i = 0 ; i < _size ; i++ )
					this->_allocator.construct(&_ptr[i], val);
			}

/* range (3) */
			/* 3 parameter */
			template <class InputIterator>
				vector (typename ft::enable_if<!std::numeric_limits<InputIterator>::is_integer, InputIterator>::type
						first,
						InputIterator last,
						const allocator_type& alloc = allocator_type()) :
				_allocator(alloc),
				_ptr(0),
				_size(0),
				_capacity(0)
				{
					_capacity = ft::distance(first, last);
					if ( _capacity )
						_ptr = _allocator.allocate(_capacity);
					for ( ; first != last ; first++ )
						this->_allocator.construct(&_ptr[_size++], *first);
					/* while (first != last) */
					/* 	this->push_back(*first++); */
				}

/* copy (4) */	
			/* 1 parameter */
			vector (const vector& x) :
				_allocator(x.get_allocator()),
				_ptr(0),
				_size(x.size()),
				_capacity(x.capacity())
		{
			if ( _capacity )
				_ptr = _allocator.allocate(_capacity);
			for ( size_type i = 0 ; i < _size ; i++ )
				this->_allocator.construct(&_ptr[i], x._ptr[i]);
		}

			/* destructor */
			~vector()
			{
				this->clear();
			/* 	this->_allocator.deallocate( _ptr, _capacity ); */
			}

			/* /1* copy (1) *1/ */	
			vector& operator= (const vector& x)
			{
				vector tmp;
				const_iterator first = x.begin();
				const_iterator last = x.end();

				clear();

				if (x.size() > tmp._capacity)
					tmp._capacity = x.size();
				if (x.capacity() < _capacity)
					tmp._capacity = _capacity;

				tmp._ptr = _allocator.allocate(tmp._capacity);
				for (size_type i = 0; first != last; ++first)
					tmp._allocator.construct(&tmp._ptr[i++], *first);

				_ptr = tmp._ptr;
				_size = x._size;
				_capacity = tmp._capacity;

				return (*this);

				/* version norme iso */
				/* if (x == *this) */
				/* 	return *this; */
				/* this->clear(); */
				/* /1* this->insert(begin(), x.begin(), x.end()); *1/ */
				/* return (*this); */
			}


		private :
			pointer alloconstruct(size_type size,
					pointer initial_ptr,
					value_type val)
			{
				// Allocate n memory block of value_type size
				initial_ptr = this->_allocator.allocate(size);
				for ( size_type i = 0 ; i < size ; i++ )
				{
					// construct an object of value_type size
					this->_allocator.construct(initial_ptr + i, val);
				}
				return (initial_ptr);
			}


/* ************************************************************************** */
/* MEMBER FUNCTIONS                                                               */
/* ************************************************************************** */
public:


/* https://www.cplusplus.com/reference/vector/vector/begin/ */

/* Begin */
iterator begin ( void )
{
	iterator it;
	return ( iterator(_ptr) );
}

const_iterator begin ( void ) const
{ return ( const_iterator(_ptr) ); }

/* https://www.cplusplus.com/reference/vector/vector/end/ */

/* end */
iterator end ( void )
{ return ( iterator(_ptr + _size) ); }

const_iterator end() const
{ return ( const_iterator(_ptr + _size) ); }

/* rbegin */
reverse_iterator rbegin ( void )
{ return ( reverse_iterator(end()) ); }

const_reverse_iterator rbegin ( void ) const
{ return ( const_reverse_iterator(end()) ); }

/* rend */
reverse_iterator rend ( void )
{ return ( reverse_iterator(begin()) ); }

const_reverse_iterator rend ( void ) const
{ return ( const_reverse_iterator(begin()) ); }

/* size */
size_type size() const
{ return ( _size ); }

/* max_size */
size_type max_size() const
{ return ( _allocator.max_size() ); }

/* capacity */
size_type capacity() const
{ return ( _capacity ); }

/* empty */
bool empty() const
{ return ( _size == 0 ); }

/* reserve */
void reserve (size_type n)
{
	vector<T, Alloc>	tmp;
	iterator first = begin();
	iterator last = end();

	if (n > _capacity)
	{
		_size = 0;
		_capacity = n;
		tmp._ptr = _allocator.allocate(n);
		for (; first != last; ++first)
			_allocator.construct(&tmp._ptr[_size++], *first);
		_ptr = tmp._ptr;
	}
	// IF requested size is less than cpacity, do nothing
	/* if ( n <= _capacity ) */
	/* 	return ; */

	/* // IF requested size is higher than max_size, exception */
	/* if ( n > this->max_size()) */
	/* 	throw std::length_error("Vector reserve request is too high\n"); */

	/* else if ( n > _capacity ) */
	/* { */
	/* 	pointer		new_ptr		= _allocator.allocate( n ); */
	/* 	if ( _capacity > 0 ) */
	/* 	{ */
	/* 		for (size_type i = 0 ; i < _size ; i++ ) */
	/* 		{ */
	/* 			_allocator.construct( &new_ptr[i], _ptr[i] ); */
	/* 			_allocator.destroy( &_ptr[i] ); */
	/* 		} */
	/* 		_allocator.deallocate( _ptr, _size ); */
	/* 	} */
	/* 	_capacity = n; */
	/* 	_ptr = new_ptr; */
	/* } */
	/* return ; */
}

/* push_back */
void push_back (const value_type& val)
{

	if ( _size == _capacity && _capacity > 0)
	{
		// the real stl allocate 2 times the capacity, we have to do it too
		// to fit the capacity tests.
		pointer ptr = _allocator.allocate( _capacity * 2);
		for ( size_type i = 0 ; i < _size ; i++ )
		{
			_allocator.construct(&ptr[i], _ptr[i]);
			_allocator.destroy(&_ptr[i]);
		}
		_allocator.deallocate( _ptr, _capacity );
		_capacity = _capacity * 2;
		_ptr = ptr;
	}
	else if ( _capacity == 0 )
	{
		_capacity = 1;
		_ptr = _allocator.allocate( _capacity );
	}
	_allocator.construct( &_ptr[_size], val);
	_size++;
	return ;
}

/* pop_back */
void pop_back()
{
	if (_size > 0)
	{
		_allocator.destroy( &_ptr[_size - 1]);
		_size--;
	}
	return ;
}

/* page 485 */
/* resize */
// comportement different entre mac et linux
void resize (size_type n, value_type val = value_type())
{
	if (n < _size)
		for (; n < _size; _size--)
			_allocator.destroy(&_ptr[_size]);
	else
	{
		if (n <= _capacity)
			;
		else if (n <= _capacity * 2)
			reserve( _capacity * 2);
		else
			reserve(n);
		for (; _size < n; _size++)
			_allocator.construct(&_ptr[_size], val);
	}
	/* if (n > size()) */
	/* 	insert(end(), n - size(), val); */
	/* else if (n < size()) */
	/* 	erase(begin() + n, end()); */
	/* else */
	/* 	; */
	/* if ( n < _size) */
	/* 	while (n < _size) */
	/* 		this->pop_back(); */
	/* else */
	/* 	while ( _size < n ) */
	/* 		push_back(val); */
	return ;
}

/* assign */
/* https://www.cplusplus.com/reference/vector/vector/assign/ */
/* std::vector::assign */

/* page 484 */
/* range (1) */	
	template <class InputIterator>
	void assign (typename ft::enable_if<!std::numeric_limits<InputIterator>::is_integer, InputIterator>::type
			first,
			InputIterator last)
{
	/* norme iso */
	/* erase(begin(), end()); */
	/* insert(begin(), first, last); */

	/* size_type new_size = last - first; */
	size_type new_size = ft::distance(first, last);
	
	clear();
	if (new_size > _capacity)
	{
		_allocator.deallocate(_ptr, _capacity);
		_capacity = new_size;
		_ptr = _allocator.allocate(_capacity);
	}
	_size = new_size;
	for (size_type i = 0; first != last; ++first)
		_allocator.construct(&_ptr[i++], *first);

	return ;
}

/* page 484 */
/* fill (2) */	
void assign (size_type n, const value_type& val)
{
	/* norme iso */
	/* erase(begin(), end()); */
	/* insert(begin(), n, val); */

	clear();
	if (n > _capacity)
	{
		_allocator.deallocate(_ptr, _capacity);
		_capacity = n;
		_ptr = _allocator.allocate(_capacity);
	}
	_size = n;
	for (size_type i = 0; i < n; i++)
		_allocator.construct(&_ptr[i], val);

	return ;
}

/* clear */
void clear()
{
	if (_ptr)
		for ( size_type i = 0 ; i < _size ; i++ )
			_allocator.destroy(&_ptr[i]);
	_size = 0;
	return ;
}

/* front */
reference front()
{ return ( *_ptr ); }

/* const_front */
const_reference front() const
{ return ( *_ptr ); }

/* back */
reference back()
{ return ( _ptr[_size - 1] ); }

/* const_back */
const_reference back() const
{ return ( _ptr[_size - 1] ); }

/* insert */
/* https://www.cplusplus.com/reference/vector/vector/insert/ */

/* single element (1) */	
iterator insert (iterator position, const value_type& val)
{
	/* this->insert(position, 1, val); */
	/* return (position); */

	size_type i = position - begin();
	insert(position, 1, val);

	return iterator(this->begin() + i);
}

/* fill (2) */	
void insert (iterator position, size_type n, const value_type& val)
{
	vector<T, Alloc>	tmp;
	iterator first = begin(); iterator last = end();
	size_type	index = 0;

	if (!n)
		return ;
	tmp = *this;
	_size += n;
	if (_size > _capacity * 2)
		_capacity = _size;
	else if (_size > _capacity)
		_capacity = _capacity * 2; 
	tmp._ptr = _allocator.allocate(_capacity);
	for (; first != position; ++first)
		_allocator.construct(&tmp._ptr[index++], *first);
	for(size_type i = index + n; index < i; index++)
		_allocator.construct(&tmp._ptr[index], val);
	for (; index < _size; ++first)
		_allocator.construct(&tmp._ptr[index++], *first);
	_ptr = _allocator.allocate(_capacity);
	for (size_type i = 0; i < _size; i++)
		_allocator.construct(&_ptr[i], tmp[i]);
	tmp.clear();
	tmp._allocator.deallocate(tmp._ptr, tmp._capacity);
	tmp._capacity = 0;
	tmp._ptr = 0;
	tmp._size = 0;


	/* difference_type nb = position - begin(); */
	/* reserve( _size + n ); */

	/* for ( difference_type i = _size ; i > nb ; i-- ) */
	/* { */
	/* 	_allocator.construct(&_ptr[i + n - 1], _ptr[i - 1]); */
	/* 	_allocator.destroy(&_ptr[i - 1]); */
	/* } */

	/* for (size_type i = 0 ; i < n ; i++) */
	/* 	_allocator.construct(&_ptr[nb + i], val ); */
	/* _size = _size + n; */
	/* return ; */
}

/* range (3) */	
template <class InputIterator>
    void insert (iterator position, InputIterator first, InputIterator last,
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0)
{
	vector<T, Alloc>	tmp;
	iterator	first_it = begin(); iterator	last_it = end();
	size_type	index = 0;
	size_type	len = ft::distance(first, last);

	if (!len)
		return ;
	resize(_size + len);
	tmp._ptr = _allocator.allocate(_capacity);
	for (; first_it != position; ++first_it)
		_allocator.construct(&tmp._ptr[index++], *first_it);
	for (; first != last; ++first)
		_allocator.construct(&tmp._ptr[index++], *first);
	for (; first_it != last_it; ++first_it)
		_allocator.construct(&tmp._ptr[index++], *first_it);
	_ptr = tmp._ptr;

	/* size_type nb = position - _ptr; */
	/* size_type n = ft::distance(first, last); */
	/* reserve( _size + n ); */

	/* for ( size_type i = _size ; i > nb ; i-- ) */
	/* { */
	/* 	_allocator.construct(&_ptr[i + n - 1], _ptr[i - 1]); */
	/* 	_allocator.destroy(&_ptr[i - 1]); */
	/* } */

	/* for (size_type i = 0 ; first != last ; first++, i++) */
	/* 	_allocator.construct( &_ptr[nb + i], *first ); */
	/* _size = _size + n; */
	/* return ; */
}

/* erase */
iterator erase (iterator position)
{ return erase(position, position + 1); }

iterator erase (iterator first, iterator last)
{
	iterator	it = begin();
	iterator	ret = first;
	size_type	len = ft::distance(first, last);

	for (; last != end(); first++, last++)
		*first = *last;
	while (len--)
		_allocator.destroy(&_ptr[--_size]);

	return (ret);
}

/* std::vector::swap */
void swap (vector& x)
{
	vector tmp(*this);

	// if we just build form = operator, pointer don't remain valid
	tmp._size = _size;
	tmp._capacity = _capacity;
	tmp._allocator = _allocator;
	tmp._ptr = _ptr;

	_size = x._size;
	_capacity = x._capacity;
	_allocator = x._allocator;
	_ptr = x._ptr;

	x._size = tmp._size;
	x._capacity = tmp._capacity;
	x._allocator = tmp._allocator;
	x._ptr = tmp._ptr;
}

/* at */
reference at (size_type n)
{
	if ( n >= _size )
		throw std::out_of_range("n is out of range");
	return ( _ptr[n] );
}

const_reference at (size_type n) const
{
	if ( n >= _size )
		throw std::out_of_range("n is out of range");
	return ( _ptr[n] );
}

reference operator[] (size_type n)
{
	return ( _ptr[n] );
}

const_reference operator[] (size_type n) const
{
	return ( _ptr[n] );
}


	};// Vector class

/* std::swap */
template <class T, class Alloc>
  void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
{
	x.swap(y);
}

/* Relational operators */
/* https://www.cplusplus.com/reference/vector/vector/operators/ */

/* == */
template <class T, class Alloc>
  bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	if (lhs.size() != rhs.size())
		return false;
	for (size_t i = 0; i < lhs.size(); i++)
		if (lhs[i] != rhs[i])
			return false;
	return true;
}

template <class T, class Alloc>
bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{ return (lhs == rhs ? false : true); }

template <class T, class Alloc>
bool operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{ return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()); }

template <class T, class Alloc>
bool operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{ return (rhs < lhs ? false : true); }

template <class T, class Alloc>
bool operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{ return (rhs < lhs ? true : false); }

template <class T, class Alloc>
bool operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{ return (lhs < rhs ? false : true); }

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
