#ifndef __ROBOTOMYREQUESTFORM_HPP__
#define __ROBOTOMYREQUESTFORM_HPP__

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm
{
	public :
		RobotomyRequestForm();
		RobotomyRequestForm(std::string const _target);
		RobotomyRequestForm(RobotomyRequestForm const &ori);
		static AForm *create_new(std::string target);
		~RobotomyRequestForm();

		RobotomyRequestForm &operator=(RobotomyRequestForm &ori);
	
		void action() const;

	private :
		std::string name_gen(std::string _target);
		std::string target;

};

#endif