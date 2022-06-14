#include "Dog.hpp"
#include "Animal.hpp"

void Dog::setIdea(int i, std::string str)
{
	return ( this->_brain->setIdea( i, str ) );
}

void Dog::printIdeas( void ) const
{
	return ( this->_brain->printIdeas() );
}

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
	this->_brain = new Brain();
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
	this->_brain = new Brain();
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
	delete this->_brain;
	std::cout << this->_type << " Dog Destructor called" << std::endl;
	return ;
}

Dog::Dog( const Dog & src ) : _brain(new Brain())
{
	for (int i = -1; i < 100; ++i)
	{
		this->_brain->setIdea( i, src._brain->getIdea(i) );
	}
	std::cout << "----------------------------------" << std::endl;
	std::cout << "Dog reference Constructor called." << std::endl;
	std::cout << "----------------------------------" << std::endl;
	return ;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/
Dog &				Dog::operator=( Dog const & src )
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

