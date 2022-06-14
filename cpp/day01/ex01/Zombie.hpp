#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>

class	Zombie
{
	private :

		std::string		_name;

	public :

		void announce (void);
		void setName( std::string name );
		Zombie( std::string name );	//init Constructor
		Zombie();	//Constructor
		~Zombie();	//Destructor

		// Non member var & functions
		static int		nbZombie;
};

Zombie* zombieHorde( int N, std::string name );

#endif
