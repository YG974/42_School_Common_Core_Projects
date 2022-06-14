#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <string>
#include <iostream>
#include <fstream>
#include "Form.hpp"

class Form;

class	PresidentialPardonForm : public Form
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
		PresidentialPardonForm ( std::string target );
		// Copy Constructor
		PresidentialPardonForm ( PresidentialPardonForm const & src );

		// Assignation
		PresidentialPardonForm &operator= (const PresidentialPardonForm & src);


		// Methods
		void		exec(Bureaucrat const & executor) const;

		// Destructors
		virtual ~PresidentialPardonForm();

};

#endif
