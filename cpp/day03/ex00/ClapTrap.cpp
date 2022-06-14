#include "ClapTrap.hpp"

void ClapTrap::attack(std::string const & target)
{
	std::cout << "ClapTrap " << this->_name << " attacks " << target;
	std::cout << ", causing " << this->_Hit_points << " points of damage!";
	std::cout << std::endl;
	return ;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	this->_Hit_points -= amount;
	std::cout << "ClapTrap " << this->_name << " takes " << amount;
	std::cout << " damage points. " << this->_Hit_points;
	std::cout << " hit points remaining."<< std::endl;
	return ;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	this->_Hit_points += amount;
	std::cout << "ClapTrap " << this->_name << " is repaired, " << amount;
	std::cout << " hit points earned. " << this->_Hit_points;
	std::cout << " hit points remaining."<< std::endl;
	return ;
}

/*
 * init Constructor
 */
ClapTrap::ClapTrap ( std::string name ) :
	_name (name), _Hit_points (10), _Energy_points (10), _Attack_damage(0)
{
	std::cout << "----------------------------------" << std::endl;
	std::cout << "ClapTrap init Constructor called." << std::endl;
	std::cout << "Name : " << this->_name << std::endl;
	std::cout << "Hit_points : " << this->_Energy_points << std::endl;
	std::cout << "Energy_points : " << this->_Energy_points << std::endl;
	std::cout << "Attack_damage : " << this->_Attack_damage << std::endl;
	std::cout << "----------------------------------" << std::endl;
	return ;
}

/*
 * Default Destructor
 */
ClapTrap::~ClapTrap()
{
	std::cout << this->_name << " ClapTrap Destructor called" << std::endl;
	return ;
}

