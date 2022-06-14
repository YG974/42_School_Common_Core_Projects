#include "Zombie.hpp"

void	Zombie::setName ( std::string name )
{
	this->_name = name;
	return ;
}

void	Zombie::announce ( void )
{
	std::cout << this->_name << " BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}

/*
 * init Constructor
 */
Zombie::Zombie( std::string name ) : _name (name)
{
	this->_name = name;
	std::cout << this->_name << " Init constructor called" << std::endl;
	return ;
}

/*
 * Default Constructor
 */
Zombie::Zombie()
{
	std::cout << "Constructor called" << std::endl;
	return ;
}

/*
 * Default Destructor
 */
Zombie::~Zombie()
{
	std::cout << this->_name << " Destructor called" << std::endl;
	return ;
}

/*
 * Initialisation of non member class variable
 */
int		Zombie::nbZombie = 0;
