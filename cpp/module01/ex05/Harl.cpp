#include "Harl.hpp"


// typedef a function pointer to a function that returns void, takes no parameters, and is part of Harl:: class
typedef void (Harl::*func_ptr)(void) ;

void Harl::complain(std::string level)
{
	// them function pointer array
	func_ptr functions[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string option[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	int i = 0;
	while (i < 5)
	{
		if (!option[i].compare(level))
		{
			// to access a function pointer, use (*function[i])
			// this-> is needed to... idk honestly
			// if you dont use this-> a bunch of unhappy error pop up sooooooooooo
			(this->*functions[i]) ();
			break;
		}
		i++;
	}
}

void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

Harl::Harl(void)
{
	std::cout << "Harl has entered the premise" << std::endl;
}

Harl::~Harl(void)
{
	std::cout << "Harl has been escorted out the premise" << std::endl;
}