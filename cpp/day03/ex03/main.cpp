#include <string>
#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

// TO UNDERSTAND DIAMOND PROBLEM
// https://stackoverflow.com/questions/55829798/c-diamond-problem-how-to-call-base-method-only-once

int main( void )
{
	std::cout << "\n\nCLAPTRAP" << std::endl;
	ClapTrap	fifi ("michel", 10, 10, 0);
	std::cout << "\n\nSCAVTRAP" << std::endl;
	ScavTrap	riri ("Djimmy");
	std::cout << "\n\nFRAGTRAP" << std::endl;
	FragTrap	loulou ("Christiano");
	std::cout << "\n\nDIAMONDTRAP" << std::endl;
	DiamondTrap	thierry ("thibaud");

	std::cout << "\n\nCLAPTRAP" << std::endl;
	std::cout << "----------------------------------" << std::endl;
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
	std::cout << "\n\nSCAVTRAP" << std::endl;
	std::cout << "----------------------------------" << std::endl;
	riri.attack ("Roberto");
	std::cout << "----------------------------------" << std::endl;
	std::cout << "TAKE DAMAGE" << std::endl;
	riri.takeDamage (2);
	riri.takeDamage (2);
	std::cout << "----------------------------------" << std::endl;
	std::cout << "BE REPAIRED" << std::endl;
	riri.beRepaired (2);
	std::cout << "----------------------------------" << std::endl;
	std::cout << " GUARD GATE" << std::endl;
	riri.guardGate();
	std::cout << "----------------------------------" << std::endl;
	std::cout << "\n\nFRAGTRAP" << std::endl;
	std::cout << "----------------------------------" << std::endl;
	loulou.attack ("Roberto");
	std::cout << "----------------------------------" << std::endl;
	std::cout << "TAKE DAMAGE" << std::endl;
	loulou.takeDamage (2);
	loulou.takeDamage (2);
	std::cout << "----------------------------------" << std::endl;
	std::cout << "BE REPAIRED" << std::endl;
	loulou.beRepaired (2);
	std::cout << "----------------------------------" << std::endl;
	std::cout << " HIGH FIVE !" << std::endl;
	loulou.highFivesGuys();
	std::cout << "----------------------------------" << std::endl;
	std::cout << "\n\nDIAMONDTRAP" << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "TAKE DAMAGE" << std::endl;
	thierry.takeDamage(2);
	std::cout << "----------------------------------" << std::endl;
	std::cout << "GUARD GATE" << std::endl;
	thierry.guardGate();
	std::cout << "----------------------------------" << std::endl;
	std::cout << " HIGH FIVE !" << std::endl;
	thierry.highFivesGuys();
	std::cout << "----------------------------------" << std::endl;
	std::cout << "ATTACK" << std::endl;
	thierry.attack("bolos");
	std::cout << "----------------------------------" << std::endl;
	std::cout << "WHOAMI" << std::endl;
	thierry.whoAmI();
	std::cout << "----------------------------------" << std::endl;
	std::cout << std::endl;
	return (0);
}
