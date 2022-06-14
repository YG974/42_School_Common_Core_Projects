#include "Cat.hpp"
#include "Animal.hpp"

void Cat::makeSound ( void ) const
{
	std::cout << "I'm a CAT. MIAAAOUUU MIAAAOUUU." << std::endl;
	return ;
}

/*
 * init Constructor
 */
Cat::Cat ( std::string type ) : Animal( "Cat" )
{
	(void)type;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "Cat init Constructor called." << std::endl;
	std::cout << "Type : " << this->_type << std::endl;
	std::cout << "----------------------------------" << std::endl;
	return ;
}

/*
 * Default Constructor
 */
Cat::Cat ( void ) : Animal( "Cat" )
{
	std::cout << "----------------------------------" << std::endl;
	std::cout << "Cat Default Constructor called." << std::endl;
	std::cout << "Type : " << this->_type << std::endl;
	std::cout << "----------------------------------" << std::endl;
	return ;
}

/*
 * Default Destructor
 */
Cat::~Cat()
{
	std::cout << this->_type << " Cat Destructor called" << std::endl;
	return ;
}

