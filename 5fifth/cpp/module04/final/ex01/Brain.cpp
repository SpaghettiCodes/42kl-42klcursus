#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain is constructed" << std::endl;
}

Brain::Brain(Brain const &ori)
{
	*this = ori;
}

Brain &Brain::operator=(Brain const &ori)
{
	for (int i = 0; i < 100; ++i)
		this->ideas[i] = ori.ideas[i];
	std::cout << "Brain is duplicated" << std::endl;
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain is deconstructed" << std::endl;
}

std::string &Brain::getIdeas(int tab)
{
	return (ideas[tab]);
}

void Brain::setIdeas(std::string new_idea, int tab)
{
	ideas[tab] = new_idea;
}