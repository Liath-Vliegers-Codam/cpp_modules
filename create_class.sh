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

		// Getters and Setters


		// Member functions

		// Operators
		${classname} &operator=(const ${classname}& src);
};

std::ostream& operator<<(std::ostream &output_stream, ${classname}& src);


EOL

# Create the .cpp file
cat > "${classname}.cpp" <<EOL
#include "${classname}.hpp"

/*Member functions*/
void ${classname}::method()
{
    // Method implementation
}

/*Getters and Setters*/

/*Constructors*/
${classname}::${classname}(/*Parameterized Constructor*/)
{
   std::cout << "${classname} parameterized constructor is called" << std::endl;
}

${classname}::${classname}()
{
    std::cout << "${classname} default constructor is called" << std::endl;
}

/*Destructors*/
${classname}::~${classname}( void )
{
    std::cout << "${classname} destructor is called" << std::endl;
}

/*Overload operators*/
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
	return output_stream;
}

EOL

echo "Class ${classname} created with ${classname}.hpp and ${classname}.cpp"
