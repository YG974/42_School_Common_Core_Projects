#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class	HumanA
{
	private :

		// HumanA always has a Weapon, so we can use reference
		// since Weapon won't point to NULL
		Weapon			&_Weapon;

		std::string		_name;

	public :

		void	attack ( void );

		// Constructor & Destructor
		// Only Init constructor, because HumanA need to always have a Weapon
		HumanA ( std::string name, Weapon &type);	// Init Constructor
		~HumanA();									// Destructor

		// no default constructor for HumanA because HumanA always has a Weapon
		/* HumanA();								// Constructor */
};


#endif
