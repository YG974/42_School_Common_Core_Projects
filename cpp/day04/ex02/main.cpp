#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
	std::cout << "\n---- ARRAY TEST ----\n" << std::endl;

	Animal* array[4];
	/* Animal	abstract; */

	array[0] = new Dog();
	array[1] = new Dog();
	array[2] = new Cat();
	array[3] = new Cat();

	array[0]->makeSound();
	array[1]->makeSound();
	array[2]->makeSound();
	array[3]->makeSound();

	delete array[0];
	delete array[1];
	delete array[2];
	delete array[3];
}
