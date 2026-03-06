#include "Serializer.hpp"


// Constructors
Serializer::Serializer(void)
{
    std::cout << "Serializer default constructor is called" << std::endl;
}

Serializer::Serializer(const Serializer& other)
{
	std::cout << "Serializer copy constructor is called" << std::endl;
	*this = other;
}

// Destructor
Serializer::~Serializer(void)
{
    std::cout << "Serializer destructor is called" << std::endl;
}

// Getters and Setters

// Member functions
uintptr_t Serializer::serialize(Data* ptr)
{
	uintptr_t uintptr_to_data = reinterpret_cast<uintptr_t>(ptr);

	std::cout << "Data was sucesfully serialized." << std::endl;

	return (uintptr_to_data);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	Data* dataptr_to_data = reinterpret_cast<Data*>(raw);

	std::cout << "Data was sucesfully deserialized." << std::endl;

	return (dataptr_to_data);
}

// Overload operators
Serializer& Serializer::operator=(const Serializer& other)
{
	if (this != &other)
	{
		std::cout << "Serializer copy assignment is called" << std::endl;
		*this = other;
	}
	return (*this);
}

std::ostream& operator<<(std::ostream& output_stream, Serializer& other)
{
	(void) other;

	output_stream << "*Serializer Class info here*" << std::endl;
	return (output_stream);
}


