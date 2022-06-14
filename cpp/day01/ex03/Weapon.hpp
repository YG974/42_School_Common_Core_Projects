#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>
#include <iostream>

class	Weapon
{
	private :

		std::string		_type;

	public :

		// SETTER
		void					setType( std::string type );

		// GETTER
		std::string const &		getType( void );

		// Constructor & Destructor
		Weapon ( std::string type);		//Init Constructor
		Weapon();						//Constructor
		~Weapon();						//Destructor

};


#endif
