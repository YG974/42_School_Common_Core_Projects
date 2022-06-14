#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>
#include <iostream>

class	Animal
{
	private:

		Animal ( Animal const & src );			// Copy constructor
		Animal & operator= (const Animal & src);	// Copy assignment operator

	protected :
		std::string		_type;

	public :

		// Methods
		virtual void makeSound ( void ) const = 0;
		std::string getType ( void ) const;

		// Constructors and Destructors
		Animal( std::string type );		// Init Constructor
		Animal( void );					// Default Constructor
		virtual ~Animal();						// Destructor
};


#endif
