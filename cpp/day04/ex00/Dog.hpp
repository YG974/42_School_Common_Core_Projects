#ifndef DOG_HPP
# define DOG_HPP

#include <string>
#include <iostream>
#include "Animal.hpp"

class	Dog : public Animal
{
	private :

		Dog ( Dog const & src );			// Copy constructor
		Dog & operator= (const Dog & src);	// Copy assignment operator

	protected :
		// ANIMALS ATTRIBUTES
		// std::string		_type;

	public :

		// ANIMALS Methods
		// void makeSound ( void ) const;

		// Dog Methods
		void makeSound ( void ) const;

		// Constructors and Destructors
		Dog( void );						// Default Constructor
		Dog( std::string type );			// Init Constructor
		~Dog();								// Destructor
};


#endif
