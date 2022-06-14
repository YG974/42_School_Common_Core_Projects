#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

void WrongCat::makeSound ( void ) const
{
	std::cout << "I'm a WRONGCAT. MEEWWWW MEEWWWW." << std::endl;
	return ;
}

/*
 * init Constructor
 */
WrongCat::WrongCat ( std::string type ) : WrongAnimal( "WrongCat" )
{
	(void)type;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "WrongCat init Constructor called." << std::endl;
	std::cout << "Type : " << this->_type << std::endl;
	std::cout << "----------------------------------" << std::endl;
	return ;
}

/*
 * Default Constructor
 */
WrongCat::WrongCat ( void ) : WrongAnimal( "WrongCat" )
{
	std::cout << "----------------------------------" << std::endl;
	std::cout << "WrongCat Default Constructor called." << std::endl;
	std::cout << "Type : " << this->_type << std::endl;
	std::cout << "----------------------------------" << std::endl;
	return ;
}

/*
 * Default Destructor
 */
WrongCat::~WrongCat()
{
	std::cout << this->_type << " WrongCat Destructor called" << std::endl;
	return ;
}

