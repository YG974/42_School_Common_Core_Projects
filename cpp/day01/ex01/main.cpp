#include "Zombie.hpp"

int		main( void )
{
	Zombie	*robert = NULL;
	Zombie	*michel = NULL;

	// Michel
	michel = zombieHorde ( 5, "michel");
	std::cout << "DELETE michel";
	std::cout << "\n----------------------\n";
	delete [] michel;
	std::cout << "----------------------\n";

	// robert
	robert = zombieHorde( 3, "robert");
	std::cout << "DELETE robert";
	std::cout << "\n----------------------\n";
	delete [] robert;
	std::cout << "----------------------\n";

	std::cout << "return hihi\n";
	return (0);
}
