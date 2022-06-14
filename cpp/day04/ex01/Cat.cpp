#include "Cat.hpp"
#include "Animal.hpp"
#include "Brain.hpp"

void Cat::makeSound ( void ) const
{
	std::cout << "I'm a CAT. MIAAAOUUU MIAAAOUUU." << std::endl;
	return ;
}

/*
 * init Constructor
 */
Cat::Cat ( std::string type ) : Animal( "Cat" ), _brain(new Brain())
{
	(void)type;
	this->_brain = new Brain();
	std::cout << "----------------------------------" << std::endl;
	std::cout << "Cat init Constructor called." << std::endl;
	std::cout << "Type : " << this->_type << std::endl;
	std::cout << "----------------------------------" << std::endl;
	return ;
}

/*
 * Default Constructor
 */
Cat::Cat ( void ) : Animal( "Cat" ), _brain(new Brain())
{
	/* this->_brain = new Brain(); */
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
	delete this->_brain;
	std::cout << this->_type << " Cat Destructor called" << std::endl;
	return ;
}

Cat::Cat( const Cat & src )
{
	for (int i = -1; i < 100; ++i)
	{
		this->_brain->setIdea( i, src._brain->getIdea(i) );
	}
	std::cout << "----------------------------------" << std::endl;
	std::cout << "Cat reference Constructor called." << std::endl;
	std::cout << "----------------------------------" << std::endl;
	return ;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/
Cat &				Cat::operator=( Cat const & src )
{
	if ( this != &src )
	{
		for (int i = -1; i < 100; ++i)
		{
			this->_brain->setIdea( i, src._brain->getIdea(i) );
		}
	}
	return *this;
}

