#include "includes/phonebook.h"

void	welcome_message(void)
{
	std::cout << " ------------------------------------------- " << "\n";
	std::cout << "Welcome to PhoneBook of the turfu\n";
	std::cout << "PhoneBook memory is empty, fill it !\n";
	std::cout << "You can add up to 8 contacts\n";
	std::cout << "Please enter one of the following commands to start:\n";
	std::cout << "- ADD\n";
	std::cout << "- SEARCH\n";
	std::cout << "- EXIT";
	std::cout << std::endl;
	std::cout << " ------------------------------------------- " << "\n";
	return ;
}

int		is_command(std::string *str)
{
	if (str->compare("ADD") == 0)
		return (0);
	else if (str->compare("SEARCH") == 0)
		return (1);
	else if (str->compare("EXIT") == 0)
		return (2);
	else 
		return (-1);
}

int		main(void)
{
	Contact			book[8];
	Contact			*ptr;
	std::string		buff;
	int				cmd;
	int				i;
	int				index;

	i = 0;
	welcome_message();
	ptr = &book[8];
	while (667)
	{
		std::cout << "You typed : ";
		std::getline(std::cin, buff);
		if (std::cin.eof())
			{
				std::cout << "EOF (ctrl - D)." << std::endl;
				break ;
			}
		if ((cmd = is_command(&buff)) < 0)
			std::cout << WRONG_COMMAND;
		else
		{
			// ADD CMD
			if (cmd == 0)
			{
				if (i == 8)
				{
					i = 0;
					std::cout << "Phone book is full. Most recent contact ";
					std::cout << "will erase  the oldest one." << std::endl;
				}
				book[i++].setContactInput();
			}
			// SEARCH CMD
			else if (cmd == 1)
			{
				book[0].printHeader();
				book->printContactList(&book[0]);
				std::cout << "Please select 1 contact number" << std::endl;
				std::cout << "You select contact number ";
				index = -1;
				std::getline(std::cin, buff);
				if (isdigit(buff[0]) && buff[1] == 0)
				{
					index = stoi(buff);
					if (index > 0 && index <= Contact::nbContact)
						book[index - 1].printContactDetails();
					else
						std::cout << INDEX_ERROR << std::endl;
				}
				else
					std::cout << INDEX_ERROR << std::endl;
			}
			// EXIT CMD
			else if (cmd == 2)
			{
				std::cout << "GOOD BYE from the turfu !!!" << std::endl;
				break ;
			}
		}
		std::cout << " ------------------------------------------- " << "\n";
		std::cout << "Enter one of the following commands to continue:\n";
		std::cout << AVAILABLE_COMMAND << std::endl;
		std::cout << " ------------------------------------------- " << "\n";
	}
	return (0);
}
