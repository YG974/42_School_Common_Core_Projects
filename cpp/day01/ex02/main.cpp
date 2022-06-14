#include <string>
#include <iostream>

int		main( void )
{
	std::string		str = "HI THIS IS BRAIN";
	std::string		*stringPTR = &str;
	std::string		&stringREF = str;

	std::cout << "-----------------------------------------------\n";
	std::cout << "ADDRESSES :                                    |\n";
	std::cout << "-----------------------------------------------|\n";
	std::cout << "String    address \'&str\'      : ";
	std::cout << &str << " |" << std::endl;
	std::cout << "StringPTR address \'stringPTR\' : ";
	std::cout << stringPTR << " |" << std::endl;
	std::cout << "StringREF address \'&stringREF\': ";
	std::cout << &stringREF << " |" << std::endl;

	std::cout << "-----------------------------------------------|\n";
	std::cout << "STRINGS :                                      |\n";
	std::cout << "-----------------------------------------------|\n";
	std::cout << "String    \'str\'        : ";
	std::cout << str << "      |" << std::endl;
	std::cout << "StringPTR \'*stringPTR\' : ";
	std::cout << *stringPTR << "      |" << std::endl;
	std::cout << "StringREF \'stringREF\'  : ";
	std::cout << stringREF << "      |" << std::endl;
	std::cout << "-----------------------------------------------\n";
	return (0);
}
