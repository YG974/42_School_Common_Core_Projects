#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

int main()
{
	// Constructors
	std::cout << "\n---------------------------------------------" << std::endl;
	std::cout << "Constructor Exceptions" << std::endl;
	std::cout << "---------------------------------------------\n" << std::endl;

	std::cout << "Normal Bureaucrat." << std::endl;
	// Normal
	try
	{
		Bureaucrat normal ("michel", 70);
		std::cout << normal;
	}
	catch ( std::exception & e )
	{
		std::cerr << "Exception caught -> " << e.what() << std::endl;
	}

	std::cout << "\n\nLow Bureaucrat." << std::endl;
	// Low
	try
	{
		Bureaucrat low ("Leon", 0);
		std::cout << low;
		std::cout << low.getName() << " Bureaucrat has a grade of ";
		std::cout << low.getGrade() << std::endl;
	}
	catch ( std::exception & e )
	{
		std::cerr << "Exception caught -> " << e.what() << std::endl;
	}

	std::cout << "\n\nHigh Bureaucrat." << std::endl;
	// High
	try
	{
		Bureaucrat High ("Robert", 170);
		std::cout << High;
		std::cout << High.getName() << " Bureaucrat has a grade of ";
		std::cout << High.getGrade() << std::endl;
	}
	catch ( std::exception & e )
	{
		std::cerr << "Exception caught -> " << e.what() << std::endl;
	}

	std::cout << "\n---------------------------------------------" << std::endl;
	std::cout << "Increment and decrement exceptions" << std::endl;
	std::cout << "---------------------------------------------\n" << std::endl;
	
	std::cout << "Decrement Bureaucrat." << std::endl;
	// Decrement
	try
	{
		Bureaucrat Decrement ("Robert", 140);

		while (1)
			Decrement.decremente_grade();
	}
	catch ( std::exception & e )
	{
		std::cerr << "Exception caught -> " << e.what() << std::endl;
	}

	std::cout << "\n\nIncrement Bureaucrat." << std::endl;
	// Decrement
	try
	{
		Bureaucrat Increment ("Robert", 10);

		while (1)
			Increment.incremente_grade();
	}
	catch ( std::exception & e )
	{
		std::cerr << "Exception caught -> " << e.what() << std::endl;
	}
}
