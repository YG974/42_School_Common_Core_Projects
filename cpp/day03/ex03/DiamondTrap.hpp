#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include <string>
#include <iostream>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class	DiamondTrap : public FragTrap, public ScavTrap
{
	protected :
		std::string		_name;

		// CLAPTRAP ATTRIBUTES
		/* std::string		_name; */
		/* int				_Hit_points; */
		/* int				_Energy_points; */
		/* int				_Attack_damage; */

	public :

		// DIAMONDTRAP FUNCTIONS
		void attack(std::string const & target);
		void whoAmI ( void );

		// CLAPTRAP FUNCTIONS
		/* void attack(std::string const & target); */
		/* void takeDamage(unsigned int amount); */
		/* void beRepaired(unsigned int amount); */

		// Constructors and Destructors
		DiamondTrap(std::string name);		// Init Constructor
		~DiamondTrap();						// Destructor
};


#endif
