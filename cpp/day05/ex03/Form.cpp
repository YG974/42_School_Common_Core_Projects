#include "Form.hpp"
#include <exception>

/*
 * init Constructor
 */
Form::Form (	std::string name, const int sign_grade, const int exec_grade, 
				std::string target) :
_name ( name ), _signed (false),
_sign_grade ( sign_grade ), _exec_grade ( exec_grade ), _target ( target )
{
	std::cout << "----------------------------------" << std::endl;
	std::cout << "Form init Constructor called." << std::endl;
	std::cout << "Name : " << this->_name << std::endl;
	std::cout << "Signed : " << this->_signed << std::endl;
	std::cout << "SignGrade : " << this->_sign_grade << std::endl;
	std::cout << "Exec_grade : " << this->_exec_grade << std::endl;
	std::cout << "Target : " << this->_target << std::endl;
	std::cout << "----------------------------------" << std::endl;
	if ( sign_grade < 1 )
		throw Form::GradeTooLowException();
	if ( sign_grade > 150 )
		throw Form::GradeTooHighException();
	return ;
}

/*
 * Default Constructor
 */
Form::Form ( void ) : _name ("Unknown"), _signed(false),
	_sign_grade(150), _exec_grade(150)
{
	std::cout << "----------------------------------" << std::endl;
	std::cout << "Form Default Constructor called." << std::endl;
	std::cout << "Name : " << this->_name << std::endl;
	std::cout << "Signed : " << this->_signed << std::endl;
	std::cout << "SignGrade : " << this->_sign_grade << std::endl;
	std::cout << "Exec_grade : " << this->_exec_grade << std::endl;
	std::cout << "Target : " << this->_target << std::endl;
	std::cout << "----------------------------------" << std::endl;
	if ( _sign_grade < 1 )
		throw Form::GradeTooLowException();
	if ( _sign_grade > 150 )
		throw Form::GradeTooHighException();
	return ;
}

/*
 * Copy Constructor
 */
Form::Form ( Form const & src ) : _name ( src._name),  _signed ( src._signed ),
	_sign_grade ( src._sign_grade ), _exec_grade( src._exec_grade ),
	_target ( src._target )
{
	std::cout << "----------------------------------" << std::endl;
	std::cout << "Form Copy Constructor called." << std::endl;
	std::cout << "Name : " << this->_name << std::endl;
	std::cout << "Signed : " << this->_signed << std::endl;
	std::cout << "SignGrade : " << this->_sign_grade << std::endl;
	std::cout << "Exec_grade : " << this->_exec_grade << std::endl;
	std::cout << "Target : " << this->_target << std::endl;
	std::cout << "----------------------------------" << std::endl;
	if ( _sign_grade < 1 )
		throw Form::GradeTooLowException();
	if ( _sign_grade > 150 )
		throw Form::GradeTooHighException();
	return ;
}

/*
 * Assignement operator
 */
Form&	Form::operator=(const Form& src)
{
	this->_signed = src._signed;
	return (*this);
}

/*
 * Default Destructor
 */
Form::~Form()
{
	std::cout << this->_name << " Form Destructor called" << std::endl;
	return ;
}

// Getters
std::string Form::getName( void ) const
{
	return ( this->_name ) ;
}

bool Form::getSigned( void ) const
{
	return ( this->_signed ) ;
}

int Form::getSignGrade( void ) const
{
	return ( this->_sign_grade ) ;
}

int Form::getExecGrade( void ) const
{
	return ( this->_exec_grade ) ;
}

std::string Form::getTarget( void ) const
{
	return ( this->_target ) ;
}

// Methods
void Form::beSigned( Bureaucrat bur)
{
	std::cout << "---------------------------------------------" << std::endl;
	try 
	{
	if (bur.getGrade() > this->_sign_grade)
		throw Form::GradeTooLowException();
	if (this->_signed == true)
		bur.signForm(0, this->_name);
	else
	{
		if (bur.getGrade() > this->_sign_grade)
			throw Form::GradeTooLowException();
		else
		{
			this->_signed = true;
			bur.signForm(1, this->_name);
		}
	};
	}
	catch (std::exception & e)
	{
		std::cerr << "Exception caught -> " << e.what() << std::endl;
	}
	std::cout << "---------------------------------------------\n" << std::endl;
	return ;
}

// Execute
void Form::execute(Bureaucrat const & executor) const
{
	(void)executor;
	this->exec(executor);
	return ;
}

std::ostream &	operator<<(std::ostream& os, const Form& src)
{
	os << "OVERLOAD DEMONSTRATION :" << std::endl;
	os << "Name : " << src.getName() << std::endl;
	os << "Signed : " << src.getSigned() << std::endl;
	os << "signGrade : " << src.getSignGrade() << std::endl;
	os << "exec_grade : " << src.getExecGrade() << std::endl;
	return ( os );
}
