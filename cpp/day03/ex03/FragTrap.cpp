#include "FragTrap.hpp"

void	FragTrap::highFivesGuys ( void )
{
	std::cout << "FragTrap " << this->_name;
	std::cout << " wants you to high-five ! High-five him !" << std::endl;
	std::cout << "FRAG PIOU PIOU" << std::endl;

	return ;
}

/*
 * init Constructor
 */
FragTrap::FragTrap ( std::string name ) : ClapTrap (name, 100, 100, 30)
{
	std::cout << "----------------------------------" << std::endl;
	std::cout << "FragTrap init Constructor called." << std::endl;
	std::cout << "FRAG PIOU PIOU" << std::endl;
	std::cout << "Name : " << this->_name << std::endl;
	std::cout << "Hit_points : " << this->_Hit_points << std::endl;
	std::cout << "Energy_points : " << this->_Energy_points << std::endl;
	std::cout << "Attack_damage : " << this->_Attack_damage << std::endl;
	std::cout << "----------------------------------" << std::endl;
	return ;
}

/*
 * Default Destructor
 */
FragTrap::~FragTrap()
{
	std::cout << this->_name << " FragTrap Destructor called" << std::endl;
	std::cout << "FRAG PIOU PIOU" << std::endl;
	return ;
}
