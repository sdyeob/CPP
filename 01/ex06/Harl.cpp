
#include "Harl.hpp"


Harl::Harl()
{
	levels[0] = "DEBUG";
	levels[1] = "INFO";
	levels[2] = "WARNING";
	levels[3] = "ERROR";

	func_ptr[0] = &Harl::debug;
	func_ptr[1] = &Harl::info;
	func_ptr[2] = &Harl::warning;
	func_ptr[3] = &Harl::error;
}

void Harl::debug(void) {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" << '\n';
}

void Harl::info(void) {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << '\n';
}

void Harl::warning(void) {
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << '\n';
}

void Harl::error(void) {
	std::cout << "This is unacceptable! I want to speak to the manager now." << '\n';
}

void Harl::complain(std::string level)
{
	int value = 0;
	for (value = 0; value < 4; ++value)
	{
		if (levels[value] == level) break ;
	}

	switch (value)
	{
		case (0) :
			std::cout << "[ DEBUG ]" << '\n';
			(this->*func_ptr[0])();
		case (1) :
			std::cout << "[ INFO ]" << '\n';
			(this->*func_ptr[1])();
		case (2) :
			std::cout << "[ WARNING ]" << '\n';
			(this->*func_ptr[2])();
		case (3) :
			std::cout << "[ ERROR ]" << '\n';
			(this->*func_ptr[3])();
		default:
			break;
	}
}
