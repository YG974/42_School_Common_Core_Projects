#ifndef CAT_HPP
# define CAT_HPP

#include <string>
#include <iostream>
#include "Animal.hpp"

class	Cat : public Animal
{
	private :

		Cat ( Cat const & src );			// Copy constructor
		Cat & operator= (const Cat & src);	// Copy assignment operator

	protected:
		// ANIMALS ATTRIBUTES
		// std::string		_type;

	public :

		// ANIMALS Methods
		// void makeSound ( void ) const;

		// Cat Methods
		void makeSound ( void ) const;

		// Constructors and Destructors
		Cat( void );				// Default Constructor
		Cat( std::string type );	// Init Constructor
		~Cat();						// Destructor
};


#endif
