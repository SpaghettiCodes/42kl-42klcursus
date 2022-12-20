#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	AForm *RoboForm = new RobotomyRequestForm("Bob");
	AForm *RoboForm2 = new RobotomyRequestForm("Ben");
	AForm *ShrubForm = new ShrubberyCreationForm("Home");
	AForm *ShrubForm2 = new ShrubberyCreationForm("test");
	AForm *President = new PresidentialPardonForm("Obama");

	Bureaucrat Amogus("Amgous", 1);
	Bureaucrat Sussy("Sussy", 150);
	Bureaucrat Baka("Baka", 45);
	Bureaucrat Sus("Sus", 137);

	std::cout << std::endl << "Forms" << std::endl;
	std::cout << (*RoboForm) << std::endl;
	std::cout << (*RoboForm2) << std::endl;
	std::cout << (*ShrubForm) << std::endl;
	std::cout << (*ShrubForm2) << std::endl;
	std::cout << (*President) << std::endl;
	std::cout << std::endl;

	std::cout << std::endl << "Bureaucrats" << std::endl;
	std::cout << Amogus << std::endl;
	std::cout << Sussy << std::endl;
	std::cout << Baka << std::endl;
	std::cout << Sus << std::endl;
	std::cout << std::endl;

	Amogus.signForm(*President);
	Amogus.executeForm(*President);
	std::cout << std::endl;

	Sussy.signForm(*ShrubForm);
	Sussy.executeForm(*ShrubForm);
	Sussy.executeForm(*President);
	std::cout << std::endl;

	Baka.signForm(*RoboForm);
	Baka.executeForm(*RoboForm);
	std::cout << std::endl;

	Sus.signForm(*ShrubForm);
	Sus.executeForm(*ShrubForm);
	std::cout << std::endl;

	Amogus.signForm(*ShrubForm2);
	Sus.executeForm(*ShrubForm2);
	std::cout << std::endl;

	Amogus.signForm(*RoboForm2);
	Baka.executeForm(*RoboForm2);
	std::cout << std::endl;

	std::cout << std::endl << "Forms" << std::endl;
	std::cout << (*RoboForm) << std::endl;
	std::cout << (*RoboForm2) << std::endl;
	std::cout << (*ShrubForm) << std::endl;
	std::cout << (*ShrubForm2) << std::endl;
	std::cout << (*President) << std::endl;
	std::cout << std::endl;

	delete RoboForm;
	delete ShrubForm;
	delete President;
	delete RoboForm2;
	delete ShrubForm2;
}