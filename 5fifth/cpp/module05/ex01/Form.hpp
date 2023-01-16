#ifndef __FORM_HPP__
#define __FORM_HPP__

#include <string>
#include "Bureaucrat.hpp"

class Form
{
	public:
		Form();
		Form(std::string new_name, int _req_sign, int _req_execute);
		Form(Form &ori);
		virtual ~Form();

		// uhhhhhh
		// Form &operator=(Form &ori);

		std::string const	&getName();
		int	const			&getreq_Sign();
		int const			&getreq_Exec();
		bool				getIs_Signed();
		std::string			beSigned(Bureaucrat const &signer);

	private:
		bool				is_signed;
		std::string const	name;
		int const			req_sign;
		int	const			req_execute;

		class GradeTooHighException : public std::exception
		{
			public: 
				const char *what() const throw()
				{
					return ("Error: Grade too high");
				}
		};

		class GradeTooLowException : public std::exception
		{
			public: 
				const char *what() const throw()
				{
					return ("Error: Grade too Low");
				}
		};
	
		class AlreadySignedException : public std::exception
		{
			public: 
				const char *what() const throw()
				{
					return ("Error: Form is already Signed");
				}
		};
};

std::ostream &operator<<(std::ostream &out, Form &form);

#endif