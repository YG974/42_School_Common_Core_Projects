#ifndef DOG_HPP
# define DOG_HPP

#include <string>
#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class	Dog : public Animal
{
	private :

		Brain*	_brain;


	protected :
		// ANIMALS ATTRIBUTES
		// std::string		_type;

	public :

		// ANIMALS Methods
		// void makeSound ( void ) const;

		// Dog Methods
		void		makeSound ( void ) const;
		void		setIdea(int i, std::string str);
		void		printIdeas( void ) const;

		// Constructors and Destructors
		Dog( void );						// Default Constructor
		Dog( std::string type );			// Init Constructor
		Dog ( Dog const & src );			// Copy constructor
		Dog & operator= (const Dog & src);	// Copy assignment operator
		virtual ~Dog();								// Destructor
};


#endif
