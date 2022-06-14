#include "includes/phonebook.h"

void	Contact::printContactDetails()
{
	int i = -1;
	std::cout << " ------------------------------------------- " << "\n";
	while (++i < 5)
	{
		std::cout.width (15);
		std::cout << this->field[i];
		std::cout << " : " << this->_details[i] << std::endl;
	}
	return ;
}

void	Contact::printHeader()
{
	std::string		str[4] = {"Index", "First Name", "Last Name", "Nickname"};

	int i = -1;

	std::cout.setf ( std::ios::right );
	std::cout << " ------------------------------------------- " << "\n|";
	while (++i < 4)
	{
		std::cout.width (10);
		std::cout.fill (' ');
		std::cout << str[i];
		std::cout << "|";
	}
	std::cout << std::endl;
	std::cout << " ------------------------------------------- " << "\n";
}

void	Contact::printContactList(Contact *ptr)
{
	std::string tmp;

	int i = -1;
	int j = -1;

	std::cout.setf ( std::ios::right );
	while (++i < Contact::nbContact)
	{
		std::cout << "|";
		std::cout.width (10);
		std::cout << i + 1;
		std::cout << "|";
		j = -1;
		while (++j < 3)
		{
			tmp = ptr[i]._details[j];
			if (tmp.size() > 10)
			{
				tmp[9] = '.';
				tmp.resize(10);
			}
			std::cout.width (10);
			std::cout << tmp;
			std::cout << "|";
		}
		std::cout << std::endl;
	}
	std::cout << " ------------------------------------------- " << "\n";
	return ;
}

void	Contact::setContactInput()
{
	int i = -1;
	while (++i < 5)
	{
		std::cout << "Please enter your " << Contact::field[i] << " : ";
		std::getline(std::cin, Contact::_details[i]);
		if (Contact::_details[i].empty())
		{
			std::cout << "Error. Empty field. ADD command aborted" << std::endl;
			return ;
		}
	}
	if (Contact::nbContact < 8)
		Contact::nbContact++;
	std::cout << " ------------------------------------------- " << "\n";
	std::cout << "New contact added successfully.\n";
	std::cout << "Now, you have "<< this->nbContact;;
	std::cout << " contact(s) in your phonebook." << std::endl;
	return ;
}

/*
 * Default Constructor
 */
Contact::Contact()
{
	field[0] = "First Name";
	field[1] = "Last Name";
	field[2] = "Nickname";
	field[3] = "Phone Number";
	field[4] = "Darkest Secret";
	std::cout << "Constructor called" << std::endl;
	return ;
}

/*
 * Default Destructor
 */
Contact::~Contact()
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

/*
 * Initialisation of non member class variable
 */
int		Contact::nbContact = 0;
