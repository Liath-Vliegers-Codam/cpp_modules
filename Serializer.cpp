#include "Serializer.hpp"

// Member functions
void Serializer::method()
{
    // Method implementation
}

// Getters and Setters

// Constructors
Serializer::Serializer(/*Parameterized Constructor*/)
{
   std::cout << "Serializer parameterized constructor is called" << std::endl;
}

Serializer::Serializer()
{
    std::cout << "Serializer default constructor is called" << std::endl;
}

// Destructor
Serializer::~Serializer(void)
{
    std::cout << "Serializer destructor is called" << std::endl;
}

// Overload operators
Serializer& Serializer::operator=(const Serializer& src)
{
	std::cout << "Serializer copy assignment is called" << std::endl;
	if (this != &src)
	{
		// Assinment variables
	}
	return (*this);
}

std::ostream& operator<<(std::ostream& output_stream, Serializer& src)
{
	output_stream << "* Serializer Class info*" << std::endl;
	return output_stream;
}

