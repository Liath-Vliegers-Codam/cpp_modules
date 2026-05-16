#include "Span.hpp"


// // SUBJECT MAIN
// int main(void)
// {
// 	Span sp = Span(5);
// 	sp.addNumber(6);
// 	sp.addNumber(3);
// 	sp.addNumber(17);
// 	sp.addNumber(9);
// 	sp.addNumber(11);
// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << sp.longestSpan() << std::endl;
// 	return 0;
// }


int main(void)
{
	Span span1 = Span(5);
	try
	{
		span1.addNumber(6);
		span1.addNumber(3);
		span1.addNumber(17);
		span1.addNumber(9);
		span1.addNumber(11);
		span1.addNumber(8); // should throw
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << DEFAULT << std::endl;
	}
	std::cout << span1;
	
	try
	{
		std::cout << "shortest span = " << span1.shortestSpan() << std::endl;
		std::cout << "longest span = " << span1.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << DEFAULT << std::endl;
	}
	
	std::vector<int> veccy;

	veccy.push_back(1);
	veccy.push_back(2);
	veccy.push_back(235423);
	veccy.push_back(234);
	veccy.push_back(5);
	veccy.push_back(245);
	veccy.push_back(5554);
	veccy.push_back(85667);
	veccy.push_back(4564);
	veccy.push_back(8);

	try
	{
		span1.addRange(std::next(veccy.begin(), 3), veccy.end());
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << DEFAULT << std::endl;
	}
	
	Span span2 = Span(50);
	try
	{
		span2.addRange(std::prev(veccy.end()), veccy.begin() + 3);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << DEFAULT << std::endl;
	}
	std::cout << span2;

	Span span3 = Span(50);
	try
	{
		span3.addRange(std::next(veccy.begin(), 3), veccy.end());
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << DEFAULT << std::endl;
	}
	std::cout << span3;

	return (0);
}
