#include "Weapon.hpp"
#include "HumanA.hpp"

void	HumanA::attack ( void )
{
	std::cout << this->_name;
	std::cout << " attacks with his ";

	// We use '.' because point to '&_Weapon' 
	std::cout << this->_Weapon.getType();

	std::cout << std::endl;
	return ;
}

/*
 * init Constructor
 * HumanA always has a Weapon, so we can use reference, since Weapon won't
 * point to NULL ever if Weapon isn't init
 */
HumanA::HumanA ( std::string name, Weapon &type) : _Weapon (type), _name (name)
{
	std::cout << "HumanA init Constructor called. Weapon_type=";
	std::cout << this->_Weapon.getType();
	std::cout << " | name=" << this->_name << std::endl;
	return ;
}

/*
 * Default Constructor
 */
/* HumanA::HumanA() */
/* { */
/* 	std::cout << "Constructor called" << std::endl; */
/* 	return ; */
/* } */

/*
 * Default Destructor
 */
HumanA::~HumanA()
{
	std::cout << this->_name << " HumanA Destructor called" << std::endl;
	return ;
}

