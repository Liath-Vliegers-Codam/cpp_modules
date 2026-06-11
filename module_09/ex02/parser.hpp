#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>

static bool check_token(std::string token);

// Container::value_type must be convertible from int
template <typename Container>
Container parse_part(std::string input);

template <typename Container>
Container parse_input(char* argv[]);

#include "parser.tpp"