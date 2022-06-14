#include <cstdlib>
#include <iterator>
#include <string>
#include <iostream>
#include <typeinfo>
#include <locale>
#include <climits>
#include <cfloat>
#include <list>
#include <algorithm>

template <typename T>
int easyfind ( T container, int nb )
{
	if ( std::find( container.begin(), container.end(), nb ) != container.end())
	{
		std::cout << "Value found : \'" << nb << "\'." << std::endl;
		return ( nb );
	}
	else
		std::cerr << "Sorry, value \'" << nb << "\' wasn't found." << std::endl;
	return (0) ;
}
