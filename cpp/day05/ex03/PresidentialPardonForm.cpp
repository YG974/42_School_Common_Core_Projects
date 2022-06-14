#include "PresidentialPardonForm.hpp"

/*
 * init Constructor
 */
PresidentialPardonForm::PresidentialPardonForm ( std::string target) :
	Form ( "PresidentialPardonForm", 25,  5 , target )
{
	std::cout << "----------------------------------" << std::endl;
	std::cout << "PresidentialPardonForm init Constructor called." << std::endl;
	std::cout << "Name : " <<  this->getName() << std::endl;
	std::cout << "Signed : " << this->getSigned() << std::endl;
	std::cout << "signGrade : " << this->getSignGrade() << std::endl;
	std::cout << "exec_grade : " << this->getExecGrade() << std::endl;
	std::cout << "----------------------------------" << std::endl;
	if ( this->getSignGrade() < 1 )
		throw PresidentialPardonForm::GradeTooLowException();
	if ( this->getSignGrade() > 150 )
		throw PresidentialPardonForm::GradeTooHighException();
	return ;
}

/*
 * Default Destructor
 */
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << this->getName() << " PresidentialPardonForm Destructor called";
	std::cout << std::endl;
	return ;
}


// Methods

// Execute
void PresidentialPardonForm::exec(Bureaucrat const & executor) const
{
	(void)executor;

	std::cout << this->getTarget();
	std::cout << " has been pardoned by Zafod Beeblebrox";
	std::cout << std::endl;
	std::cout << std::endl;

	return ;
}
