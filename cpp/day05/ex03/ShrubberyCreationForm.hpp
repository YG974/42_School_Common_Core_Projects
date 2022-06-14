#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <string>
#include <iostream>
#include <fstream>
#include "Form.hpp"

class Form;

class	ShrubberyCreationForm : public Form
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
		ShrubberyCreationForm ( std::string target );
		// Copy Constructor
		ShrubberyCreationForm ( ShrubberyCreationForm const & src );

		// Assignation
		ShrubberyCreationForm &operator= (const ShrubberyCreationForm & src);


		// Methods
		void		exec(Bureaucrat const & executor) const;

		// Destructors
		virtual ~ShrubberyCreationForm();

};

#endif
