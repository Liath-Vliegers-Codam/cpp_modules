#include "hoi.hpp"

// Constructors and Destructor
hoi::hoi()
{
	std::cout << "hoi default Constructor called" << std::endl;
	this->name = "hoi";
}

hoi::hoi(std::string n)
{
	std::cout << "hoi Constructor called" << std::endl;
	this->name = n;
}

hoi::~hoi() { std::cout << "hoi Destructor called" << std::endl; }

// Canonical form
hoi &hoi::operator=(const hoi &obj)
{
	// copy depending on vars;
	return *this;
}

hoi::hoi(const hoi &obj) { *this = obj; }
