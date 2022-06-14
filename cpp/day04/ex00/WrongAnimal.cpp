#include "WrongAnimal.hpp"

std::string WrongAnimal::getType ( void ) const
{
	return ( this->_type );
}

void WrongAnimal::makeSound ( void ) const
{
	std::cout << "I am a random WrongAnimal and I make sound." << std::endl;
	return ;
}

/*
 * init Constructor
 */
WrongAnimal::WrongAnimal ( std::string type ) : _type ( type )
{
	std::cout << "----------------------------------" << std::endl;
	std::cout << "WrongAnimal init Constructor called." << std::endl;
	std::cout << "Type : " << this->_type << std::endl;
	std::cout << "----------------------------------" << std::endl;
	return ;
}

/*
 * Default Constructor
 */
WrongAnimal::WrongAnimal ( void )
{
	std::cout << "----------------------------------" << std::endl;
	std::cout << "WrongAnimal Default Constructor called." << std::endl;
	std::cout << "Type : " << this->_type << std::endl;
	std::cout << "----------------------------------" << std::endl;
	return ;
}

/*
 * Default Destructor
 */
WrongAnimal::~WrongAnimal()
{
	std::cout << this->_type << " WrongAnimal Destructor called" << std::endl;
	return ;
}

