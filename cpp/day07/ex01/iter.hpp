#include <cstdlib>
#include <string>
#include <iostream>
#include <typeinfo>
#include <locale>
#include <climits>
#include <cfloat>

template <typename T>
void iter ( T  *array_adress, size_t len, void (&function_ref)(T const &) )
{
	for ( size_t i = 0 ; i < len ; i++ )
		function_ref(array_adress[i]);
}
