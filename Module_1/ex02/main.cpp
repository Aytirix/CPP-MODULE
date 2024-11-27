#include <iostream>

int main(void)
{
	std::string var = "HI THIS IS BRAIN";
	std::string* ptr = &var;
	std::string& ref = var;

	std::cout << "Memory address of the string variable: " << &var << std::endl;
	std::cout << "Memory address held by stringPTR: " << ptr << std::endl;
	std::cout << "Memory address held by stringREF: " << &ref << std::endl;

	std::cout << "String variable: " << var << std::endl;
	std::cout << "StringPTR: " << *ptr << std::endl;
	std::cout << "StringREF: " << ref << std::endl;
	return 1;
}
