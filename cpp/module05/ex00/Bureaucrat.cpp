#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("Unnamed"), grade(75)
{
	std::cout << "Bureaucrat is created" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &ori): name(ori.name), grade(ori.grade)
{
	std::cout << "Bureaucrat is copied" << std::endl;
}

Bureaucrat::Bureaucrat(std::string new_name, int new_grade): name(new_name), grade(new_grade)
{
	try 
	{
		if (grade < 1)
		{
			grade = 1;
			throw Bureaucrat::GradeTooLowException();
		}
		else if (grade > 150)
		{
			grade = 150;
			throw Bureaucrat::GradeTooHighException();
		}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "Bureaucrat is created" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat is destroyed" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &ori)
{
	this->grade = ori.grade;
	return (*this);
}

std::string const &Bureaucrat::getName() const
{
	return (name);
}

int Bureaucrat::getGrade() const
{
	return (grade);
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureu)
{
	out << bureu.getName() << ", grade " << bureu.getGrade();
	return (out);
}