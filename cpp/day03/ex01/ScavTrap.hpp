#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <string>
#include <iostream>
#include "ClapTrap.hpp"

class	ScavTrap : public ClapTrap
{
	protected :

		// CLAPTRAP ATTRIBUTES
		/* std::string		_name; */
		/* int				_Hit_points; */
		/* int				_Energy_points; */
		/* int				_Attack_damage; */

	public :

		// SCAVTRAP FUNCTIONS
		void	guardGate ( void );
		void	attack(std::string const & target);

		// CLAPTRAP FUNCTIONS
		/* void attack(std::string const & target); */
		/* void takeDamage(unsigned int amount); */
		/* void beRepaired(unsigned int amount); */

		// Constructors and Destructors
		ScavTrap(std::string name);			// Init Constructor
		~ScavTrap();						// Destructor
};


#endif
