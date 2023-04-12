#ifndef __BUREAUCRAT_HPP__
#define __BUREAUCRAT_HPP__

#include <string>
#include <iostream>
class AForm;

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(Bureaucrat const &ori);
		Bureaucrat(std::string new_name, int new_grade);
		~Bureaucrat();

		Bureaucrat &operator=(Bureaucrat const &ori);

		std::string const	&getName() const;
		int					getGrade() const;

		void				increment_grade();
		void				decrement_grade();
		void				signForm(AForm &to_sign);
		void				executeForm(AForm const &form);

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

	private:
		std::string const name;
		int grade;
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureu);

#endif