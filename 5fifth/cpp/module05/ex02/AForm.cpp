#include "AForm.hpp"

AForm::AForm() : is_signed(0), name("Unnamed"), req_sign(150), req_execute(150)
{
	std::cout << "Default AForm Created" << std::endl;
}

AForm::AForm(std::string new_name, int _req_sign, int _req_exec) : is_signed(0), name(new_name), req_sign(_req_sign), req_execute(_req_exec)
{
	if (req_sign < 1 || req_execute < 1)
		throw AForm::GradeTooHighException();
	else if (req_sign > 150 || req_execute > 150)
		throw AForm::GradeTooLowException();
	std::cout << "Form Created" << std::endl;
}

AForm::AForm(AForm &ori): is_signed(ori.is_signed), name(ori.name), req_sign(ori.req_sign), req_execute(ori.req_execute)
{
	std::cout << "Form Copied" << std::endl;
}

AForm::~AForm()
{
	std::cout << "Form deleted" << std::endl;
}

AForm &AForm::operator=(AForm &ori)
{
	this->is_signed = ori.is_signed;
	return (*this);
}

std::string const &AForm::getName() const
{
	return (name);
}

int const &AForm::getreq_Sign() const
{
	return (req_sign);
}

int const &AForm::getreq_Exec() const
{
	return (req_execute);
}

bool	AForm::getIs_Signed()
{
	return (is_signed);
}

void AForm::beSigned(Bureaucrat const &signer)
{
	if (signer.getGrade() > req_sign)
		throw AForm::GradeTooLowException();
	else if (is_signed)
		throw AForm::AlreadySignedException();
	else
	{
		std::cout << signer.getName() << " signed " << name << std::endl;
		is_signed = 1;
	}
}

void	AForm::execute(Bureaucrat const &executor) const
{
	if (!is_signed)
		throw AForm::NotSignedException();
	else if (executor.getGrade() > req_sign)
		throw AForm::GradeTooLowException();
	else
	{
		std::cout << executor.getName() << " executed " << name << std::endl;
		action();
	}

}

std::ostream &operator<<(std::ostream &out, AForm &AForm)
{
	out << "Form Name = " << AForm.getName() << ", IsSigned = " << AForm.getIs_Signed() << ", Grade Required To Sign = " << AForm.getreq_Sign() << ", Grade Required To Execute = " << AForm.getreq_Exec();
	return (out); 
}