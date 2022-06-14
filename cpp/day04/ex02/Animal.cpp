#include "Animal.hpp"

std::string Animal::getType ( void ) const
{
	return ( this->_type );
}

void Animal::makeSound ( void ) const
{
	std::cout << "I am a random Animal and I make sound." << std::endl;
	return ;
}

/*
 * init Constructor
 */
Animal::Animal ( std::string type ) : _type ( type )
{
	std::cout << "----------------------------------" << std::endl;
	std::cout << "Animal init Constructor called." << std::endl;
	std::cout << "Type : " << this->_type << std::endl;
	std::cout << "----------------------------------" << std::endl;
	return ;
}

/*
 * Default Constructor
 */
Animal::Animal ( void )
{
	std::cout << "----------------------------------" << std::endl;
	std::cout << "Animal Default Constructor called." << std::endl;
	std::cout << "Type : " << this->_type << std::endl;
	std::cout << "----------------------------------" << std::endl;
	return ;
}

/*
 * Default Destructor
 */
Animal::~Animal()
{
	std::cout << this->_type << " Animal Destructor called" << std::endl;
	return ;
}

