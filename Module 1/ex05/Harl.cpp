#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::debug()
{
	std::cout << "\033[34m[DEBUG] This is a debug message\033[0m" << std::endl;
}

void Harl::info()
{
	std::cout << "\033[32m[INFO] This is an info message\033[0m" << std::endl;
}

void Harl::warning()
{
	std::cout << "\033[33m[WARNING] This is a warning message\033[0m" << std::endl;
}

void Harl::error()
{
	std::cout << "\033[31m[ERROR] This is an error message\033[0m" << std::endl;
}

void Harl::complain(std::string level)
{
	void (Harl::*f[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*f[i])();
			return;
		}
	}
}

int main(void)
{
	Harl harl;

	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");
	return 1;
}
