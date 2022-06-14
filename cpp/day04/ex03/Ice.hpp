#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"

class Ice : public AMateria
{

	public:

		// Constructors
		Ice();							// Default 
		Ice( Ice const & src ); 		// copy

		// Destructor
		~Ice();

		// Assignation
		Ice &		operator=( Ice const & src );

		// methods
		AMateria* clone() const;
		void use(ICharacter& target);

	private:

};

#endif /* ************************************************************* ICE_H */
