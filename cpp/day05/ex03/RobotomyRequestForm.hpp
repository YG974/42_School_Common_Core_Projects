#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <string>
#include <iostream>
#include "Form.hpp"

class Form;

class	RobotomyRequestForm : public Form
{
	private:

		// Form attributes
		/* const std::string	_name; */
		/* bool				_signed; */
		/* const int			_sign_grade; */
		/* const int			_exec_grade; */

	public :

		// Constructors
		// Init Constructor
		RobotomyRequestForm ( std::string target );
		// Copy Constructor
		RobotomyRequestForm ( RobotomyRequestForm const & src );

		// Assignation
		RobotomyRequestForm &operator= (const RobotomyRequestForm & src);


		// Methods
		void		exec(Bureaucrat const & executor) const;

		// Destructors
		virtual ~RobotomyRequestForm();

};

#endif
