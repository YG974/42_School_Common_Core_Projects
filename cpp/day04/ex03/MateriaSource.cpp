#include "MateriaSource.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

MateriaSource::MateriaSource()
{
	/* std::cout << "----------------------------------" << std::endl; */
	/* std::cout << "MateriaSource Default Constructor called." << std::endl; */
	/* std::cout << "----------------------------------" << std::endl; */
	for ( int i = 0; i < 4; i++)
		this->Inventory[i] = NULL;
	return ;
}

MateriaSource::MateriaSource( const MateriaSource & src )
{
	/* std::cout << "----------------------------------" << std::endl; */
	/* std::cout << "MateriaSource Copy Constructor called." << std::endl; */
	/* std::cout << "----------------------------------" << std::endl; */
	for ( int i = 0; i < 4; i++)
	{
		if (src.Inventory[i])
			this->Inventory[i] = src.Inventory[i]->clone();
	}
	return ;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

MateriaSource::~MateriaSource()
{
	/* std::cout << "----------------------------------" << std::endl; */
	/* std::cout << "MateriaSource Destructor called." << std::endl; */
	/* std::cout << "----------------------------------" << std::endl; */
	for ( int i = 0; i < 4; i++)
	{
		if (this->Inventory[i])
			delete this->Inventory[i];
	}
	return ;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

MateriaSource & MateriaSource::operator=( MateriaSource const & src )
{
	for ( int i = 0; i < 4; i++)
	{
		if (src.Inventory[i])
			this->Inventory[i] = src.Inventory[i]->clone();
	}
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

// learnMateria must copy the Materia passed as a parameter, and store it in memory to be cloned later. Much in the same way as for Character , the Source can know at most 4 Materia, which are not necessarily unique.
void MateriaSource::learnMateria(AMateria* src)
{
	for ( int i = 0; i < 4; i++)
	{
		if (this->Inventory[i] == NULL)
		{
			 this->Inventory[i] = src;
			 return ;
		}
	}
}

// createMateria(std::string const &) will return a new Materia, which will be a copy of the Materia (previously learned by the Source) which type equals the parameter. Returns 0 if the type is unknown.
AMateria* MateriaSource::createMateria(std::string const & type)
{
	for ( int i = 0; i < 4; i++)
	{
		if (this->Inventory[i] && this->Inventory[i]->getType() == type)
			 return (this->Inventory[i]->clone());
	}
	return ( 0 );
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
