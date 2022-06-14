#include "ScavTrap.hpp"

void	ScavTrap::guardGate ( void )
{
	std::cout << "ScavTrap " << this->_name;
	std::cout << " have entered in Gate keeper mode." << std::endl;

	return ;
}

void ScavTrap::attack(std::string const & target)
{
	std::cout << "ScavTrap " << this->_name << " attacks " << target;
	std::cout << ", causing " << this->_Hit_points << " points of damage!";
	std::cout << std::endl;
	std::cout << "THIS IS A DIFFERENT FROM CLAPTRAP ATTACK" << std::endl;
	return ;
}


/*
 * init Constructor
 */
ScavTrap::ScavTrap ( std::string name ) : ClapTrap(name)
{
	std::cout << "----------------------------------" << std::endl;
	std::cout << "ScavTrap init Constructor called." << std::endl;
	std::cout << "THIS IS A DIFFERENT CONSTRUCTOR FROM CLAPTRAP" << std::endl;
	std::cout << "Name : " << this->_name << std::endl;
	std::cout << "Hit_points : " << this->_Hit_points << std::endl;
	std::cout << "Energy_points : " << this->_Energy_points << std::endl;
	std::cout << "Attack_damage : " << this->_Attack_damage << std::endl;
	std::cout << "----------------------------------" << std::endl;
	return ;
}

/*
 * Default Destructor
 */
ScavTrap::~ScavTrap()
{
	std::cout << this->_name << " ScavTrap Destructor called" << std::endl;
	std::cout << "THIS IS A DIFFERENT DESTRUCTOR FROM CLAPTRAP" << std::endl;
	return ;
}

