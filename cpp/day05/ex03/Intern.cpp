#include "Intern.hpp"

/*
 * init Constructor
 */
Intern::Intern ( void )
{
	std::cout << "----------------------------------" << std::endl;
	std::cout << "Intern Default Constructor called." << std::endl;
	std::cout << "----------------------------------" << std::endl;
	return ;
}

/*
 * Copy Constructor
 */
Intern::Intern(const Intern& obj)
{
	std::cout << "Copy Constructor called" << std::endl;
	*this = obj;
}

/*
 * Assignation operator
 */
Intern&	Intern::operator=(const Intern& obj)
{
	(void)obj;
	std::cout << "Assignation operator called" << std::endl;
	return *this;
}

/*
 * Default Destructor
 */
Intern::~Intern()
{
	std::cout << "Intern Destructor called";
	std::cout << std::endl;
	return ;
}

Form* Intern::Robotomy (std::string target)
{
	return (new RobotomyRequestForm(target));
}

Form* Intern::Shrubbery (std::string target)
{
	return (new ShrubberyCreationForm(target));
}

Form* Intern::Presidential (std::string target)
{
	return (new PresidentialPardonForm(target));
}

// Methods

Form* Intern::makeForm (std::string form, std::string target)
{
	std::string index[3] = {	"robotomy request",
								"shrubbery creation",
								"presidential pardon" };
	this->function_tab[0] = &Intern::Robotomy;
	this->function_tab[1] = &Intern::Presidential;
	this->function_tab[2] = &Intern::Shrubbery;
	for (int i = 0 ; i < 3 ; i++)
	{
		if ( form.compare(index[i]) == 0 )
		{
			std::cout << "Intern creates " << index[i] << std::endl;
			return ((this->*function_tab[i])(target));
		}
	}
	std::cerr << "Counldn't create \'" << form << "\' Form." << std::endl;
	std::cerr << "Form wasn't found." << std::endl;
	return (NULL);
}
