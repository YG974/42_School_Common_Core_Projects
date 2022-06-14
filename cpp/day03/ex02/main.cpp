#include <string>
#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main( void )
{
	ClapTrap	fifi ("michel", 10, 10, 0);
	ScavTrap	riri ("Djimmy");
	FragTrap	loulou ("Christiano");

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
	std::cout << " GUARD GATE" << std::endl;
	riri.guardGate();
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
	return (0);
}
