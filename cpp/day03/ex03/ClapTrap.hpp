#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>
#include <iostream>

class	ClapTrap
{
	protected :

		std::string		_name;
		int				_Hit_points;
		int				_Energy_points;
		int				_Attack_damage;

	public :

		void attack(std::string const & target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		// Constructors and Destructors
		ClapTrap(std::string name, int a, int b, int c);	// Init Constructor
		ClapTrap(std::string name);			// Init Constructor
		ClapTrap();							// Default Constructor
		~ClapTrap();						// Destructor
};


#endif
