#pragma once

#include <iostream>
#include <string>
	
	
class AAnimal 
{
	protected:
		AAnimal();
		AAnimal(const AAnimal &other);
		std::string _type;
	public:
		virtual ~AAnimal();
		
		AAnimal &operator=(const AAnimal &other);

		virtual void makeSound() const = 0;  // Pure virtual function makes class abstract
		const std::string &getType() const;
};
