#include <string>
#include <iostream>
#include "ClapTrap.hpp"

int main( void )
{
	ClapTrap	test ("michel");

	std::cout << "ATTACK" << std::endl;
	test.attack ("Roberto");
	std::cout << "----------------------------------" << std::endl;
	std::cout << "TAKE DAMAGE" << std::endl;
	test.takeDamage (2);
	test.takeDamage (2);
	std::cout << "----------------------------------" << std::endl;
	std::cout << "BE REPAIRED" << std::endl;
	test.beRepaired (2);
	std::cout << "----------------------------------" << std::endl;
	return (0);
}
