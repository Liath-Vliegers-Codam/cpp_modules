#include "ScalarConverter.hpp"

void ScalarConverter::convert_char(const char &input)
{
	std::cout << "char: '" << input << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(input) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(input) << "f" <<std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(input) <<std::endl;
}

void ScalarConverter::convert_int(const std::string &input)
{
	// convert input to int
	int int_value = 0;
	try 
	{
		int_value = std::stoi(input);
	}
	catch (const std::exception &)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}

	// print char
	if (int_value < 0 || int_value > 127)
		std::cout << "char: impossible" << std::endl;
	else if ((int_value < 32 || int_value > 126))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(int_value) << "'"<< std::endl;
	
	// print int and float and double
	std::cout << "int: " << int_value << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(int_value) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(int_value) << std::endl;
}

void ScalarConverter::convert_float(const std::string &input)
{
	// convert input to float
	float float_value = 0.0f;
	try 
	{
		float_value = std::stof(input);
	}
	catch (const std::exception &)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}
	
	// print char
	if (is_pseudo_float(input) || float_value < 0.0f || float_value > 127.0f)
		std::cout << "char: impossible" << std::endl;
	else if (float_value < 32.0f || float_value > 126.0f)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(float_value) << "'" << std::endl;

	// print int
	double float_value_d = static_cast<double>(float_value);
	if (is_pseudo_float(input) || float_value_d > static_cast<double>(std::numeric_limits<int>::max()) || float_value_d < static_cast<double>(std::numeric_limits<int>::min()))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(float_value) << std::endl;

	// print float and double
	std::cout << "float: " << std::fixed << std::setprecision(1) << float_value << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << (static_cast<double>(float_value)) << std::endl;
}

// A float has only 24 bits of integer precision (including the hidden bit), so it can represent all integers exactly only up to (2^{24}).
// 2147483647 is (2^{31}-1), far beyond that exact range.
// Near (2^{31}), adjacent representable float values are 256 apart, so 2147483647 cannot be stored exactly.
// The nearest representable float is 2147483648.0f ((2^{31})), so it rounds up by 1.
// double has 53 bits of precision, so it can represent all 32-bit int values exactly, which is why your double output stays correct.

void ScalarConverter::convert_double(const std::string &input)
{
	// convert input to double
	double double_value = 0.0;
	try 
	{
		double_value = std::stod(input);
	}
	catch (const std::exception &)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}

	// print char
	if (is_pseudo_double(input) || double_value < 0.0 || double_value > 127.0)
		std::cout << "char: impossible" << std::endl;
	else if (double_value < 32.0 || double_value > 126.0)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(double_value) << "'" << std::endl;

	// print int
	if (is_pseudo_double(input) || double_value < static_cast<double>(INT_MIN) || double_value > static_cast<double>(INT_MAX))
		std::cout << "int: impossible" << std::endl;
	else 
		std::cout << "int: " << static_cast<int>(double_value) << std::endl;

	// print float
	float double_value_f = static_cast<float>(double_value);
	if (double_value_f > std::numeric_limits<float>::max() || double_value_f < std::numeric_limits<float>::lowest())
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << std::fixed << std::setprecision(1) << (static_cast<float>(double_value)) << "f" << std::endl;

	// print double
	std::cout << "double: " << std::fixed << std::setprecision(1) << double_value << std::endl;
}
