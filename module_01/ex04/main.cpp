
#include <fstream>
#include <iostream>

std::string replace_s1_with_s2(std::string line, std::string s1, std::string s2)
{
	size_t position;

	position = line.find(s1, 0);
	while (position != std::string::npos)
	{
		std::cout << "we found \"" << s1 << "\", and we will replace it with \"" << s2 << "\"" << std::endl;

		line.erase(position, s1.length());
		line.insert(position, s2);

		position = line.find(s1, position + s1.length());
	}
	return (line);
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "This program takes three parameters in the following order: a filename and two strings, s1 and s2." << std::endl;
		return (1);
	}

	std::string og_file_name = argv[1];
	std::string rep_file_name = og_file_name + ".replace";
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	std::string line;

	std::ifstream original_file(og_file_name.c_str());
	std::ofstream replace_file(rep_file_name.c_str());

	if (original_file.is_open() && replace_file.is_open())
	{
		while (std::getline(original_file, line))
		{
			line = replace_s1_with_s2(line, s1, s2);
			replace_file << line;
		}
		original_file.close();
		replace_file.close();
	}
	else
	{
		std::cout << "Error: could not open file" << std::endl;
	}
	return (0);
}
