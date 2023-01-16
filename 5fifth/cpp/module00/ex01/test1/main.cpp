#include <iostream>
#include <string>

#define FN 0
#define LN 1
#define NN 2
#define PN 3
#define DS 4

#define SHORTEN 0
#define DETAILED 1

class Contact{
	public:
		// constructor
		Contact();
		void		set_info(int chunk, std::string str);
		int			get_filled();
		void		set_filled(int val);
		void		print_data(int type);
	private:
		std::string	info[5];
		int			filled;
};

Contact :: Contact()
{
	filled = 0;
	return ;
}

void Contact::set_info(int chunk, std::string str)
{
	info[chunk] = str;
}

int	Contact::get_filled()
{
	return (filled);
}

void Contact::set_filled(int val)
{
	filled = val;
}

class PhoneBook{
	public:
		// constructor
		PhoneBook();
		void	addcontact();
		void	search_n_print();
	private:
		Contact	contacts[8];
		int			added;
		void		get_new_info(std::string msg, std::string &input);
		void		display_data();
		int			index_check(int index);
		void		get_search_index();
};

PhoneBook :: PhoneBook()
{
	added = 0;
	return ;
}

void Contact :: print_data(int type)
{
	int	i;

	i = 0;
	if (!type)
	{	
		while (i < 5)
		{
			std::cout << info[i];
			if (i != 4)
				std::cout << " | ";
			i++;
		}
		std::cout << std::endl;
	}
	else
	{
		std::cout << "\n| FIRST NAME == " << info[FN] << std::endl;
		std::cout << "| LAST NAME == " << info[LN] << std::endl;
		std::cout << "| NICKNAME NAME == " << info[NN] << std::endl;
		std::cout << "| PHONE NUMBER == " << info[PN] << std::endl;
		std::cout << "| DARKEST SECRET == " << info[DS] << std::endl << std::endl;
	}
}

int	s_toi(std::string str)
{
	int	result;
	int	i;

	i = 0;
	result = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result);
}

int PhoneBook :: index_check(int index)
{
	if (index != -1)
	{
		if (index < 8 && contacts[index].get_filled())
			return (0);
		else
			std::cout << "Error: Invalid Index" << std::endl;
	}
	else
		std::cout << "Error: Invalid Input" << std::endl;
	return (1);
}

void PhoneBook :: get_search_index()
{
	int index;
	std::string input;

	while (1)
	{
		std::cout << "Enter the index of the entry to display: ";
		getline(std::cin, input);
		index = s_toi(input);
		if (index_check(index))
			continue;
		break;
	}
	contacts[index].print_data(DETAILED);
}

void PhoneBook :: display_data()
{
	int i;
	std::string input;

	i = 0;
	std::cout << "INDEX : FIRST NAME | LAST NAME | NICKNAME | PHONE NUMBER | DARKEST SECRET" << std::endl;
	while (i < 8 && contacts[i].get_filled())
	{
		std::cout << i << " : ";
		contacts[i].print_data(SHORTEN);
		i++;
	}
	get_search_index();
}

void PhoneBook :: search_n_print()
{
	display_data();
}

void PhoneBook :: get_new_info(std::string msg, std::string &input)
{
	while (1)
	{
		std::cout << msg;
		getline(std::cin, input);
		if (input.length())
			break;
		std::cout << "Error: Empty Field\n";
	}
}

int	is_num(std::string str)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void PhoneBook :: addcontact()
{
	std::string buff;
	int	i;

	while (i < 8 && contacts[i].get_filled())
		i++;
	if (i == 9)
	{
		std::cout << "All Spaces Used Up!" << std::endl;
		i = added - 9;
	}
	get_new_info("Enter First Name: ", buff);
	contacts[i].set_info(FN, buff);
	get_new_info("Enter Last Name: ", buff);
	contacts[i].set_info(LN, buff);
	get_new_info("Enter Nickname: ", buff);
	contacts[i].set_info(NN, buff);
	while (1)
	{
		get_new_info("Enter Phone Number: ", buff);
		if (is_num(buff))
			break;
		std::cout << "Numbers Only!" << std::endl;
	}
	contacts[i].set_info(PN, buff);
	get_new_info("Enter Darkest Secret ( ͡° ͜ʖ ͡°): ", buff);
	contacts[i].set_info(DS, buff);
	contacts[i].set_filled(1);
	added++;
}

int main()
{
	PhoneBook epic_phonebook;
	std::string input;
	while (1)
	{
		std::cout << "ADD or SEARCH or EXIT" << std::endl;
		getline(std::cin, input);
		if (std::cin.eof())
			break;
		if (!input.compare("ADD"))
			epic_phonebook.addcontact();
		else if (!input.compare("SEARCH"))
			epic_phonebook.search_n_print();
		else if (!input.compare("EXIT"))
			break;
		std::cout << "Invalid Option\n" << std::endl; 
	}
}