#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(): name("Unnamed"), grade(75)
{
	std::cout << "Default Bureaucrat is created" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &ori): name(ori.name), grade(ori.grade)
{
	std::cout << "Bureaucrat is copied" << std::endl;
}

Bureaucrat::Bureaucrat(std::string new_name, int new_grade): name(new_name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade = new_grade;
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

void	Bureaucrat::increment_grade()
{
	if (grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	grade--;
	std::cout << "Incremented " << name << std::endl;
}

void	Bureaucrat::decrement_grade()
{
	if (grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	grade++;
	std::cout << "Decremented " << name << std::endl;
}

void	Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned((*this));
	}
	catch (std::exception &e)
	{
		std::cout << name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
		return ;
	}
	std::cout << name << " successfully signed " << form.getName() << std::endl;
}

void	Bureaucrat::executeForm(AForm const &form)
{
	try
	{
		form.execute((*this));
	}
	catch (std::exception &e)
	{
		std::cout << name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
		return ;
	}
	std::cout << name << " successfully executed " << form.getName() << std::endl;
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureu)
{
	out << bureu.getName() << ", grade " << bureu.getGrade();
	return (out);
}