 #!/bin/bash

# Get the class name from the first argument
classname=$1
uppercase_classname=$(echo "$classname" | tr '[:lower:]' '[:upper:]')

# Create the .hpp file
cat > "${classname}.hpp" <<EOL
#pragma once

#include <iostream>

#define DEFAULT	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define MAGENTA	"\033[35m"
#define CYAN	"\033[36m"
#define WHITE	"\033[37m"

class ${classname}
{
	private:
		// Add member variables here

	public:
		// Constructors
		${classname}(void);
		${classname}(/*Parameterized Constructor*/);
		${classname}(const ${classname}& other);

		// Destructor
		~$classname(void);

		// Operators
		${classname} &operator=(const ${classname}& other);

		// Getters and Setters

		// Member functions
};

std::ostream& operator<<(std::ostream &output_stream, ${classname}& src);

// Exceptions
class ExceptionName : public std::exception
{
	const char* what() const noexcept override;
};

EOL

# Create the .cpp file
cat > "${classname}.cpp" <<EOL
#include "${classname}.hpp"

// Constructors
${classname}::${classname}(void)
{
    std::cout << "${classname} default constructor is called" << std::endl;
}

${classname}::${classname}(/*Parameters here*/)
{
   std::cout << "${classname} parameterized constructor is called" << std::endl;
}

${classname}::${classname}(const ${classname}& other)
{
	std::cout << "${classname} copy constructor is called" << std::endl;
	*this = other;
}

// Destructor
${classname}::~${classname}(void)
{
    std::cout << "${classname} destructor is called" << std::endl;
}

// Getters and Setters

// Member functions


// Overload operators
${classname}& ${classname}::operator=(const ${classname}& other)
{
	if (this != &other)
	{
		std::cout << "${classname} copy assignment is called" << std::endl;
		*this = other;
	}
	return (*this);
}

std::ostream& operator<<(std::ostream& output_stream, ${classname}& src)
{
	output_stream << "*${classname} Class info here*" << std::endl;
	return (output_stream);
}

// Exceptions
const char* ExceptionName::what() const noexcept
{
	return ("*Exception info here*");
}

EOL

echo "Class ${classname} created with ${classname}.hpp and ${classname}.cpp"
