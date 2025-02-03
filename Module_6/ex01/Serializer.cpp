#include "Serializer.hpp"

// Constructors and destructors

Serializer::Serializer()
{
	std::cout << RED BOLD "Serializer " GRAY " is created!" << RESET << std::endl;
}

Serializer::Serializer(const Serializer &other)
{
	std::cout << RED BOLD "Serializer " GRAY " copied!" << RESET << std::endl;
	*this = other;
}

Serializer &Serializer::operator=(const Serializer &other)
{
	std::cout << RED BOLD "Serializer " GRAY " assigned!" << RESET << std::endl;
	(void)other;
	return (*this);
}

Serializer::~Serializer()
{
	std::cout << RED BOLD "Serializer " GRAY " is destroyed!" << RESET << std::endl;
}

// Functions

uintptr_t Serializer::serialize(Data *ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data *>(raw);
}
