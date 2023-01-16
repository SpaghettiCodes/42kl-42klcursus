#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm(name_gen("NULL"), 25, 5), target("NULL")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string const _target) : AForm(name_gen(_target), 25, 5), target(_target)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &ori) : AForm(name_gen(ori.target), 25, 5), target(ori.target)
{
}

AForm *PresidentialPardonForm::create_new(std::string target)
{
	AForm *ret = new PresidentialPardonForm(target);
	return (ret);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm &ori)
{
	this->target = ori.target;
	return (*this);
}

void PresidentialPardonForm::action() const
{
	std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

std::string PresidentialPardonForm::name_gen(std::string _target)
{
	return (std::string(_target).append("'s Presidential Pardon Form"));
}