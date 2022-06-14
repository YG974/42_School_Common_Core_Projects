#ifndef INTERN_HPP
# define INTERN_HPP

#include <string>
#include <iostream>
#include <fstream>
#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Form;

class	Intern
{
	private:
		// Tab
		Form* (Intern::*function_tab[3]) (std::string target);
		// Functions
		Form* Robotomy (std::string target);
		Form* Shrubbery (std::string target);
		Form* Presidential (std::string target);

	public :

		// Constructors
		// Default Constructor
		Intern ( void );
		// Copy Constructor
		Intern ( Intern const & src );

		// Assignation
		Intern &operator= (const Intern & src);


		// Methods
		Form* makeForm (std::string form, std::string target);

		// Destructors
		~Intern();

};

#endif
