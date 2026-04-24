/*-------------------------------------------------------------------------

Exercise 00: 		Conversion of scalar types
Turn-in directory: 	ex00/
Files to turn in: 	Makefile, *.cpp, *.{h, hpp}
Allowed functions: 	Any function to convert from a string to an int, a float, or a double. 
This will help, but won’t do the whole job.

Write a class ScalarConverter that will contain only one static method "convert" 
that will take as a parameter a string representation of a C++ literal in its most common form 
and output its value in the following series of scalar types:
• char
• int
• float
• double

As this class doesn’t need to store anything at all, it must not be instantiable by users.
Except for char parameters, only the decimal notation will be used.

- Examples of char literals: ’c’, ’a’, ...

To make things simple, please note that non-displayable characters shouldn’t be used as inputs. 
If a conversion to char is not displayable, print an informative message.

- Examples of int literals: 0, -42, 42...

- Examples of float literals: 0.0f, -4.2f, 4.2f...

You have to handle these pseudo-literals as well (you know, for science): -inff, +inff, and nanf.

- Examples of double literals: 0.0, -4.2, 4.2...

You have to handle these pseudo-literals as well (you know, for fun): -inf, +inf, and nan.

Write a program to test that your class works as expected.
You have to:
- first detect the type of the literal passed as a parameter, 
- convert it from string to its actual type, 
- then convert it explicitly to the three other data types. 
- Lastly, display the results as shown below.

If a conversion does not make any sense or overflows, display a message to inform the user that the type conversion is impossible. 
Include any header you need in order to handle numeric limits and special values.

./convert 0
char: Non displayable
int: 0
float: 0.0f
double: 0.0

./convert nan
char: impossible
int: impossible
float: nanf
double: nan

./convert 42.0f
char: '*'
int: 42
float: 42.0f
double: 42.0

--------------------------------------------------------------------------*/

#include "ScalarConverter.hpp"

// int main(int argc, char** argv)
// {
// 	if (argc != 2)
// 	{
// 		std::cout << INVALID_INPUT_MESSAGE << std::endl;
// 		return (1);
// 	}
	
// 	std::string input;
// 	input = argv[1];

// 	if (input.empty())
// 	{
// 		std::cout << INVALID_INPUT_MESSAGE << std::endl;
// 		return (1);
// 	}

// 	try
// 	{
// 		ScalarConverter::convert(input);
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << std::endl;
// 	}

// 	return (0);
// }


// ============================ TEST CASES MAIN ================================
int main(int argc, char** argv)
{
	(void)argc;
	(void)argv;

	std::cout << RED << "\n===========SUBJECT CASES===========:" << DEFAULT << std::endl;
	
	std::cout << BLUE << "\nchar literals:" << DEFAULT << std::endl;
	ScalarConverter::convert("a");
	ScalarConverter::convert("c");
	ScalarConverter::convert(" ");

	std::cout << BLUE << "\nint literals:" << DEFAULT << std::endl;
	ScalarConverter::convert("0");
	ScalarConverter::convert("-42");
	ScalarConverter::convert("42");

	std::cout << BLUE << "\nfloat literals:" << DEFAULT << std::endl;
	ScalarConverter::convert("0.0f");
	ScalarConverter::convert("-4.2f");
	ScalarConverter::convert("4.2f");
	ScalarConverter::convert("-inff");
	ScalarConverter::convert("+inff");
	ScalarConverter::convert("nanf");

	std::cout << BLUE << "\ndouble literals:" << DEFAULT << std::endl;
	ScalarConverter::convert("0.0");
	ScalarConverter::convert("-4.2");
	ScalarConverter::convert("4.2");
	ScalarConverter::convert("-inf");
	ScalarConverter::convert("+inf");
	ScalarConverter::convert("nan");

	std::cout << RED << "\n===========FAIL CASES===========: \n" << DEFAULT << std::endl;

	ScalarConverter::convert(".0");
	ScalarConverter::convert("0.");
	ScalarConverter::convert("0.0.");
	ScalarConverter::convert(".0f");
	ScalarConverter::convert("0.f");
	ScalarConverter::convert("0.0.f");
	ScalarConverter::convert("780987f");
	ScalarConverter::convert("214.7483.647");
	ScalarConverter::convert("nanff");
	ScalarConverter::convert("111i111");

	std::cout << RED << "\n===========EDGE CASES===========:" << DEFAULT << std::endl;

	std::cout << YELLOW << "\nINTS: \n" << DEFAULT << std::endl;

	std::cout << BLUE << "INT_MAX:" << DEFAULT << std::endl;
	ScalarConverter::convert("2147483647");		// INT_MAX
	std::cout << BLUE << "INT_MIN:" << DEFAULT << std::endl;
	ScalarConverter::convert("-2147483648");	// INT_MIN

	std::cout << BLUE << "INT_MAX + 1:" << DEFAULT << std::endl;
	ScalarConverter::convert("2147483648");		// INT_MAX + 1
	std::cout << BLUE << "INT_MAX - 1:" << DEFAULT << std::endl;
	ScalarConverter::convert("2147483646");		// INT_MAX - 1

	std::cout << BLUE << "INT_MIN + 1:" << DEFAULT << std::endl;
	ScalarConverter::convert("-2147483647");	// INT_MIN + 1
	std::cout << BLUE << "INT_MIN - 1:" << DEFAULT << std::endl;
	ScalarConverter::convert("-2147483649");	// INT_MIN - 1

	std::cout << BLUE << "INT_MAX in float:" << DEFAULT << std::endl;
	ScalarConverter::convert("2147483647.0f");	// INT_MAX in float
	std::cout << BLUE << "INT_MIN in float:" << DEFAULT << std::endl;
	ScalarConverter::convert("-2147483648.0f");	// INT_MIN in float
	
	std::cout << BLUE << "INT_MAX + 1 in float:" << DEFAULT << std::endl;
	ScalarConverter::convert("2147483648.0f");	// INT_MAX + 1 in float
	std::cout << BLUE << "INT_MIN - 1 in float:" << DEFAULT << std::endl;
	ScalarConverter::convert("-2147483649.0f");	// INT_MIN - 1 in float

	std::cout << BLUE << "INT_MAX in double:" << DEFAULT << std::endl;
	ScalarConverter::convert("2147483647.0");	// INT_MAX in double
	std::cout << BLUE << "INT_MIN in double:" << DEFAULT << std::endl;
	ScalarConverter::convert("-2147483648.0");	// INT_MIN in double

	std::cout << BLUE << "INT_MAX + 1 in double:" << DEFAULT << std::endl;
	ScalarConverter::convert("2147483648.0");	// INT_MAX + 1 in double
	std::cout << BLUE << "INT_MIN - 1 in double:" << DEFAULT << std::endl;
	ScalarConverter::convert("-2147483649.0");	// INT_MIN - 1 in double


	std::string FLOAT_MAX_VALUE = std::to_string(std::numeric_limits<float>::max());
	std::string FLOAT_MIN_VALUE = std::to_string(std::numeric_limits<float>::lowest());
	std::string DOUBLE_MAX_VALUE = std::to_string(std::numeric_limits<double>::max());
	std::string DOUBLE_MIN_VALUE = std::to_string(std::numeric_limits<double>::lowest());


	std::cout << YELLOW << "\nFLOATS: \n" << DEFAULT << std::endl;

	std::cout << BLUE << "INT_MAX in float:" << DEFAULT << std::endl;
	ScalarConverter::convert("2147483647.0f");	// INT_MAX in float
	std::cout << BLUE << "INT_MIN in float:" << DEFAULT << std::endl;
	ScalarConverter::convert("-2147483648.0f");	// INT_MIN in float

	std::cout << BLUE << "FLOAT_MAX:" << DEFAULT << std::endl;
	ScalarConverter::convert(FLOAT_MAX_VALUE + "f");	// FLOAT_MAX
	ScalarConverter::convert("340282346638528859811704183484516925440.000000f");	// FLOAT_MAX
	ScalarConverter::convert("340282346638528859811704183484516925450.000000f");	// FLOAT_MAX + 10
	
	std::cout << BLUE << "FLOAT_MIN:" << DEFAULT << std::endl;
	ScalarConverter::convert(FLOAT_MIN_VALUE + "f");	// FLOAT_MIN
	ScalarConverter::convert("-340282346638528859811704183484516925440.000000f");	// FLOAT_MIN
	ScalarConverter::convert("-340282346638528859811704183484516925450.000000f");	// FLOAT_MIN - 10


	std::cout << YELLOW << "\nDOUBLES: \n" << DEFAULT << std::endl;
	
	std::cout << BLUE << "INT_MAX in double:" << DEFAULT << std::endl;
	ScalarConverter::convert("2147483647.0");	// INT_MAX in double
	std::cout << BLUE << "INT_MIN in double:" << DEFAULT << std::endl;
	ScalarConverter::convert("-2147483648.0");	// INT_MIN in double
	
	std::cout << BLUE << "FLOAT_MAX in double:" << DEFAULT << std::endl;
	ScalarConverter::convert(FLOAT_MAX_VALUE);	// FLOAT_MAX in double
	std::cout << BLUE << "FLOAT_MIN in double:" << DEFAULT << std::endl;
	ScalarConverter::convert(FLOAT_MIN_VALUE);	// FLOAT_MIN in double
	
	std::cout << BLUE << "DOUBLE_MAX:" << DEFAULT << std::endl;
	ScalarConverter::convert(DOUBLE_MAX_VALUE);	// DOUBLE_MAX
	ScalarConverter::convert("179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000"); // DOUBLE_MAX
	std::cout << BLUE << "DOUBLE_MIN:" << DEFAULT << std::endl;
	ScalarConverter::convert(DOUBLE_MIN_VALUE);	// DOUBLE_MIN
	ScalarConverter::convert("-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000"); // DOUBLE_MAX

	return (0);
}
