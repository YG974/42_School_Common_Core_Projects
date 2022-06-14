#include "RobotomyRequestForm.hpp"
#include <cstdlib>

/*
 * init Constructor
 */
RobotomyRequestForm::RobotomyRequestForm ( std::string target) :
	Form ( "RobotomyRequestForm", 72,  45 , target )
{
	std::cout << "----------------------------------" << std::endl;
	std::cout << "RobotomyRequestForm init Constructor called." << std::endl;
	std::cout << "Name : " <<  this->getName() << std::endl;
	std::cout << "Signed : " << this->getSigned() << std::endl;
	std::cout << "signGrade : " << this->getSignGrade() << std::endl;
	std::cout << "exec_grade : " << this->getExecGrade() << std::endl;
	std::cout << "----------------------------------" << std::endl;
	if ( this->getSignGrade() < 1 )
		throw RobotomyRequestForm::GradeTooLowException();
	if ( this->getSignGrade() > 150 )
		throw RobotomyRequestForm::GradeTooHighException();
	return ;
}

/*
 * Default Destructor
 */
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << this->getName() << " RobotomyRequestForm Destructor called";
	std::cout << std::endl;
	return ;
}


// Methods

// Execute
void RobotomyRequestForm::exec(Bureaucrat const & executor) const
{
	(void)executor;
	int	chance;

	chance = rand() % 2;
	if ( chance == 0)
	{
		std::cout << " DRILLLLLLLLLLLLYYYY NOIIIIIISSSSSEEEE " << std::endl;
		std::cout << this->getTarget();
		std::cout <<" has been robotomized successfuly" << std::endl;
		std::cout << std::endl;
	}
	else
			std::cout <<"Robotomy execution failed." << std::endl;
	return ;
}
