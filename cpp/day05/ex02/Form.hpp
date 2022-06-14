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
		const std::string	_target;

	public :

		// Constructors

		// Default Constructor
		Form ( void );
		// Init Constructor
		Form ( std::string name , const int sign_grade, const int exec_grade,
				std::string target );
		// Copy constructor
		Form ( Form const & src );

		// Assignation
		/* Form&	operator=(const Form&); */
		Form & operator= (const Form &src);

		// Getters
		std::string getName( void ) const;
		bool		getSigned( void ) const;
		int			getSignGrade( void ) const;
		int			getExecGrade( void ) const;
		std::string getTarget( void ) const;

		// Methods
		void		beSigned ( Bureaucrat Bur );

		void		execute(Bureaucrat const & executor) const;
		virtual void		exec(Bureaucrat const & executor) const = 0;

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

		// exec grade
		class ExecGradeException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("Exec grade is too low");
			}
	};

		// Not signed
		class NotSignedException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("Form is not signed");
			}
	};
};

std::ostream &	operator<<(std::ostream& os, const Form& src);

#endif
