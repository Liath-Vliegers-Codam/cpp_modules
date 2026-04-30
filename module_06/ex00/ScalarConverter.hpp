#pragma once

# include <iostream>
# include <string>
# include <sstream>
# include <cmath>
# include <limits>
# include <climits>
# include <cstdlib>
# include <iomanip>

#define DEFAULT	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define MAGENTA	"\033[35m"
#define CYAN	"\033[36m"
#define WHITE	"\033[37m"

#define INVALID_INPUT_MESSAGE "Invalid input. Run program with a char, an int, a float or a double as argument."

enum ScalarType
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	INVALID
};

class ScalarConverter
{
	private:
		// Constructors
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);

		// Destructor
		~ScalarConverter();

		// Operators
		ScalarConverter& operator=(const ScalarConverter& other);

		// Getters and Setters

		// Member functions
		static bool is_pseudo_float(std::string input);
		static bool is_pseudo_double(std::string input);
		static void convert_char(const char &input);
		static void convert_int(const std::string &input);
		static void convert_float(const std::string &input);
		static void convert_double(const std::string &input);
		static bool is_int(std::string input);
		static bool is_float(std::string input);
		static bool is_double(std::string input);
		static ScalarType whichType(std::string input);

	public:
		static void convert(std::string input);
};

std::ostream& operator<<(std::ostream &output_stream, ScalarConverter& other);
