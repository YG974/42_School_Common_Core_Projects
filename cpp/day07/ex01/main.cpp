#include <cstdlib>
#include <string>
#include <iostream>
#include <typeinfo>
#include <locale>
#include <climits>
#include <cfloat>

#include "iter.hpp"

template <typename T>
void print_template (T & ref)
{
	std::cout << "Value of the element : " << ref << std::endl;
}

int main ( void )
{
	int		len = 10;
	int		nb[10] = {1, 3, 12, 4, 2, 3, 1, 9, 13, 15};
	char	c[10] = { 'a', '/', '$', '*', ')', '#', '@', '!', '%', '='};

	std::cout << "\n --- SOME INT ---- \n" << std::endl;
	::iter(nb, len, print_template);

	std::cout << "\n --- SOME CHAR ---- \n" << std::endl;
	::iter(c, len, print_template);

	return (0);
}
