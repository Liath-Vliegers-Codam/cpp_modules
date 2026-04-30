
#include "ScalarConverter.hpp"

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cout << INVALID_INPUT_MESSAGE << std::endl;
		return (1);
	}
	
	std::string input;
	input = argv[1];

	if (input.empty())
	{
		std::cout << INVALID_INPUT_MESSAGE << std::endl;
		return (1);
	}

	try
	{
		ScalarConverter::convert(input);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}


// // // ============================ TEST CASES MAIN ================================

// int main(int argc, char** argv)
// {
// 	(void)argc;
// 	(void)argv;

// 	std::cout << RED << "\n===========SUBJECT CASES===========:" << DEFAULT << std::endl;
	
// 	ScalarConverter::convert("0");
// 	ScalarConverter::convert("nan");
// 	ScalarConverter::convert("42.0f");

// 	std::cout << BLUE << "\nchar literals:" << DEFAULT << std::endl;
// 	ScalarConverter::convert("a");
// 	ScalarConverter::convert("c");
// 	ScalarConverter::convert(" ");

// 	std::cout << BLUE << "\nint literals:" << DEFAULT << std::endl;
// 	ScalarConverter::convert("0");
// 	ScalarConverter::convert("-42");
// 	ScalarConverter::convert("42");

// 	std::cout << BLUE << "\nfloat literals:" << DEFAULT << std::endl;
// 	ScalarConverter::convert("0.0f");
// 	ScalarConverter::convert("-4.2f");
// 	ScalarConverter::convert("4.2f");
// 	ScalarConverter::convert("-inff");
// 	ScalarConverter::convert("+inff");
// 	ScalarConverter::convert("nanf");

// 	std::cout << BLUE << "\ndouble literals:" << DEFAULT << std::endl;
// 	ScalarConverter::convert("0.0");
// 	ScalarConverter::convert("-4.2");
// 	ScalarConverter::convert("4.2");
// 	ScalarConverter::convert("-inf");
// 	ScalarConverter::convert("+inf");
// 	ScalarConverter::convert("nan");

// 	std::cout << RED << "\n===========FAIL CASES===========: \n" << DEFAULT << std::endl;

// 	ScalarConverter::convert(".0");
// 	ScalarConverter::convert("0.");
// 	ScalarConverter::convert("0.0.");
// 	ScalarConverter::convert(".0f");
// 	ScalarConverter::convert("0.f");
// 	ScalarConverter::convert("0.0.f");
// 	ScalarConverter::convert("780987f");
// 	ScalarConverter::convert("214.7483.647");
// 	ScalarConverter::convert("nanff");
// 	ScalarConverter::convert("111i111");

// 	std::cout << RED << "\n===========EDGE CASES===========:" << DEFAULT << std::endl;

// 	std::cout << YELLOW << "\nINTS: \n" << DEFAULT << std::endl;

// 	std::cout << BLUE << "INT_MAX:" << DEFAULT << std::endl;
// 	ScalarConverter::convert("2147483647");	
// 	std::cout << BLUE << "INT_MIN:" << DEFAULT << std::endl;
// 	ScalarConverter::convert("-2147483648");

// 	std::cout << BLUE << "INT_MAX + 1:" << DEFAULT << std::endl;
// 	ScalarConverter::convert("2147483648");	
// 	std::cout << BLUE << "INT_MAX - 1:" << DEFAULT << std::endl;
// 	ScalarConverter::convert("2147483646");	

// 	std::cout << BLUE << "INT_MIN + 1:" << DEFAULT << std::endl;
// 	ScalarConverter::convert("-2147483647");
// 	std::cout << BLUE << "INT_MIN - 1:" << DEFAULT << std::endl;
// 	ScalarConverter::convert("-2147483649");

// 	std::string FLOAT_MAX_VALUE = std::to_string(std::numeric_limits<float>::max());
// 	std::string FLOAT_MIN_VALUE = std::to_string(std::numeric_limits<float>::lowest());
// 	std::string DOUBLE_MAX_VALUE = std::to_string(std::numeric_limits<double>::max());
// 	std::string DOUBLE_MIN_VALUE = std::to_string(std::numeric_limits<double>::lowest());

// 	std::cout << YELLOW << "\nFLOATS: \n" << DEFAULT << std::endl;

// 	std::cout << BLUE << "INT_MAX in float:" << DEFAULT << std::endl;
// 	ScalarConverter::convert("2147483647.0f");
// 	std::cout << BLUE << "INT_MIN in float:" << DEFAULT << std::endl;
// 	ScalarConverter::convert("-2147483648.0f");

// 	std::cout << BLUE << "FLOAT_MAX:" << DEFAULT << std::endl;
// 	ScalarConverter::convert(FLOAT_MAX_VALUE + "f");
// 	ScalarConverter::convert("340282346638528859811704183484516925440.000000f");
	
// 	std::cout << BLUE << "FLOAT_MIN:" << DEFAULT << std::endl;
// 	ScalarConverter::convert(FLOAT_MIN_VALUE + "f");
// 	ScalarConverter::convert("-340282346638528859811704183484516925440.000000f");

// 	std::cout << YELLOW << "\nDOUBLES: \n" << DEFAULT << std::endl;
	
// 	std::cout << BLUE << "INT_MAX in double:" << DEFAULT << std::endl;
// 	ScalarConverter::convert("2147483647.0");
// 	std::cout << BLUE << "INT_MIN in double:" << DEFAULT << std::endl;
// 	ScalarConverter::convert("-2147483648.0");
	
// 	std::cout << BLUE << "FLOAT_MAX in double:" << DEFAULT << std::endl;
// 	ScalarConverter::convert(FLOAT_MAX_VALUE);
// 	std::cout << BLUE << "FLOAT_MIN in double:" << DEFAULT << std::endl;
// 	ScalarConverter::convert(FLOAT_MIN_VALUE);
	
// 	std::cout << BLUE << "DOUBLE_MAX:" << DEFAULT << std::endl;
// 	ScalarConverter::convert(DOUBLE_MAX_VALUE);
// 	ScalarConverter::convert("179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000");
// 	std::cout << BLUE << "DOUBLE_MIN:" << DEFAULT << std::endl;
// 	ScalarConverter::convert(DOUBLE_MIN_VALUE);
// 	ScalarConverter::convert("-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000");

// 	std::cout << RED << "DECIMAL TESTS:" << DEFAULT << std::endl;

// 	ScalarConverter::convert("42.0");
// 	ScalarConverter::convert("42.00");
// 	ScalarConverter::convert("42.000000000");
// 	ScalarConverter::convert("4.2f");
// 	ScalarConverter::convert("4.20f");
// 	ScalarConverter::convert("4.2000000000f");
// 	ScalarConverter::convert("4.2000000000");
// 	ScalarConverter::convert("2147483647.0");
// 	ScalarConverter::convert("214748.23424234");
// 	ScalarConverter::convert("0.1f");
// 	ScalarConverter::convert("0.1");
// 	ScalarConverter::convert("1.23456789f");
// 	ScalarConverter::convert("1.2345678901234567");

// 	return (0);
// }



// // MATH EXPAINATIONS:

// // A float has only 24 bits of integer precision (including the hidden bit), so it can represent all integers exactly only up to (2^{24}).
// // 2147483647 is (2^{31}-1), far beyond that exact range.
// // Near (2^{31}), adjacent representable float values are 256 apart, so 2147483647 cannot be stored exactly.
// // The nearest representable float is 2147483648.0f ((2^{31})), so it rounds up by 1.
// // double has 53 bits of precision, so it can represent all 32-bit int values exactly.


// // float has 24 bits of precision (including hidden bit), which needs up to 9 decimal digits to uniquely recover the same binary float value.
// // double has 53 bits of precision, which needs up to 17 decimal digits for the same guarantee.

// // In C++, these are exposed as:
// // std::numeric_limits<float>::max_digits10 = 9
// // std::numeric_limits<double>::max_digits10 = 17

// // those numbers are the standard “round-trip safe” decimal counts for IEEE-754 types.

// // The math behind it is:
// // max_digits10=⌈𝑝⋅log^⁡10(2)+1⌉
// // where p is the number of binary precision bits.

// // for float: 𝑝=24⇒9p=24⇒9
// // for double: 𝑝=53⇒17p=53⇒17
// // That is why you see 9 and 17, independent of how many decimals were typed in the input string.