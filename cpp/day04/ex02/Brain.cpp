#include "Brain.hpp"
#include <string>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/


Brain::Brain()
{
	std::cout << "----------------------------------" << std::endl;
	std::cout << "Brain default Constructor called." << std::endl;
	std::cout << "----------------------------------" << std::endl;
	/* for (int i = 0; i < 100; i++) */
	/* { */
	/* 	this->_ideas[i] = word[i]; */
	/* 	std::cout << i << " -> " << this->_ideas[i]<< std::endl; */
	/* } */
	return ;
}

Brain::Brain( const Brain & src )
{
	for (int i = 0; i < 100; i++)
	{
		this->_ideas[i] = src._ideas[i];
	}
	std::cout << "----------------------------------" << std::endl;
	std::cout << "Brain reference Constructor called." << std::endl;
	std::cout << "----------------------------------" << std::endl;
	return ;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Brain::~Brain()
{
	std::cout << "----------------------------------" << std::endl;
	std::cout << "Brain default Destructor called." << std::endl;
	std::cout << "----------------------------------" << std::endl;
	return ;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Brain &				Brain::operator=( Brain const & src )
{
	if ( this != &src )
	{
		for (int i = 0; i < 100; i++)
		{
			this->_ideas[i] = src._ideas[i];
		}
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Brain::setIdea( int i , std::string str)
{
	if ( i < 0 || i > 99 )
	{
		std::cout << "Set idea number is out of brain !" << std::endl;
		return ;
	}
	else if ( ! str.empty() )
	{
		this->_ideas[i] = str;
		std::cout << "Idea nb " << i + 1 << " sucessfuly added : \' ";
		std::cout << str << "\'." << std::endl;
	}
	return ;
}

void Brain::printIdeas( void ) const
{
	for (int i = 0; i < 100; i++)
	{
		if ( ! _ideas[i].empty() )
		{
			std::cout << "Idea nb " << i + 1 << " : \'" << _ideas[i] << "\'.";
			std::cout << std::endl;
		}
	}
	return ;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string Brain::getIdea( int i ) const
{
	if ( i < 0 || i > 99 )
		return ("Idea requested is out of brain !\n");
	return (this->_ideas[i]);
}

/* ************************************************************************** */
