
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <cstdlib>

Base* generate(void)
{
	std::srand(time(0));
	
	int random_number = std::rand() % 3;

	Base* random_base;

	switch (random_number) 
	{
		case 0:
			random_base = new A;
			break ;
		case 1:
			random_base = new B;
			break ;
		case 2:
			random_base = new C;
			break ;
	}
	return (random_base);
}

void identify(Base* p)
{
	std::cout << BLUE << "identifying base class type of the object pointed to by p" << DEFAULT << std::endl;

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
	std::cout << BLUE << "identifying base class type of the object referenced to by p" << DEFAULT << std::endl;

	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "Base class Type is A" << std::endl;
		return ;
	}
	catch(const std::exception& e){}

	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "Base class Type is B" << std::endl;
		return ;
	}
	catch(const std::exception& e){}

	try
	{
		(void)dynamic_cast<C&>(p);
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
