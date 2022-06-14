#include "Bureaucrat.hpp"

/*
 * init Constructor
 */
Bureaucrat::Bureaucrat ( std::string name, int grade ) :
	_name ( name ), _grade ( grade )
{
	std::cout << "----------------------------------" << std::endl;
	std::cout << "Bureaucrat init Constructor called." << std::endl;
	std::cout << "Name : " << this->_name << std::endl;
	std::cout << "Grade : " << this->_grade << std::endl;
	std::cout << "----------------------------------" << std::endl;
	if ( grade < 1 )
		throw Bureaucrat::GradeTooLowException();
	if ( grade > 150 )
		throw Bureaucrat::GradeTooHighException();
	return ;
}

/*
 * init Constructor
 */
Bureaucrat::Bureaucrat ( std::string name ) : _name ( name ), _grade (0)
{
	std::cout << "----------------------------------" << std::endl;
	std::cout << "Bureaucrat init Constructor called." << std::endl;
	std::cout << "Name : " << this->_name << std::endl;
	std::cout << "Grade : " << this->_grade << std::endl;
	std::cout << "----------------------------------" << std::endl;
	if ( this->_grade < 1 )
		throw Bureaucrat::GradeTooLowException();
	if ( this->_grade > 150 )
		throw Bureaucrat::GradeTooHighException();
	return ;
}

/*
 * Copy Constructor
 */
Bureaucrat::Bureaucrat ( Bureaucrat const & src ) : 
	_name ( src._name),  _grade( src._grade )
{
	std::cout << "----------------------------------" << std::endl;
	std::cout << "Bureaucrat Copy Constructor called." << std::endl;
	std::cout << "Name : " << this->_name << std::endl;
	std::cout << "Grade : " << this->_grade << std::endl;
	std::cout << "----------------------------------" << std::endl;
	if ( this->_grade < 1 )
		throw Bureaucrat::GradeTooLowException();
	if ( this->_grade > 150 )
		throw Bureaucrat::GradeTooHighException();
	return ;

}


/*
 * Default Constructor
 */
Bureaucrat::Bureaucrat ( void ) : _name ("Unknown"), _grade (0)
{
	std::cout << "----------------------------------" << std::endl;
	std::cout << "Bureaucrat Default Constructor called." << std::endl;
	std::cout << "Name : " << this->_name << std::endl;
	std::cout << "Grade : " << this->_grade << std::endl;
	std::cout << "----------------------------------" << std::endl;
	if ( this->_grade < 1 )
		throw Bureaucrat::GradeTooLowException();
	if ( this->_grade > 150 )
		throw Bureaucrat::GradeTooHighException();
	return ;
}

/*
 * Default Destructor
 */
Bureaucrat::~Bureaucrat()
{
	std::cout << this->_name << " Bureaucrat Destructor called" << std::endl;
	return ;
}

// Getters
int Bureaucrat::getGrade( void ) const
{
	return ( this->_grade ) ;
}

std::string Bureaucrat::getName( void ) const
{
	return ( this->_name ) ;
}

void Bureaucrat::signForm(int mode, std::string form_name)
{
	if (mode == 0)
	{
		std::cout << this->_name << " cannot signs " << form_name;
		std::cout << " because it's already signed" << std::endl;
	}
	else if (mode == 1)
		std::cout << this->_name << " signs " << form_name <<  std::endl;
}

// Increment
void Bureaucrat::incremente_grade( void )
{
	this->_grade--;
	if ( this->_grade < 1 )
		throw Bureaucrat::GradeTooLowException();
	if ( this->_grade > 150 )
		throw Bureaucrat::GradeTooHighException();
	return ;
}

// decrement
void Bureaucrat::decremente_grade( void )
{
	this->_grade++;
	if ( this->_grade < 1 )
		throw Bureaucrat::GradeTooLowException();
	if ( this->_grade > 150 )
		throw Bureaucrat::GradeTooHighException();
	return ;
}

// excecute
void Bureaucrat::executeForm(Form const & form)
{
	try
	{
		if (!form.getSigned())
			throw Form::NotSignedException();
		if (this->getGrade() > form.getExecGrade())
			throw Form::ExecGradeException();
		std::cerr << std::endl;
		std::cout << this->getName() << " executes " << form.getName() << std::endl;
		form.execute(*this);
	}
	catch (std::exception & e)
	{
		std::cerr << std::endl;
		std::cerr << this->getName() << " tried to execute " << form.getName();
		std::cerr << " but :" << std::endl;
		std::cerr << "Exception caught -> " << e.what() << std::endl;
		std::cerr << std::endl;
	}
	return ;
}

std::ostream &	operator<<(std::ostream& os, const Bureaucrat& src)
{
	os << "Bureaucrat named " << src.getName() << " got ";
	os << src.getGrade() << ". Amazing !" << std::endl;
	return ( os );
}
