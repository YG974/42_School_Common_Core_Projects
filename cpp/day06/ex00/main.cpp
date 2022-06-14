#include <string>
#include <iostream>
#include <typeinfo>
#include <locale>
#include <climits>
#include <cfloat>
#include <cstdlib>

int main (int ac, char **av)
{
	if (ac != 2 || !av)
	{
		std::cerr << "Wrong argument number." << std::endl;
		std::cerr << "Usage : \'./Convert <arg>\'" << std::endl;
		return (0);
	}

	std::string input = av[1];
	bool		nan = false;

	std::cout.setf( std::ios::fixed, std:: ios::floatfield );
	std::cout <<   std::showpoint;
	std::cout.precision (1);

	/* https://cplusplus.com/reference/typeinfo/type_info/name/ */
	/* int isprint ( int c ); */
	char	c = static_cast<char>(atoi(av[1]));
	int		i = static_cast<int>(atoi(av[1]));
	float	f = static_cast<double>(atof(av[1]));
	double	d = static_cast<double>(atof(av[1]));

	long	nb = atol(av[1]);

	// CHAR
	if (	input.compare("nan") == 0 || input.compare("nanf") == 0 ||
			input.compare("inf") == 0 || input.compare("-inf") == 0 ||
			input.compare("+inf") == 0 || input.compare("inff") == 0 ||
			input.compare("-inff") == 0 || input.compare("+inff") == 0 ||
			input.compare("inff") == 0 )
	{
		nan = true;
	}
	if ( nan == true || nb < CHAR_MIN || nb > CHAR_MAX)
		std::cout << "Char : impossible" << std::endl;
	else if (isprint(i) == 0)
		std::cout << "Char : Non displayable" << std::endl;
	else
		std::cout << "Char : '" << c << "'" <<  std::endl;

	// INT
	if (nan == true || nb < INT_MIN || nb > INT_MAX)
		std::cout << "Int : impossible" << std::endl;
	else
		std::cout << "Int : " << i << std::endl;

	// FLOAT
	std::cout << "Float : " << f << "f" <<  std::endl;
	// DOUBLE
	std::cout << "Double : " << d << std::endl;

	return (0);
}
