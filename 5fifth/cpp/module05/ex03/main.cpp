#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

// "presidential pardon",
// "robotomy request",
// "shrubbery creation"

int main()
{
	Intern Bob;
	AForm *BobForm;

	BobForm = Bob.makeForm("PResidential pardon", "John");
	if (BobForm)
	{
		std::cout << (*BobForm) << std::endl;
		delete BobForm;
	}

	BobForm = Bob.makeForm("robotomy request", "Ballers");
	if (BobForm)
	{
		std::cout << (*BobForm) << std::endl;
		delete BobForm;
	}

	BobForm = Bob.makeForm("shrubbery creation", "Amogus");
	if (BobForm)
	{
		std::cout << (*BobForm) << std::endl;
		delete BobForm;
	}

	try
	{
		BobForm = Bob.makeForm("hyok hyok hyok ", "Amogus");
		if (BobForm)
		{
			std::cout << (*BobForm) << std::endl;
			delete BobForm;
		}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	BobForm = Bob.makeForm("ShRubBery CREation", "Susses");
	if (BobForm)
	{
		std::cout << (*BobForm) << std::endl;
		delete BobForm;
	}

	BobForm = Bob.makeForm("ROB      OTOMY REQUE         ST", "Man");
	if (BobForm)
	{
		std::cout << (*BobForm) << std::endl;
		delete BobForm;
	}
}