#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <deque>
#include <iterator>
#include <string>
#include <iostream>
#include <vector>
#include <stack>
#include <list>

template < typename T >
class	MutantStack : public std::stack<T>
{
	private:

	public :

		// Default Constructors
		MutantStack ( void ) : std::stack<T>()
		{ return ; };

		// Copy constructor
		MutantStack ( MutantStack<T> const & src ) : std::stack<T>( src )
		{ return ; }

/*
 *  Stack Template container has a container attribute named 'c'
 *  We acces tis attribute using this->c
 */
		// Assignation
		MutantStack &operator= (const MutantStack<T> & src)
		{
			this->c = src.c;
			return ( *this );
		}

		// Destructors
		~MutantStack ( void )
		{ return ; }

		// Iterators
		typedef typename std::deque<T>::iterator iterator;

		iterator begin ( void ) { return this->c.begin(); };
		iterator end ( void ) { return this->c.end(); };

		// Const Iterators
		typedef typename std::deque<T>::const_iterator const_iterator;
		const_iterator begin ( void ) const { return this->c.begin(); } ;
		const_iterator end ( void ) const { return this->c.end(); } ;
};

#endif
