#pragma once

#include <iostream>

class Serializer
{
	private:
		// Add member variables here

	public:
		// Constructors
		Serializer(/*Parameterized Constructor*/);
		Serializer(void);

		// Destructor
		~Serializer(void);

		// Getters and Setters


		// Member functions

		// Operators
		Serializer &operator=(const Serializer& src);
};

std::ostream& operator<<(std::ostream &output_stream, Serializer& src);


