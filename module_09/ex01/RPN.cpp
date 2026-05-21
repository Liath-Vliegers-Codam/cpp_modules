#include "RPN.hpp"

bool is_operator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return (true);
	else
		return (false);
}

bool check_token(std::string token)
{
	if (token.length() > 1)
		return (false);
	if (!isdigit(token[0]) && !is_operator(token[0]))
		return (false);
	return (true);
}

std::string parse_input(std::string input)
{
	std::stringstream sstream(input);
	std::string token;
	std::string result;
	
	while (sstream >> token)
	{
		if (!check_token(token))
			throw std::invalid_argument("Error");
		else
			result += token;
	}
	return (result);
}

void RPN(std::string raw_input)
{
	std::stack<int> rpn_stack;
	std::string parsed_input;

	try
	{
		parsed_input = parse_input(raw_input);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return ;
	}

	for (size_t i = 0; i < parsed_input.length(); i++)
	{
		if (isdigit(parsed_input[i]))
			rpn_stack.push(parsed_input[i] - '0');
		else if (is_operator(parsed_input[i]))
		{
			if (rpn_stack.size() < 2)
			{
				std::cerr << "Error" << std::endl;
				return;
			}

			int b = rpn_stack.top();
			rpn_stack.pop();
			int a = rpn_stack.top();
			rpn_stack.pop();

			if (parsed_input[i] == '/' && b == 0)
			{
				std::cerr << "Error" << std::endl;
				return;
			}

			int result = 0;

			switch (parsed_input[i])
			{
				case ('+'):
					result = a + b;
					break;
				case ('-'):
					result = a - b;
					break;
				case ('*'):
					result = a * b;
					break;
				case ('/'):
					result = a / b;
					break;
			}
			rpn_stack.push(result);
		}
	}
	if (rpn_stack.size() == 1)
		std::cout << rpn_stack.top() << std::endl;
	else
		std::cerr << "Error" << std::endl;
}
