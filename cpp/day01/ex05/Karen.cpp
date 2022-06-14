#include "Karen.hpp"

// PRIVATE FUNCTIONS
void Karen::debug( void )
{
	std::cout << "This is a DEBUG message my Friend." << std::endl;
	return ;
}
void Karen::info( void )
{
	std::cout << "This is an INFORMATIVE message my Friend." << std::endl;
	return ;
}
void Karen::warning( void )
{
	std::cout << "This is a WARNING message. BE CAREFUL MAN !" << std::endl;
	return ;
}
void Karen::error( void )
{
	std::cout << "This is an ERROR message my Friend. BIG ERROR!" << std::endl;
	return ;
}

const Karen::function_pointers_tab Karen::function_tab[] =
{
	{ "debug", &Karen::debug},
	{"info", &Karen::info},
	{"warning", &Karen::warning},
	{"error", &Karen::error},
};

// PUBLIC FUNCTIONS
void Karen::complain( std::string level )
{
	int i = -1;

	while (++i <= 3)
	{
		if ( Karen::function_tab[i].function_name == level )
		{
			(this->*function_tab[i].function_pointer)();
			break ;
		}
	}
	return ;
}

/*
 * Default Constructor
 */
Karen::Karen()
{
	std::cout << "Default Constructor called" << std::endl;
	return ;
}

/*
 * Default Destructor
 */
Karen::~Karen()
{
	std::cout << "Default Destructor called" << std::endl;
	return ;
}

