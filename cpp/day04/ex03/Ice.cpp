#include "Ice.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Ice::Ice() : AMateria ( "ice" )
{
	/* std::cout << "----------------------------------" << std::endl; */
	/* std::cout << "Ice Default Constructor called." << std::endl; */
	/* std::cout << "----------------------------------" << std::endl; */
	return ;
}

Ice::Ice( const Ice & src ) : AMateria ( "ice" )
{
	/* std::cout << "----------------------------------" << std::endl; */
	/* std::cout << "Ice Copy Constructor called." << std::endl; */
	/* std::cout << "----------------------------------" << std::endl; */

	*this = src;

	return ;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Ice::~Ice()
{
	/* std::cout << "----------------------------------" << std::endl; */
	/* std::cout << "Ice Destructor called." << std::endl; */
	/* std::cout << "----------------------------------" << std::endl; */
	return ;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

// Assignation
Ice &				Ice::operator=( Ice const & src )
{
	AMateria::operator=(src);
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

AMateria * Ice::clone( void ) const
{
	AMateria *cloned_materia = new Ice();

	*cloned_materia = *this;

	return ( cloned_materia );
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *";
	std::cout << std::endl;
	AMateria::use(target);
	return ;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
