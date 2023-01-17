#ifndef __INTERN_HPP__
#define __INTERN_HPP__

#include "AForm.hpp"

class Intern
{
	public: 
		Intern();
		Intern(Intern &ori);
		~Intern();

		Intern &operator=(Intern &ori);
		AForm *makeForm(std::string name, std::string target);

	private:
		void	format_str(std::string &str);
		void	generate_templates(std::string target, AForm **tab);
	
		class NoSuchForm : public std::exception
		{
			public: 
				const char *what() const throw()
				{
					return ("Error: Form Does Not Exists");
				}
		};
};

#endif