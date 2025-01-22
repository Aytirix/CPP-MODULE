#include "Colors.hpp"
#include "Serializer.hpp"

int	main(void)
{
	Data			data;
	unsigned long	raw;
	Data			*deserializedData;

	system("clear");
	data.id = 42;
	data.name = "TestData";
	std::cout << "Original data:" << std::endl;
	std::cout << "ID: " << data.id << ", Name: " << data.name << std::endl;

	raw = Serializer::serialize(&data);
	deserializedData = Serializer::deserialize(raw);

	std::cout << GREEN BOLD "Success! Deserialized data matches the original." RESET << std::endl;
	std::cout << "ID: " << deserializedData->id << ", Name: " << deserializedData->name << std::endl;
	return (0);
}
