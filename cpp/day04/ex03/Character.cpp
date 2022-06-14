#include "Character.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Character::Character()
{
	for ( int i = 0; i < 4; i++)
		this->Inventory[i] = NULL;
	/* std::cout << "----------------------------------" << std::endl; */
	/* std::cout << "Character Default Constructor called." << std::endl; */
	/* std::cout << "Name : " << this->_name << std::endl; */
	/* std::cout << "----------------------------------" << std::endl; */
	return ;
}

Character::Character ( std::string name ) : _name ( name )
{
	for ( int i = 0; i < 4; i++)
		this->Inventory[i] = NULL;
	/* std::cout << "----------------------------------" << std::endl; */
	/* std::cout << "Character init Constructor called." << std::endl; */
	/* std::cout << "Name : " << this->_name << std::endl; */
	/* std::cout << "----------------------------------" << std::endl; */
	return ;
}

Character::Character( const Character & src ) : _name ( src._name )
{
	/* std::cout << "----------------------------------" << std::endl; */
	/* std::cout << "Character Copy Constructor called." << std::endl; */
	/* std::cout << "Name : " << this->_name << std::endl; */
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

Character::~Character()
{
	/* std::cout << "----------------------------------" << std::endl; */
	/* std::cout << "Character Destructor called." << std::endl; */
	/* std::cout << "----------------------------------" << std::endl; */
	for ( int i = 0; i < 4; i++)
	{
		if (this->Inventory[i])
			delete (this->Inventory[i]);
	}
	return ;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Character &				Character::operator=( Character const & src )
{
	this->_name = src._name;
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

// In case we try to equip a Materia in a full inventory, or use/unequip a nonexistent Materia, don’t do a thing.
void Character::equip(AMateria* m)
{
	if ( m == NULL)
		return ;
	for ( int i = 0; i < 4; i++)
	{
		if (this->Inventory[i] == NULL)
		{
			this->Inventory[i] = m;
			return ;
		}
	}
}

// The unequip method must NOT delete Materia!
void Character::unequip(int idx)
{
	if (idx > 3 || idx < 0)
		return ;
	this->Inventory[idx] = NULL;
}

// The use(int, ICharacter&) method will have to use the Materia at the idx slot,
// and pass target as parameter to the AMateria::use method.
void Character::use(int idx, ICharacter& target)
{
	if (idx > 3 || idx < 0 || !this->Inventory[idx])
		return ;
	this->Inventory[idx]->use(target);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string const & Character::getName( void ) const
{
	return ( this->_name ) ;
}


/* ************************************************************************** */
