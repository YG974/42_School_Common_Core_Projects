#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include <string>
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria	*Inventory[4];

	public:

		// Constructors
		MateriaSource();						// Default
		MateriaSource( MateriaSource const & src ); // copy
		
		// Destructor
		~MateriaSource();

		// Assignation
		MateriaSource &		operator=( MateriaSource const & src );

		// Methods
		void learnMateria(AMateria* src);
        AMateria* createMateria(std::string const & type);


};

#endif /* ******************************************************* CHARACTER_H */
