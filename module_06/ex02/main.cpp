
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <cstdlib>

/*
	Exercise 02			: Identify real type
	Turn-in directory	: ex02/
	Files to turn in	: Makefile, *.cpp, *.{h, hpp}
	Forbidden functions	: std::typeinfo

	Implement a Base class that has a public virtual destructor only. 
	Create three empty classes A, B, and C, that publicly inherit from Base.
	These four classes don’t have to be designed in the Orthodox Canonical Form.
	Implement the following functions:
	- Base * generate(void);
		It randomly instantiates A, B, or C and returns the instance as a Base pointer. 
		Feel free to use anything you like for the random choice implementation.
	- void identify(Base* p);
		It prints the actual type of the object pointed to by p: "A", "B", or "C".
	- void identify(Base& p);
		It prints the actual type of the object referenced by p: "A", "B", or "C". 
		Using a pointer inside this function is forbidden.
	Including the typeinfo header is forbidden.
	Write a program to test that everything works as expected.
*/

Base* generate(void)
{
	std::srand(time(0));
	
	int random_number = std::rand() % 3; // Generate a random number between 0 and 2

	Base* random_base;

	switch (random_number) 
	{
		case 0:
			random_base = new A;
			std::cout << "Base class A was created" << std::endl;	// TAKE OUT
			break ;
		case 1:
			random_base = new B;
			std::cout << "Base class B was created" << std::endl;	// TAKE OUT
			break ;
		case 2:
			random_base = new C;
			std::cout << "Base class C was created" << std::endl;	// TAKE OUT
			break ;
	}

	return (random_base);
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "Base class Type is A" << std::endl;

	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "Base class Type is B" << std::endl;

	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "Base class Type is C" << std::endl;

	else
		std::cout << "Base class Type is undetermined" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A a;
		a = dynamic_cast<A&>(p);
		std::cout << "Base class Type is A" << std::endl;
		return ;
	}
	catch(const std::exception& e){}

	try
	{
		B b;
		b = dynamic_cast<B&>(p);
		std::cout << "Base class Type is B" << std::endl;
		return ;
	}
	catch(const std::exception& e){}

	try
	{
		C c;
		c = dynamic_cast<C&>(p);
		std::cout << "Base class Type is C" << std::endl;
		return ;
	}
	catch(const std::exception& e){}
}

int main(void)
{
	Base* random_base_ptr = generate();

	identify(random_base_ptr);
	identify(*random_base_ptr);

	delete random_base_ptr;

	return (0);
}
