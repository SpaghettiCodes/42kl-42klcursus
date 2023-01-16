#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void	Intern::init_option()
{
	form_options[0] = "presidentialpardon";
	form_options[1] = "robotomyrequest";
	form_options[2] = "shrubberycreation";
}

Intern::Intern()
{
	init_option();
}

Intern::Intern(Intern &ori)
{
	init_option();
	(void) ori;
}

Intern::~Intern()
{
}

Intern &Intern::operator=(Intern &ori)
{	
	(void) ori;
	return (*this);
}

void	Intern::format_str(std::string &str)
{
	// make lower
	for (int i = 0; i < (int) str.size(); i++)
	{
		str[i] = tolower(str[i]);
		if (str[i] == ' ')
		{
			str.erase(i, 1);
			i--;
		}
	}
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	AForm *(*funcptr[3])(std::string) = {
		PresidentialPardonForm::create_new,
		RobotomyRequestForm::create_new,
		ShrubberyCreationForm::create_new,
	};

	AForm *ret = NULL;
	format_str(name);

	for (int i = 0 ; i < 3; i++)
	{
		if (!form_options[i].compare(name))
		{
			ret = funcptr[i](target);
			break;
		}
	}

	try
	{
		if (!ret)
			throw (Intern::NoSuchForm());
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (ret);
}