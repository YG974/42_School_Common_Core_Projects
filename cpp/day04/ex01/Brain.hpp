#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain
{

	public:

		Brain();
		Brain( Brain const & src );
		virtual ~Brain();

		Brain &		operator=( Brain const & src );

		// GETTER
		std::string getIdea(int i) const;
		// SETTER
		void		setIdea(int i, std::string str);
		// PRINTER
		void		printIdeas( void ) const;

	private:
		std::string _ideas[100];

};

#endif /* *********************************************************** BRAIN_H */
