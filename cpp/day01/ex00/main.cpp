#include "Zombie.hpp"

int		main( void )
{
	Zombie	michel;
	Zombie	*robert = NULL;

	// Michel stack 
	michel.announce();
	michel.setName("michel");
	michel.announce();
	std::cout << "\n----------------------\n";

	// robert heap
	robert = newZombie("robert");
	std::cout << "DELETE \n";
	delete robert;
	std::cout << "\n----------------------\n";

	// arnold heap random chump
	randomChump ("Arnold");

	std::cout << "\n----------------------\n";
	std::cout << "return hihi\n";
	return (0);
}
