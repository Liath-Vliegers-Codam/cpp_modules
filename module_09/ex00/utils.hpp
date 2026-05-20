
#pragma once 

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <ctime>
#include <limits>
#include <iomanip>

#define DEFAULT	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define MAGENTA	"\033[35m"
#define CYAN	"\033[36m"
#define WHITE	"\033[37m"

bool is_int(std::string input);
bool is_double(std::string input);
std::string trim_whitespaces(const std::string &str);
