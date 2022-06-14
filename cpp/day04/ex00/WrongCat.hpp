#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include <string>
#include <iostream>
#include "WrongAnimal.hpp"

class	WrongCat : public WrongAnimal
{
	private :

		WrongCat ( WrongCat const & src );			// Copy constructor
		WrongCat & operator= (const WrongCat & src);	// Copy assignment operator

	protected :
		// ANIMALS ATTRIBUTES
		// std::string		_type;

	public :

		// ANIMALS Methods
		// void makeSound ( void ) const;

		// WrongCat Methods
		void makeSound ( void ) const;

		// Constructors and Destructors
		WrongCat( void );				// Default Constructor
		WrongCat( std::string type );	// Init Constructor
		~WrongCat();						// Destructor
};


#endif
