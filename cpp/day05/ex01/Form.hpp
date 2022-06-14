#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class	Form
{
	private:

		const std::string	_name;
		bool				_signed;
		const int			_sign_grade;
		const int			_exec_grade;

	public :

		// Constructors
		Form ( void );							// Default Constructor
		Form ( std::string name , const int sign_grade, const int exec_grade);	// Init Constructor
		Form ( Form const & src );				// Copy constructor

		// Assignation
		Form &operator= (const Form & src);

		// Getters
		std::string getName( void ) const;
		bool		getSigned( void ) const;
		int			getSignGrade( void ) const;
		int			getExecGrade( void ) const;

		// Methods
		void		beSigned ( Bureaucrat Bur );

		// Destructors
		virtual ~Form();

		// Exceptions

		// High
		class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("Grade is higher than 150...");
			}
	};

		// Low
		class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("Grade is too low to be signed");
			}
	};

};

std::ostream &	operator<<(std::ostream& os, const Form& src);

#endif
