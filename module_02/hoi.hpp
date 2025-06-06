#pragma once

#include <iostream>
#include <string>

class hoi
{
   public:
	hoi();
	hoi(std::string);
	~hoi();

	// Copy constructor
	hoi(const hoi &obj);
	// Operator overload
	hoi &operator=(const hoi &obj);

   private:
	std::string name;
};
