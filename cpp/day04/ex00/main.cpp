#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() 
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " \n" << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	std::cout << "\n-- WRONG -- " << std::endl;

	const WrongAnimal* hihi = new WrongAnimal();
	const WrongAnimal* hoho = new WrongCat();
	const WrongCat *kitty = new WrongCat();

	std::cout << hoho->getType() << " " << std::endl;
	hihi->makeSound();
	hoho->makeSound();
	kitty->makeSound();
	std::cout << "\n-- DELETE -- " << std::endl;

	delete meta;
	delete i;
	delete j;
	delete hihi;
	delete hoho;
	delete kitty;
}
