#pragma once

#include <iostream>
#include <string>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		~WrongCat();
		
		WrongCat(const WrongCat &other);
		WrongCat &operator=(const WrongCat &other);

		void makeSound() const;
		// const std::string &getType() const;
};