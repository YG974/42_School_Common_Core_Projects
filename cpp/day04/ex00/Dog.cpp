#include "Dog.hpp"
#include "Animal.hpp"

void Dog::makeSound ( void ) const
{
	std::cout << "I'm a DOG. WOOOUUUF WOOOOUUUF." << std::endl;
	return ;
}

/*
 * init Constructor
 */
Dog::Dog ( std::string type ) : Animal( "Dog" )
{
	(void)type;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "Dog init Constructor called." << std::endl;
	std::cout << "Type : " << this->_type << std::endl;
	std::cout << "----------------------------------" << std::endl;
	return ;
}

/*
 * Default Constructor
 */
Dog::Dog ( void ) : Animal( "Dog" )
{
	std::cout << "----------------------------------" << std::endl;
	std::cout << "Dog Default Constructor called." << std::endl;
	std::cout << "Type : " << this->_type << std::endl;
	std::cout << "----------------------------------" << std::endl;
	return ;
}

/*
 * Default Destructor
 */
Dog::~Dog()
{
	std::cout << this->_type << " Dog Destructor called" << std::endl;
	return ;
}

