
#include <iostream>
#include <cstring>
#include <string>

int main(int argc, char **argv)
{

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	}
	else
	{
		std::string str;
		int i = 1;

		while (argv[i] != NULL)
		{
			str = argv[i];
			for (size_t j = 0; j < str.length(); j++)
			{
				char ch = std::toupper(str[j]);
				std::cout << ch;
			}
			i++;
		}
		std::cout << "\n";
	}
	return (0);
}
