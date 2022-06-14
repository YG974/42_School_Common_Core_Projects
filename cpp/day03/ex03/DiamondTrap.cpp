#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"

void DiamondTrap::whoAmI ( void )
{
	std::cout << "My real name is " << this->_name << "."<< std::endl;
	std::cout << "But my ClapTrap::name is ";
	std::cout << this->ClapTrap::_name << "."<< std::endl;
	return ;
}

void DiamondTrap::attack(const std::string &target)
{
	return (ScavTrap::attack(target));
}

/*
 * init Constructor
 */
DiamondTrap::DiamondTrap ( std::string name) :
	// grand parent class
	ClapTrap(name + "_clap_name", 100, 50, 30),
	// parents class
	FragTrap ( name ), ScavTrap ( name ),
	// init name
	_name (name)
{
	std::cout << "----------------------------------" << std::endl;
	std::cout << "DiamondTrap init Constructor called." << std::endl;
	std::cout << "Name : " << this->_name << std::endl;
	std::cout << "Clap_Name : " << ClapTrap::_name << std::endl;
	std::cout << "Hit_points : " << this->_Hit_points << std::endl;
	std::cout << "Energy_points : " << this->_Energy_points << std::endl;
	std::cout << "Attack_damage : " << this->FragTrap::_Attack_damage << std::endl;
	std::cout << "----------------------------------" << std::endl;
	return ;
}

/*
 * Default Destructor
 */
DiamondTrap::~DiamondTrap()
{
	std::cout << this->_name << " DiamondTrap Destructor called" << std::endl;
	return ;
}

