#ifndef __PRESIDENTIALPARDONFORM_HPP__
#define __PRESIDENTIALPARDONFORM_HPP__

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm
{
	public :
		PresidentialPardonForm();
		PresidentialPardonForm(std::string const _target);
		PresidentialPardonForm(PresidentialPardonForm &ori);
		~PresidentialPardonForm();

		PresidentialPardonForm &operator=(PresidentialPardonForm &ori);

		std::string getTarget();
		void action() const;

	private :
		std::string name_gen(std::string _target);
		std::string target;

};

#endif
