#include "Cure.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cure::Cure() : AMateria ( "cure" )
{
	/* std::cout << "----------------------------------" << std::endl; */
	/* std::cout << "Cure Default Constructor called." << std::endl; */
	/* std::cout << "----------------------------------" << std::endl; */
	return ;
}

Cure::Cure( const Cure & src ) : AMateria ( "cure" )
{
	/* std::cout << "----------------------------------" << std::endl; */
	/* std::cout << "Cure Copy Constructor called." << std::endl; */
	/* std::cout << "----------------------------------" << std::endl; */

	*this = src;

	return ;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cure::~Cure()
{
	/* std::cout << "----------------------------------" << std::endl; */
	/* std::cout << "Cure Destructor called." << std::endl; */
	/* std::cout << "----------------------------------" << std::endl; */
	return ;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

// Assignation
Cure &				Cure::operator=( Cure const & src )
{
	AMateria::operator=(src);
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

AMateria * Cure::clone( void ) const
{
	AMateria *cloned_materia = new Cure();

	*cloned_materia = *this;

	return ( cloned_materia );
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
	AMateria::use(target);
	return ;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
