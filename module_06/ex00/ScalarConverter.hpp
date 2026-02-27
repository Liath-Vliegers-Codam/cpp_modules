#pragma once

# include <iostream>
# include <string>
# include <sstream>
# include <cmath>
# include <limits>
# include <cstdlib>
# include <iomanip>

#define INVALID_INPUT_MESSAGE "Invalid input. Run program with a char, an int, a float or a double as argument."

enum ScalarType
{
	CHAR,		// 0
	INT,		// 1
	FLOAT,		// 2
	DOUBLE,		// 3
	INVALID		// 4
};

class ScalarConverter
{
	private:

	public:
		ScalarConverter();
		~ScalarConverter();

		// ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);

		static void convert(std::string input);
};

// std::ostream& operator<<(std::ostream &output_stream, ScalarConverter& src);
