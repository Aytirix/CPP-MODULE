#include "Colors.hpp"
#include "Serializer.hpp"

int	main(void)
{
	Data			data;

	system("clear");
	data.id = 42;
	data.name = "TestData";
	std::cout << "Original data:" << std::endl;
	std::cout << "pointer original : " << &data << std::endl;
	std::cout << "ID: " << data.id << ", Name: " << data.name << std::endl;

	uintptr_t raw = Serializer::serialize(&data);
	std::cout << "raw : " << raw << std::endl;
	Data	*deserializedData = Serializer::deserialize(raw);

	std::cout << "pointer final : " << deserializedData << std::endl;
	std::cout << GREEN BOLD "Success! Deserialized data matches the original." RESET << std::endl;
	std::cout << "ID: " << deserializedData->id << ", Name: " << deserializedData->name << std::endl;
	return (0);
}
