#include "Span.hpp"


// SUBJECT MAIN
int main(void)
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return 0;
}


// static void printSpanSpans(Span &span)
// {
// 	try
// 	{
// 		std::cout << "shortest span: " << span.shortestSpan() << std::endl;
// 		std::cout << "longest span:  " << span.longestSpan() << std::endl;
// 	}
// 	catch (const std::exception &e)
// 	{
// 		std::cerr << RED << e.what() << DEFAULT << std::endl;
// 	}
// }

// int main(void)
// {
// 	std::cout << YELLOW << "\nTEST 1: Adding numbers to a Span object and finding the shortest and longest spans" << DEFAULT << std::endl;
// 	Span span1 = Span(5);
// 	try
// 	{
// 		span1.addNumber(6);
// 		span1.addNumber(3);
// 		span1.addNumber(17);
// 		span1.addNumber(9);
// 		span1.addNumber(11);
// 		span1.addNumber(8); // should throw
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << RED << e.what() << DEFAULT << std::endl;
// 	}
// 	std::cout << MAGENTA << "Span 1: " << span1 << DEFAULT << std::endl;
// 	printSpanSpans(span1);
	
// 	std::cout << YELLOW << "\nTEST 2: Adding a range of numbers to a Span objects" << DEFAULT << std::endl;
	
// 	std::vector<int> veccy;

// 	veccy.push_back(1);
// 	veccy.push_back(2);
// 	veccy.push_back(235423);
// 	veccy.push_back(234);
// 	veccy.push_back(5);
// 	veccy.push_back(245);
// 	veccy.push_back(5554);
// 	veccy.push_back(85667);
// 	veccy.push_back(4564);
// 	veccy.push_back(8);

// 	try
// 	{
// 		std::cout << GREEN << "Adding a range of numbers to Span 1 (full, with size 5)" << DEFAULT << std::endl;
// 		span1.addRange(std::next(veccy.begin(), 3), veccy.end()); // should throw
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << RED << e.what() << DEFAULT << std::endl;
// 	}
	
// 	Span span2 = Span(50);
// 	try
// 	{
// 		std::cout << GREEN << "Adding a range of numbers to Span 2 (empty, with size 50)" << DEFAULT << std::endl;
// 		span2.addRange(std::next(veccy.begin(), 3), veccy.end());
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << RED << e.what() << DEFAULT << std::endl;
// 	}
// 	std::cout << MAGENTA << "Span 2: " << span2 << DEFAULT << std::endl;
// 	printSpanSpans(span2);


// 	std::cout << YELLOW << "\nTEST 3: Finding the shortest and longest spans of a Span object with too few elements" << DEFAULT << std::endl;
	
// 	Span span3 = Span(5);
// 	span3.addNumber(42);
// 	try
// 	{
// 		span3.shortestSpan(); // should throw
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << RED << e.what() << DEFAULT << std::endl;
// 	}
// 	try
// 	{
// 		span3.longestSpan(); // should throw
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << RED << e.what() << DEFAULT << std::endl;
// 	}

// 	std::cout << YELLOW << "\nTEST 4: Adding a range of numbers to a Span object with an end iterator smaller than the start iterator" << DEFAULT << std::endl;
// 	Span span4 = Span(5);
// 	try
// 	{		
// 		std::cout << GREEN << "Adding a range of numbers to Span 4 with an end iterator smaller than the start iterator" << DEFAULT << std::endl;
// 		span4.addRange(std::next(veccy.begin(), 3), std::next(veccy.begin(), 2)); // should throw
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << RED << e.what() << DEFAULT << std::endl;
// 	}	

// 	std::cout << YELLOW << "\nTEST 5: Adding a range of numbers to a Span object that exceeds its maximum size" << DEFAULT << std::endl;
// 	Span span5 = Span(5);
// 	try
// 	{		
// 		std::cout << GREEN << "Adding a range of numbers to Span 5 that exceeds its maximum size" << DEFAULT << std::endl;
// 		span5.addRange(std::next(veccy.begin(), 3), veccy.end()); // should throw
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << RED << e.what() << DEFAULT << std::endl;
// 	}

// 	std::cout << YELLOW << "\nTEST 6: Testing the Span class with a large number of elements (10,000)" << DEFAULT << std::endl;
// 	Span span6 = Span(20000);
// 	std::vector<int> big_vec;
// 	for (int i = 0; i < 20000; ++i)
// 	{
// 		big_vec.push_back(rand() % 100000); // random numbers between 0 and 99,999
// 	}
// 	try
// 	{		
// 		std::cout << GREEN << "Adding a range of 20,000 random numbers to Span 6" << DEFAULT << std::endl;
// 		span6.addRange(big_vec.begin(), big_vec.end());
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << RED << e.what() << DEFAULT << std::endl;
// 	}
// 	std::cout << MAGENTA << "Span 6: " << span6 << DEFAULT << std::endl;
// 	printSpanSpans(span6);

// 	return (0);
// }

