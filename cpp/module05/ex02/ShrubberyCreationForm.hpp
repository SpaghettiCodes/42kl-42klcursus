#ifndef __SHRUBBERYCREATIONFORM_HPP__
#define __SHRUBBERYCREATIONFORM_HPP__

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

class ShrubberyCreationForm : public AForm
{
	public :
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string const _target);
		ShrubberyCreationForm(ShrubberyCreationForm &ori);
		~ShrubberyCreationForm();

		ShrubberyCreationForm &operator=(ShrubberyCreationForm &ori);
	
		void action() const;

	private :
		std::string drawaFUCKINGTREE() const;
	
		std::string name_gen(std::string _target);
		std::string target;

};

#endif