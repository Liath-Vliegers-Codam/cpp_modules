
#include "RPN.hpp"

int main(int argc, char* argv[])
{
	if (argc != 2)
	{	
		std::cerr << "Error: run program with argument" << std::endl;
		return (1);
	}

	RPN(argv[1]);

	return (0);
}


// int main()
// {
// 	std::cout << YELLOW << "===== SUBJECT TESTS =====" << DEFAULT << std::endl;
// 	std::cout << "Result should be 42		Result is "; RPN("8 9 * 9 - 9 - 9 - 4 - 1 +"); 	// 42
// 	std::cout << "Result should be 42		Result is "; RPN("7 7 * 7 -"); 					// 42
// 	std::cout << "Result should be 0		Result is "; RPN("1 2 * 2 / 2 * 2 4 - +"); 		// 0
// 	std::cout << "Result should be Error		Result is "; RPN("(1 + 1)");				// Error
// 	std::cout << "Result should be 35		Result is "; RPN("7 7 * 7 7 + -"); 				// 35

// 	std::cout << YELLOW << "===== BASIC TESTS =====" << DEFAULT << std::endl;
// 	std::cout << "Result should be 7		Result is "; RPN("3 4 +");						// = 7
// 	std::cout << "Result should be 7		Result is "; RPN("9 2 -");						// = 7
// 	std::cout << "Result should be 42		Result is "; RPN("6 7 *");						// = 42
// 	std::cout << "Result should be 4		Result is "; RPN("8 2 /");						// = 4

// 	std::cout << YELLOW << "===== MEDIUM TESTS =====" << DEFAULT << std::endl;
// 	std::cout << "Result should be 14		Result is "; RPN("3 4 + 2 *");					// = 14
// 	std::cout << "Result should be 14		Result is "; RPN("5 1 2 + 4 * + 3 -");			// = 14
// 	std::cout << "Result should be 1		Result is "; RPN("8 2 / 3 -");					// = 1
// 	std::cout << "Result should be 14		Result is "; RPN("2 3 4 + *");					// = 14
// 	std::cout << "Result should be 18		Result is "; RPN("9 3 1 - *");					// = 18
// 	std::cout << "Result should be 1		Result is "; RPN("7 2 3 * -");					// = 1
// 	std::cout << "Result should be 10		Result is "; RPN("4 5 * 2 /");					// = 10
// 	std::cout << "Result should be 30		Result is "; RPN("8 3 - 2 4 + *");				// = 30

// 	std::cout << YELLOW << "===== COMPLEX TESTS =====" << DEFAULT << std::endl;
// 	std::cout << "Result should be 13		Result is "; RPN("5 6 2 + * 3 /");				// = 13
// 	std::cout << "Result should be 75		Result is "; RPN("7 8 + 3 2 + *");				// = 75
// 	std::cout << "Result should be 7		Result is "; RPN("9 5 2 + * 8 /");				// = 7
// 	std::cout << "Result should be 141		Result is "; RPN("3 5 8 * 7 + *");				// = 141
// 	std::cout << "Result should be 55		Result is "; RPN("2 3 + 5 6 + *");				// = 55
// 	std::cout << "Result should be 11		Result is "; RPN("9 1 - 2 / 7 +");				// = 11
// 	std::cout << "Result should be 15		Result is "; RPN("6 2 / 3 4 * +");				// = 15
// 	std::cout << "Result should be 11		Result is "; RPN("5 1 2 + 4 * + 3 2 * -");		// = 11

// 	std::cout << YELLOW << "===== LONG EXPRESSION TESTS =====" << DEFAULT << std::endl;
// 	std::cout << "Result should be 15		Result is "; RPN("1 2 + 3 + 4 + 5 +");			// = 15
// 	std::cout << "Result should be 35		Result is "; RPN("9 8 + 7 + 6 + 5 +");			// = 35
// 	std::cout << "Result should be 120		Result is "; RPN("2 3 * 4 * 5 *");				// = 120
// 	std::cout << "Result should be 11		Result is "; RPN("9 2 / 3 * 4 + 5 -");			// = 11
// 	std::cout << "Result should be 28		Result is "; RPN("8 2 + 3 * 4 2 / -");			// = 28
// 	std::cout << "Result should be 37		Result is "; RPN("7 3 2 + * 4 2 / +");			// = 37
// 	std::cout << "Result should be 43		Result is "; RPN("9 2 3 + * 8 4 / -");			// = 43
// 	std::cout << "Result should be 2075		Result is "; RPN("5 9 8 + 4 6 * * 7 + *");		// = 2075

// 	std::cout << YELLOW << "===== NEGATIVE RESULTS =====" << DEFAULT << std::endl;
// 	std::cout << "Result should be -4		Result is "; RPN("3 7 -");						// = -4
// 	std::cout << "Result should be -8		Result is "; RPN("5 9 - 2 *");					// = -8
// 	std::cout << "Result should be -5		Result is "; RPN("2 3 4 + -");					// = -5
// 	std::cout << "Result should be 1		Result is "; RPN("1 2 - 3 4 - *");				// = 1
// 	std::cout << "Result should be -1		Result is "; RPN("6 8 - 2 /");					// = -1

// 	std::cout << YELLOW << "===== INTEGER DIVISION =====" << DEFAULT << std::endl;
// 	std::cout << "Result should be 3		Result is "; RPN("7 2 /");						// = 3
// 	std::cout << "Result should be 2		Result is "; RPN("9 4 /");						// = 2
// 	std::cout << "Result should be 2		Result is "; RPN("8 3 /");						// = 2
// 	std::cout << "Result should be 6		Result is "; RPN("5 2 / 3 *");					// = 6
// 	std::cout << "Result should be 4		Result is "; RPN("7 3 / 2 +");					// = 4

// 	std::cout << YELLOW << "===== VERY NESTED TESTS =====" << DEFAULT << std::endl;
// 	std::cout << "Result should be 39		Result is "; RPN("2 3 + 4 5 + * 6 -");			// = 39
// 	std::cout << "Result should be 28		Result is "; RPN("5 1 2 + 4 * + 3 - 2 *");		// = 28
// 	std::cout << "Result should be 20		Result is "; RPN("3 4 5 * + 6 2 / -");			// = 20
// 	std::cout << "Result should be 8		Result is "; RPN("8 2 / 3 3 * + 5 -");			// =
// 	std::cout << "Result should be 23		Result is "; RPN("9 2 3 * - 4 5 * +");			// = 23
// 	std::cout << "Result should be 32		Result is "; RPN("7 2 3 + * 8 4 / + 5 -");		// = 32

// 	std::cout << YELLOW << "===== EDGE CASES =====" << DEFAULT << std::endl;
// 	std::cout << "Result should be 1		Result is "; RPN("0 1 +");						// = 1
// 	std::cout << "Result should be 0		Result is "; RPN("0 5 *");						// = 0
// 	std::cout << "Result should be 9		Result is "; RPN("9 9 * 9 /");					// = 9
// 	std::cout << "Result should be 5		Result is "; RPN("1 1 + 1 + 1 + 1 +");			// = 5
// 	std::cout << "Result should be -1		Result is "; RPN("9 1 - 2 - 3 - 4 -");			// = -1

// 	std::cout << YELLOW << "===== ERROR TESTS =====" << DEFAULT << std::endl;
// 	std::cout << "Result should be Error		Result is "; RPN("");						// -> Error (empty input)
// 	std::cout << "Result should be Error		Result is "; RPN("3 4");					// -> Error (too many operands left)
// 	std::cout << "Result should be Error		Result is "; RPN("2 3");					// -> Error (too many operands left)
// 	std::cout << "Result should be Error		Result is "; RPN("2 +");					// -> Error (operator without enough operands)
// 	std::cout << "Result should be Error		Result is "; RPN("5 0 /");					// -> Error (division by zero)
// 	std::cout << "Result should be Error		Result is "; RPN("2 a +");					// -> Error (invalid token)
// 	std::cout << "Result should be Error		Result is "; RPN("5 1 2 + + +");			// -> Error (too many operators)
// 	std::cout << "Result should be Error		Result is "; RPN("+");						// -> Error
// 	std::cout << "Result should be Error		Result is "; RPN("3 +");					// -> Error
// 	std::cout << "Result should be Error		Result is "; RPN("4 0 /");					// -> division by zero
// 	std::cout << "Result should be Error		Result is "; RPN("2 a +");					// -> Error
// 	std::cout << "Result should be Error		Result is "; RPN("5 1 2 + + +");			// -> Error

// 	std::cout << YELLOW << "===== MONSTER TESTS =====" << DEFAULT << std::endl;
// 	std::cout << "Result should be 145		Result is "; RPN("9 8 + 7 * 6 5 * + 4 -");		// = 145
// 	std::cout << "Result should be 97		Result is "; RPN("2 3 + 4 * 5 6 + 7 * +");		// = 97
// 	std::cout << "Result should be -13		Result is "; RPN("8 2 / 3 + 4 5 * -");			// = -13
// 	std::cout << "Result should be 156		Result is "; RPN("5 6 + 7 8 + * 9 -");			// = 156
// 	std::cout << "Result should be 1155		Result is "; RPN("3 4 + 5 6 + * 7 8 + *");		// = 1155

// 	return (0);
// }
