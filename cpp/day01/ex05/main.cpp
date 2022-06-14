#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include "Karen.hpp"

int		main( int ac, char **av )
{
	(void)ac;
	(void)av;

	Karen	kar;

	kar.complain("error");
	kar.complain("warning");
	kar.complain("info");
	kar.complain("debug");

	return (0);
}
