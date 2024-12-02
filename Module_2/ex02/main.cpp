#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << "max : " << Fixed::max(a, b) << std::endl;
	std::cout << "min : " << Fixed::min(a, b) << std::endl;

	std::cout << std::endl << "My tests :" << std::endl;
	Fixed c(10);
	Fixed d(5);
	std::cout << "c = " << c << std::endl;
	std::cout << "d = " << d << std::endl;
	std::cout << "c + d = " << c + d << std::endl;
	std::cout << "c - d = " << c - d << std::endl;
	std::cout << "c * d = " << c * d << std::endl;
	std::cout << "c / d = " << c / d << std::endl;
	std::cout << "c > d = " << (c > d) << std::endl;
	std::cout << "c < d = " << (c < d) << std::endl;
	std::cout << "c >= d = " << (c >= d) << std::endl;
	std::cout << "c <= d = " << (c <= d) << std::endl;
	std::cout << "c == d = " << (c == d) << std::endl;
	std::cout << "c != d = " << (c != d) << std::endl;

	d = c;
	std::cout << std::endl << "d = " << d << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "c > d = " << (c > d) << std::endl;
	std::cout << "c < d = " << (c < d) << std::endl;
	std::cout << "c >= d = " << (c >= d) << std::endl;
	std::cout << "c <= d = " << (c <= d) << std::endl;
	std::cout << "c == d = " << (c == d) << std::endl;
	std::cout << "c != d = " << (c != d) << std::endl;

	return 0;
}