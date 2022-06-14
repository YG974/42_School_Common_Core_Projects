#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter
{
	private:
		std::string _name;
		AMateria	*Inventory[4];

	public:

		// Constructors
		Character();						// Default
		Character (std::string name );		// Init
		Character( Character const & src ); // copy
		
		// Destructor
		~Character();

		// Assignation
		Character &		operator=( Character const & src );

		// Methods
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);

		// Accessors
		std::string const & getName() const;


};

#endif /* ******************************************************* CHARACTER_H */
