#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	// Constructors
	Intern  someRandomIntern;
	Form*   rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	rrf = someRandomIntern.makeForm("presidential pardon", "manu");
	rrf = someRandomIntern.makeForm("shrubbery creation", "tree");
	rrf = someRandomIntern.makeForm("random name", "looser");


	/* std::cout << "Normal Bureaucrat." << std::endl; */
	// Normal
}
