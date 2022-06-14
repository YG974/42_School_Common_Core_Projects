#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <string>
#include <iostream>
#include "ClapTrap.hpp"

class	FragTrap : public ClapTrap
{
	protected :

		// CLAPTRAP ATTRIBUTES
		/* std::string		_name; */
		/* int				_Hit_points; */
		/* int				_Energy_points; */
		/* int				_Attack_damage; */

	public :

		// FRAGTRAP FUNCTIONS
		void	highFivesGuys ( void );

		// CLAPTRAP FUNCTIONS
		/* void attack(std::string const & target); */
		/* void takeDamage(unsigned int amount); */
		/* void beRepaired(unsigned int amount); */

		// Constructors and Destructors
		FragTrap(std::string name);			// Init Constructor
		~FragTrap();						// Destructor
};


#endif
