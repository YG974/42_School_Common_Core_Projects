#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class	Bureaucrat
{
	private:


	protected :
		std::string		_name;
		int				_grade;

	public :

		// Constructors
		Bureaucrat ( void );							// Default Constructor
		Bureaucrat ( std::string name );				// Init Constructor
		Bureaucrat ( std::string name , int grade);		// Init Constructor
		Bureaucrat ( Bureaucrat const & src );			// Copy constructor

		// Assignation
		Bureaucrat &operator= (const Bureaucrat & src);

		// Getters
		std::string getName( void ) const;
		int			getGrade( void ) const;

		// Methods
		void		incremente_grade( void );
		void		decremente_grade( void );

		// Destructors
		virtual ~Bureaucrat();

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
				return ("Grade is lower than 1...");
			}
	};

};

std::ostream &	operator<<(std::ostream& os, const Bureaucrat& src);

#endif
