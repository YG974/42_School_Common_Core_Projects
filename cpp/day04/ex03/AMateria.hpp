#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	private :
		std::string		_type;

	public:

		// Constructors
		AMateria();								// Default 
		AMateria( std::string const & type );	// Init
		AMateria( AMateria const & src );		// copy

		// Destructor
		virtual ~AMateria();

		// Assignation
		AMateria &		operator=( AMateria const & rhs );

		// Accessors
		std::string const & getType() const; //Returns the materia type

		// Methods
		virtual AMateria* clone() const = 0;
		virtual void use( ICharacter& target );

};

#endif /* ******************************************************** AMATERIA_H */
