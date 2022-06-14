#include <cstdlib>
#include <string>
#include <iostream>
#include <typeinfo>
#include <locale>
#include <climits>
#include <cfloat>
#include <list>

#include "easyfind.hpp"

int main ( void )
{
	std::cout << "\n--- List container of ints ---\n" << std::endl;

	std::list<int>	my_list;

	my_list.push_back(1);
	my_list.push_back(11);
	my_list.push_back(13);
	my_list.push_back(5);
	my_list.push_back(2);
	my_list.push_back(191);

	::easyfind(my_list, 12);
	::easyfind(my_list, 11);
	::easyfind(my_list, 5);
	::easyfind(my_list, 191);
	::easyfind(my_list, 55);

	my_list.push_back(12);
	::easyfind(my_list, 12);
	return (0);
}
