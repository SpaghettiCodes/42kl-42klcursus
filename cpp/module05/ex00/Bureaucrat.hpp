#ifndef __BUREAUCRAT_HPP__
#define __BUREAUCRAT_HPP__

#include <string>
#include <iostream>

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(Bureaucrat const &ori);
		Bureaucrat(std::string new_name, int new_grade);
		~Bureaucrat();

		Bureaucrat &operator=(Bureaucrat const &ori);

		std::string const &getName() const;
		int getGrade() const;
	private:
		std::string const name;
		int grade;

		class GradeTooHighException : public std::exception
		{
			// https://en.cppreference.com/w/cpp/error/exception/what
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
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureu);

#endif