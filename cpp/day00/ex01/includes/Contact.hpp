#include "phonebook.h"

class	Contact
{
	private :
		std::string		_details[5];

	public :
		std::string		field[5];
		void			setContactInput();
		void			printContactDetails();
		void			printHeader();

		Contact();	//Constructor
		~Contact();	//Destructor

		// Non member var & functions
		static int		nbContact;
		static void			printContactList(Contact *ptr);

};
