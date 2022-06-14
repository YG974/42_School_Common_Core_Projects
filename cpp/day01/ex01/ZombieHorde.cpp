#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie	*zombie = new Zombie[N] ();
	std::cout << "----------------------\n";

	while (N-- > 0)
	{
		zombie[N].setName(name);
		std::cout << "Object number " << N << " : -> ";
		zombie[N].announce();
	}
	std::cout << "----------------------\n";
	return (zombie);
}
