#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
	std::cout << "\n---- LEAK TEST ----\n" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;//should not create a lea
	delete i;

	std::cout << "\n---- ARRAY TEST ----\n" << std::endl;

	Animal* array[4];

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

	std::cout << "\n---- DEEP COPY----\n" << std::endl;

	Dog		basic;


	std::cout << "\n---- SET IDEAS ----" << std::endl;
	basic.setIdea(0, "boohoo");
	basic.setIdea(1, "idee deux");
	basic.printIdeas();

	std::cout << "\n---- Dog tmp = basic ----" << std::endl;
	Dog		tmp = basic;

	std::cout << "\n---- set new idea ----" << std::endl;
	tmp.setIdea(2, "new and private");
	std::cout << "\n---- print tmp ----" << std::endl;
	tmp.printIdeas();
	std::cout << "\n---- print basic ----" << std::endl;
	basic.printIdeas();
}
