#ifndef __FORM_HPP__
#define __FORM_HPP__

#include <string>
#include "Bureaucrat.hpp"

class AForm
{
	public:
		AForm();
		AForm(std::string new_name, int _req_sign, int _req_execute);
		AForm(AForm &ori);
		virtual ~AForm();

		AForm &operator=(AForm &ori);

		std::string const	&getName() const;
		int	const			&getreq_Sign() const;
		int const			&getreq_Exec() const;
		bool				getIs_Signed();

		void				beSigned(Bureaucrat const &signer);
		void				execute(Bureaucrat const &executor) const;
		virtual void		action() const = 0;

	private:
		bool				is_signed;
		std::string const	name;
		int const			req_sign;
		int	const			req_execute;

		class GradeTooHighException : public std::exception
		{
			public: 
				const char *what() const throw() { return ("Error: Grade too high"); }
		};

		class GradeTooLowException : public std::exception
		{
			public: 
				const char *what() const throw() { return ("Error: Grade too Low"); }
		};
	
		class AlreadySignedException : public std::exception
		{
			public: 
				const char *what() const throw() { return ("Error: Form is already Signed"); }
		};

		class NotSignedException : public std::exception
		{
			public: 
				const char *what() const throw() { return ("Error: Form is not yet Signed"); }
		};
};

std::ostream &operator<<(std::ostream &out, AForm &form);

#endif