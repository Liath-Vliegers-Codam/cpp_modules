#pragma once

#include "Data.hpp"

#include <fstream>
#include <iostream>
#include <string>

#define DEFAULT	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define MAGENTA	"\033[35m"
#define CYAN	"\033[36m"
#define WHITE	"\033[37m"

class Serializer
{
	private:
		// Add member variables here

	public:
		// Constructors
		Serializer(void);
		Serializer(const Serializer& other);


		// Destructor
		~Serializer(void);

		// Operators
		Serializer &operator=(const Serializer& other);

		// Getters and Setters

		// Member functions
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

std::ostream& operator<<(std::ostream &output_stream, Serializer& other);



