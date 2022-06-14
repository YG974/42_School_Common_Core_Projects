#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"

class Cure : public AMateria
{

	public:

		// Constructors
		Cure();							// Default 
		Cure( Cure const & src ); 		// copy

		// Destructor
		~Cure();

		// Assignation
		Cure &		operator=( Cure const & src );

		// methods
		AMateria* clone() const;
		void use(ICharacter& target);

	private:

};

#endif /* ************************************************************ CURE_H */
