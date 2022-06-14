#ifndef KAREN_HPP
# define KAREN_HPP

#include <string>
#include <iostream>



class	Karen
{
	private :

		// member functions
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );

		struct				function_pointers_tab
		{
			std::string		function_name;
			void			(Karen::*function_pointer) ( void );
		};

		static const		function_pointers_tab function_tab[];


	public :

		void complain( std::string level );
		~Karen();									// Destructor
		Karen();									// Constructor
};


#endif
