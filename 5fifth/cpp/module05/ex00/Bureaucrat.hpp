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

		void increment();
		void decrement();
		std::string const &getName() const;
		int getGrade() const;

		class GradeTooHighException : public std::exception
		{
			// https://en.cppreference.com/w/cpp/error/exception/what
			// returns the string that contains what went wrong
			// overload the throw() version, noexecept is only after c++11
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