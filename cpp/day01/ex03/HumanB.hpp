#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class	HumanB
{
	private :

		// HumanB doesn't always has a Weapon, so we can't use reference
		// since Weapon may point to NULL, we use pointers
		Weapon			*_Weapon;

		std::string		_name;

	public :

		void	attack ( void );

		// type reference point to *_Weapon, possible to change it with ref
		void	setWeapon ( Weapon &type);

		// Constructor & Destructor
		// Only name in Init constructor, HumanB won't always have a Weapon
		HumanB ( std::string name);					// Init Constructor
		~HumanB();									// Destructor

		// no default constructor for HumanB because HumanB always have a name
		/* HumanB();								// Constructor */
};


#endif
