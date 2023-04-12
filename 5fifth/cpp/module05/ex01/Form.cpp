#include "Form.hpp"

Form::Form() : is_signed(0), name("Unnamed"), req_sign(150), req_execute(150)
{
	std::cout << "Default Form Created" << std::endl;
}

Form::Form(std::string new_name, int _req_sign, int _req_execute) : is_signed(0), name(new_name), req_sign(_req_sign), req_execute(_req_execute)
{
	if (req_sign < 1 || req_execute < 1)
		throw Form::GradeTooHighException();
	else if (req_sign > 150 || req_execute > 150)
		throw Form::GradeTooLowException();
	std::cout << "Form Created" << std::endl;
}

Form::Form(Form &ori): is_signed(ori.is_signed), name(ori.name), req_sign(ori.req_sign), req_execute(ori.req_execute)
{
	std::cout << "Form Copied" << std::endl;
}

Form::~Form()
{
	std::cout << "Form deleted" << std::endl;
}

// Form &Form::operator=(Form &ori)
// {
// 	return (*this);
// }

std::string const &Form::getName()
{
	return (name);
}

int const &Form::getreq_Sign()
{
	return (req_sign);
}

int const &Form::getreq_Exec()
{
	return (req_execute);
}

bool	Form::getIs_Signed()
{
	return (is_signed);
}

std::string Form::beSigned(Bureaucrat const &signer)
{
	if (signer.getGrade() > req_sign)
		throw Form::GradeTooLowException();
	else if (is_signed)
		throw Form::AlreadySignedException();
	else
	{
		is_signed = 1;
		return ((std::string(signer.getName()).append(" signed ").append(name)));
	}
}

std::ostream &operator<<(std::ostream &out, Form &form)
{
	out << "Form Name = " << form.getName() << ", IsSigned = " << form.getIs_Signed() << ", Grade Required To Sign = " << form.getreq_Sign() << ", Grade Required To Execute = " << form.getreq_Exec();
	return (out); 
}