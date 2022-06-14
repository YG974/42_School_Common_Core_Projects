#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	// Constructors
	std::cout << "\n---------------------------------------------" << std::endl;
	std::cout << "Constructor Exceptions" << std::endl;
	std::cout << "---------------------------------------------\n" << std::endl;

	Bureaucrat				bur ("titi", 149);
	Bureaucrat				boss ("titi", 1);
	ShrubberyCreationForm	test ("michel");
	RobotomyRequestForm		rob ("bot");
	PresidentialPardonForm	manu ("manu");
	
	
	std::cout << "\n---------------------------------------------" << std::endl;
	std::cout << "ShrubberyCreationForm" << std::endl;
	std::cout << "---------------------------------------------\n" << std::endl;
	test.beSigned(bur);
	test.beSigned(boss);
	bur.executeForm(test);
	boss.executeForm(test);

	std::cout << "\n---------------------------------------------" << std::endl;
	std::cout << "RobotomyRequestForm" << std::endl;
	std::cout << "---------------------------------------------\n" << std::endl;
	rob.beSigned(boss);
	boss.executeForm(rob);
	boss.executeForm(rob);
	boss.executeForm(rob);
	boss.executeForm(rob);

	std::cout << "\n---------------------------------------------" << std::endl;
	std::cout << "PresidentialPardonForm" << std::endl;
	std::cout << "---------------------------------------------\n" << std::endl;
	manu.beSigned(boss);
	boss.executeForm(manu);
	boss.executeForm(manu);
	boss.executeForm(manu);

	/* std::cout << "Normal Bureaucrat." << std::endl; */
	// Normal
}
