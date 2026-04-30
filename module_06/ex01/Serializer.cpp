#include "Serializer.hpp"

// Member functions
uintptr_t Serializer::serialize(Data* ptr)
{
	uintptr_t uintptr_to_data = reinterpret_cast<uintptr_t>(ptr);

	std::cout << BLUE << "Data was sucesfully serialized." << DEFAULT << std::endl;

	return (uintptr_to_data);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	Data* dataptr_to_data = reinterpret_cast<Data*>(raw);

	std::cout << BLUE << "Data was sucesfully deserialized." << DEFAULT << std::endl;

	return (dataptr_to_data);
}
