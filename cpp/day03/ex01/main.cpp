#include <string>
#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main( void )
{
	ClapTrap	fifi ("michel");
	ScavTrap	riri ("Djimmy");

	std::cout << "ATTACK" << std::endl;
	fifi.attack ("Roberto");
	std::cout << "----------------------------------" << std::endl;
	std::cout << "TAKE DAMAGE" << std::endl;
	fifi.takeDamage (2);
	fifi.takeDamage (2);
	std::cout << "----------------------------------" << std::endl;
	std::cout << "BE REPAIRED" << std::endl;
	fifi.beRepaired (2);
	std::cout << "----------------------------------" << std::endl;
	std::cout << "ATTACK" << std::endl;
	riri.attack ("Roberto");
	std::cout << "----------------------------------" << std::endl;
	std::cout << "TAKE DAMAGE" << std::endl;
	riri.takeDamage (2);
	riri.takeDamage (2);
	std::cout << "----------------------------------" << std::endl;
	std::cout << "BE REPAIRED" << std::endl;
	riri.beRepaired (2);
	std::cout << "----------------------------------" << std::endl;
	std::cout << "GUARD GATE" << std::endl;
	riri.guardGate();
	std::cout << "----------------------------------" << std::endl;
	return (0);
}
