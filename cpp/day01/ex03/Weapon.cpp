#include "Weapon.hpp"
#include "HumanA.hpp"

std::string const & Weapon::getType( void )
{
	return (this->_type);
}


void	Weapon::setType ( std::string type )
{
	this->_type = type;
	return ;
}

/*
 * init Constructor
 */
Weapon::Weapon( std::string type) : _type (type)
{
	std::cout << "Weapon init Constructor called. weapon_type=";
	std::cout << this->_type << std::endl;
	return ;
}


/*
 * Default Constructor
 */
Weapon::Weapon()
{
	std::cout << "Constructor called" << std::endl;
	return ;
}

/*
 * Default Destructor
 */
Weapon::~Weapon()
{
	std::cout << this->_type << " Destructor called" << std::endl;
	return ;
}

