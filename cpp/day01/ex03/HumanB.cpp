#include "Weapon.hpp"
#include "HumanB.hpp"

void	HumanB::attack ( void )
{
	std::cout << this->_name;
	std::cout << " attacks with his ";

	// We use '->' because point to '*_Weapon' 
	std::cout << this->_Weapon->getType();

	std::cout << std::endl;
	return ;
}

// type reference point to *_Weapon, possible to change it with ref
void	HumanB::setWeapon ( Weapon &type)
{
	this->_Weapon = &type;
}

/*
 * init Constructor
 * HumanB doesn't always has a Weapon, so we can't use reference, 
 * since Weapon may point to NULL, so we use pointers
 */
HumanB::HumanB ( std::string name) : _name (name)
{
	std::cout << "HumanB init Constructor called. name=";
	std::cout << this->_name << std::endl;;
	return ;
}

/*
 * Default Constructor
 */
/* HumanB::HumanB() */
/* { */
/* 	std::cout << "Constructor called" << std::endl; */
/* 	return ; */
/* } */

/*
 * Default Destructor
 */
HumanB::~HumanB()
{
	std::cout << this->_name << " HumanB Destructor called" << std::endl;
	return ;
}

