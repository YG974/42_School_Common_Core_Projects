#ifndef Span_HPP
# define Span_HPP

#include <string>
#include <iostream>
#include <vector>

class	Span
{
	private:

		std::vector<int>	_container;
		unsigned int		_size;

	public :

		// Constructors
		Span ( unsigned int size );				// Init Constructor
		Span ( Span const & src );			// Copy constructor

		// Assignation
		Span &operator= (const Span & src);

		// Destructors
		~Span();

		// Getters
		unsigned int			getSize( void ) const;

		// Methods
		void addNumber (unsigned int new_nb);
		void addNumbers ( void );
		void printValues ( void );

		unsigned int shortestSpan( void ) ;
		unsigned int longestSpan( void ) ;
		

		// Exceptions

		// Full
		class FullContainerException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("Container is full. Number wasn't added.");
			}
	};

		// Empty
		class EmptyContainerException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("Not enought numbers in the container.");
			}
	};

};

std::ostream &	operator<<(std::ostream& os, const Span& src);

#endif
