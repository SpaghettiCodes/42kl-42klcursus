#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm(name_gen("NULL"), 72, 45), target("NULL")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string const _target) : AForm(name_gen(_target), 72, 45), target(_target)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &ori) : AForm(name_gen(ori.target), 72, 45), target(ori.target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm &ori)
{
	this->target = ori.target;
	return (*this);
}

AForm *RobotomyRequestForm::dup() const
{
	AForm *ret = new RobotomyRequestForm(*this);
	return (ret);
}

void RobotomyRequestForm::action() const
{
	srand(time(NULL) + rand());
	std::cout << "\"Insert Drilling Noises\"" << std::endl;
	if (rand() % 2)
		std::cout << target << " is successfully robotomized" << std::endl;
	else
		std::cout << "Robotomy failed :(" << std::endl;
}

std::string RobotomyRequestForm::name_gen(std::string _target)
{
	return (std::string(_target).append("'s Robotomy Request Form"));
}