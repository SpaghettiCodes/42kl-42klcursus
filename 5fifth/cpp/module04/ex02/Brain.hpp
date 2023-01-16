#ifndef __BRAIN_HPP__
#define __BRAIN_HPP__

#include <iostream>
#include <string>

class Brain
{
	public:
		Brain();
		Brain(Brain const &ori);
		Brain &operator=(Brain const &ori);
		~Brain();

		std::string &getIdeas(int tab);
		void setIdeas(std::string new_idea, int tab);
	private:
		std::string ideas[100];
};

#endif