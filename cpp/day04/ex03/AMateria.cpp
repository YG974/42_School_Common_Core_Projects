#include "AMateria.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

// Default
AMateria::AMateria()
{
	/* std::cout << "----------------------------------" << std::endl; */
	/* std::cout << "AMateria Default Constructor called." << std::endl; */
	/* std::cout << "Type : " << this->_type << std::endl; */
	/* std::cout << "----------------------------------" << std::endl; */
	return ;
}

// Copy
AMateria::AMateria( const AMateria & src ) : _type (src._type)
{
	/* std::cout << "----------------------------------" << std::endl; */
	/* std::cout << "AMateria Copy Constructor called." << std::endl; */
	/* std::cout << "Type : " << this->_type << std::endl; */
	/* std::cout << "----------------------------------" << std::endl; */
	return ;
}

// init
AMateria::AMateria( std::string const & type ) : _type ( type )
{
	/* std::cout << "----------------------------------" << std::endl; */
	/* std::cout << "AMateria init Constructor called." << std::endl; */
	/* std::cout << "Type : " << this->_type << std::endl; */
	/* std::cout << "----------------------------------" << std::endl; */
	return ;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AMateria::~AMateria()
{
	/* std::cout << "----------------------------------" << std::endl; */
	/* std::cout << "AMateria Default Destructor called." << std::endl; */
	/* std::cout << "Type : " << this->_type << std::endl; */
	/* std::cout << "----------------------------------" << std::endl; */
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

// Assignation
AMateria &				AMateria::operator=( AMateria const & rhs )
{
	if ( this != &rhs )
	{
		this->_type = rhs.getType();
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/
void AMateria::use( ICharacter& target )
{
	(void)target;
	return ;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string const & AMateria::getType( void ) const
{
	return (this->_type);
}


/* ************************************************************************** */
