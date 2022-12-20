#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm(name_gen("NULL"), 145, 137), target("NULL")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const _target) : AForm(name_gen(_target), 145, 137), target(_target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &ori) : AForm(name_gen(ori.target), 145, 137), target(ori.target)
{
}

AForm *ShrubberyCreationForm::create_new(std::string target)
{
	AForm *ret = new ShrubberyCreationForm(target);
	return (ret);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm &ori)
{
	this->target = ori.target;
	return (*this);
}

void ShrubberyCreationForm::action() const
{
	std::ofstream out;

	out.open((std::string(target).append("_shrubbery")).c_str(), std::ios::trunc | std::ios::out);
	for (int i = 0; i < 5; i++)
		out << drawaFUCKINGTREE() << std::endl << std::endl;
	out.close();
}

std::string ShrubberyCreationForm::drawaFUCKINGTREE() const
{
	std::string tree;

//           &&& &&  & &&
//       && &\/&\|& ()|/ @, &&
//       &\/(/&/&||/& /_/)_&/_&
//    &() &\/&|()|/&\/ '%" & ()
//   &_\_&&_\ |& |&&/&__%_/_& &&
// &&   && & &| &| /& & % ()& /&&
//  ()&_---()&\&\|&&-&&--%---()~
//      &&     \|||
//              |||
//              |||
//              |||
//        , -=-~  .-^- _

	tree = "          &&& &&  & &&\n      && &\\/&\\|& ()|/ @, &&\n      &\\/(/&/&||/& /_/)_&/_&\n   &() &\\/&|()|/&\\/ '%\" & ()\n  &_\\_&&_\\ |& |&&/&__%_/_& &&\n&&   && & &| &| /& & % ()& /&&\n ()&_---()&\\&\\|&&-&&--%---()~\n     &&     \\|||\n             |||\n             |||\n             |||\n       , -=-~  .-^- _";
	return (tree);
}

std::string ShrubberyCreationForm::name_gen(std::string _target)
{
	return (std::string(_target).append("'s Shrubbery Creation Form"));
}

