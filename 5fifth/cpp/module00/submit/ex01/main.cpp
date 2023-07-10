# include <iostream>
# include <string>
# include <iomanip>

// future chua here, i am SO SORRY about this code

# define FN 0
# define LN 1
# define NN 2
# define PN 3
# define DS 4

# define SHORTEN 0
# define DETAILED 1

class Contact{
	public:
		// constructor
		Contact();
		int			set_info(int chunk, std::string str);
		int			get_filled();
		void		set_filled(int val);
		void		print_data(int type);
	private:
		std::string	info[5];
		int			filled;
};

class PhoneBook{
	public:
		// constructor
		PhoneBook();
		void	addcontact();
		void	search_n_print();
	private:
		Contact			contacts[8];
		unsigned int	added;
		void			display_data();
		int				index_check(int index);
		void			get_search_index();
};

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

Contact::Contact()
{
	filled = 0;
	return ;
}

int Contact::set_info(int chunk, std::string str)
{
	if (chunk == PN && !(is_num(str)))
		return 0;
	info[chunk].assign(str);
	return 1;
}

int	Contact::get_filled()
{
	return (filled);
}

void Contact::set_filled(int val)
{
	filled = val;
}

PhoneBook::PhoneBook()
{
	added = 0;
	return ;
}

std::string	trunc(std::string str, int length, char exceed)
{
	std::string	ret;
	
	if (length >= (int) str.length())
		return (ret.assign(str));

	ret = str.substr(0, (length - 1));
	ret.push_back(exceed);
	return (ret);
}

void Contact :: print_data(int type)
{
	std::string print;
	int	i;

	i = 0;
	if (type == SHORTEN)
	{	
		while (i < 3)
		{
			std::cout << std::setfill(' ') << std::setw(10) << trunc(info[i], 10, '.') << " | ";
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
	if (!str.length())
		return (-1);
	while (i < (int) str.length())
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

	i = 0;
	if (!added)
	{
		std::cout << "Go fill in some entry first" << std::endl;
		return ;
	}
	std::cout << "| INDEX      | FIRST NAME | LAST NAME  | NICKNAME   |" << std::endl;
	while (i < 8 && contacts[i].get_filled())
	{
		std::cout << "| " << std::setfill(' ') << std::setw(10) << i << " | ";
		contacts[i].print_data(SHORTEN);
		i++;
	}
	get_search_index();
}

void PhoneBook :: search_n_print()
{
	display_data();
}

std::string get_new_info(std::string msg)
{
	std::string input;

	while (1)
	{
		std::cout << msg;
		getline(std::cin, input);
		if (input.length())
			break;
		std::cout << "Error: Empty Field\n";
	}
	return (input);
}

void PhoneBook :: addcontact()
{
	std::string		buff;
	unsigned int	i;

	if (added >= 8)
		std::cout << "Warning, will overwrite oldest entry!" << std::endl;
	i = added % 8;
	contacts[i].set_info(FN, get_new_info("Enter First Name: "));
	contacts[i].set_info(LN, get_new_info("Enter Last Name: "));
	contacts[i].set_info(NN, get_new_info("Enter Nick Name: "));
	while (!contacts[i].set_info(PN, get_new_info("Enter Phone Number: ")))
		std::cout << "Numbers Only!" << std::endl;
	contacts[i].set_info(DS, get_new_info("Enter Darkest Secret: "));
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
		else
			std::cout << "Invalid Option" << std::endl; 
	}
}