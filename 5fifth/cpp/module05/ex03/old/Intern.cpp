#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
}

Intern::Intern(Intern &ori)
{
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

void	Intern::generate_templates(std::string target, AForm **tab)
{
	tab[0] = new PresidentialPardonForm(target);
	tab[1] = new RobotomyRequestForm(target);
	tab[2] = new ShrubberyCreationForm(target);
}

void	Intern::format_str(std::string &str)
{
	// make lower
	for (int i = 0; i < (int) str.size(); i++)
		str[i] = tolower(str[i]);

	// remove spaces
	for (int i = 0; i < (int) str.size(); i++)
		if (str[i] == ' ')
			str.erase(i, 1);
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	std::string options[3] = {
		"presidentialpardon",
		"robotomyrequest",
		"shrubberycreation" };
	AForm *forms[3];
	int i = 0;
	AForm *ret = NULL;
	
	generate_templates(target, forms);
	format_str(name);

	for ( ; i < 3; i++)
	{
		if (!options[i].compare(name))
			ret = forms[i]->dup();
		delete forms[i];
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