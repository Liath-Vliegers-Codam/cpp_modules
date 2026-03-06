 #!/bin/bash

# Get the class name from the first argument
classname=$1
uppercase_classname=$(echo "$classname" | tr '[:lower:]' '[:upper:]')

# Create the .hpp file
cat > "${classname}.hpp" <<EOL
#pragma once

#include <iostream>

class ${classname}
{
	private:
		// Add member variables here

	public:
		// Constructors
		${classname}(/*Parameterized Constructor*/);
		${classname}(void);

		// Destructor
		~$classname(void);

		// Operators
		${classname} &operator=(const ${classname}& src);

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

${classname}::${classname}(/*Parameterized Constructor*/)
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
${classname}& ${classname}::operator=(const ${classname}& src)
{
	std::cout << "${classname} copy assignment is called" << std::endl;
	if (this != &src)
	{
		// Assinment variables
	}
	return (*this);
}

std::ostream& operator<<(std::ostream& output_stream, ${classname}& src)
{
	output_stream << "* ${classname} Class info*" << std::endl;
	return (output_stream);
}

// Exceptions
const char* ExceptionName::what() const noexcept
{
	return ("Grade is too high.");
}

EOL

echo "Class ${classname} created with ${classname}.hpp and ${classname}.cpp"
