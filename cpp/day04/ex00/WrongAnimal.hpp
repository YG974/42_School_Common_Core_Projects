#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <string>
#include <iostream>

class	WrongAnimal
{
	private :

		WrongAnimal ( WrongAnimal const & src );			// Copy constructor
		WrongAnimal & operator= (const WrongAnimal & src);	// Copy assignment operator

	protected :
		std::string		_type;

	public :

		// Methods
		void makeSound ( void ) const;
		std::string getType ( void ) const;

		// Constructors and Destructors
		WrongAnimal( std::string type );		// Init Constructor
		WrongAnimal( void );					// Default Constructor
		~WrongAnimal();						// Destructor
};


#endif
