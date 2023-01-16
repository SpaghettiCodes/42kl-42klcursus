#ifndef __PRESIDENTIALPARDONFORM_HPP__
#define __PRESIDENTIALPARDONFORM_HPP__

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm
{
	public :
		PresidentialPardonForm();
		PresidentialPardonForm(std::string const _target);
		PresidentialPardonForm(PresidentialPardonForm const &ori);

		// this is made static
		// we cam call this function to create a new instance of the object wihout any existing object
		// i now know why i needed that this-> from module01
		static AForm *create_new(std::string target);
		~PresidentialPardonForm();

		PresidentialPardonForm &operator=(PresidentialPardonForm &ori);

		void action() const;

	private :
		std::string name_gen(std::string _target);
		std::string target;

};

#endif
