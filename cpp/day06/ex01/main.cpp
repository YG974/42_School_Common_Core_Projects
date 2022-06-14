#include <string>
#include <iostream>
#include <typeinfo>
#include <locale>
#include <climits>
#include <cfloat>
#include <cstdlib>
#include <stdint.h>

typedef struct  Data
{
	int				i;
	float			f;
	std::string		str;
}				Data;

uintptr_t serialize(Data* ptr)
{
	uintptr_t new_ptr = reinterpret_cast<uintptr_t>(ptr);
	/* uintptr_t new_ptr = (uintptr_t)ptr; */

	return (new_ptr);
}

Data* deserialize(uintptr_t raw)
{
	Data	*new_ptr = reinterpret_cast<Data*>(raw);
	/* Data	*new_ptr = (Data*)raw; */

	return (new_ptr);
}

int main ( void )
{
	Data	x = { 4, 3.14159265, "string test"};

	uintptr_t	integer_ptr;
	Data		*regular_ptr;

	integer_ptr = serialize(&x);
	regular_ptr = deserialize(integer_ptr);
	

	std::cout << "original ptr : " << &x << std::endl;
	std::cout << "serialize ptr : " << integer_ptr << std::endl;
	/* std::cout << "serialize casted ptr : " << (void*)integer_ptr << std::endl; */
	std::cout << "deserialize ptr : " << regular_ptr << std::endl;


	return (0);
}
