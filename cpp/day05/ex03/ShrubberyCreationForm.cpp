#include "ShrubberyCreationForm.hpp"

/*
 * init Constructor
 */
ShrubberyCreationForm::ShrubberyCreationForm ( std::string target) :
	Form ( "ShrubberyCreationForm", 145,  137 , target )
{
	std::cout << "----------------------------------" << std::endl;
	std::cout << "ShrubberyCreationForm init Constructor called." << std::endl;
	std::cout << "Name : " <<  this->getName() << std::endl;
	std::cout << "Signed : " << this->getSigned() << std::endl;
	std::cout << "signGrade : " << this->getSignGrade() << std::endl;
	std::cout << "exec_grade : " << this->getExecGrade() << std::endl;
	std::cout << "----------------------------------" << std::endl;
	if ( this->getSignGrade() < 1 )
		throw ShrubberyCreationForm::GradeTooLowException();
	if ( this->getSignGrade() > 150 )
		throw ShrubberyCreationForm::GradeTooHighException();
	return ;
}

/*
 * Default Destructor
 */
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << this->getName() << " ShrubberyCreationForm Destructor called";
	std::cout << std::endl;
	return ;
}


// Methods

// Execute
void ShrubberyCreationForm::exec(Bureaucrat const & executor) const
{
	(void)executor;

	std::string file_name = this->getTarget() + "_shruberry";
	std::ofstream output ( file_name );
	
	if (!output.good())
		std::cerr << "Failed opening output file." << std::endl;

	output << "    _\\/_" << std::endl;
	output << "     /\\" << std::endl;
	output << "     /\\" << std::endl;
	output << "    /  \\" << std::endl;
	output << "    /~~\\o" << std::endl;
	output << "   /o   \\" << std::endl;
	output << "  /~~*~~~\\" << std::endl;
	output << " o/    o \\" << std::endl;
	output << " /~~~~~~~~\\~`" << std::endl;
	output << "/__*_______\\" << std::endl;
	output << "     ||" << std::endl;
	output << "   \\====/" << std::endl;
	output << "    \\__/" << std::endl;

	return ;
}
