
#include "MutantStack.hpp"
// SUBJECT MAIN

// int main(void)
// {
// 	MutantStack<int> mstack;
// 	mstack.push(5);
// 	mstack.push(17);
// 	std::cout << mstack.top() << std::endl;
// 	mstack.pop();
// 	std::cout << mstack.size() << std::endl;
// 	mstack.push(3);
// 	mstack.push(5);
// 	mstack.push(737);
// 	//[...]
// 	mstack.push(0);
// 	MutantStack<int>::iterator it = mstack.begin();
// 	MutantStack<int>::iterator ite = mstack.end();
// 	++it;
// 	--it;
// 	while (it != ite)
// 	{
// 		std::cout << *it << std::endl;
// 		++it;
// 	}
// 	std::stack<int> s(mstack);

// 	return (0);
// }


int main(void)
{
	std::cout << YELLOW << "Testing MutantStack and inheritanted functions" << DEFAULT << std::endl;

	MutantStack<int> mstack;
	std::cout << "Is the stack empty? " << (mstack.empty() ? "Yes" : "No") << std::endl;
	std::cout << "Pushing elements 5, 17, 3, 5, 737 and 12 onto the stack" << std::endl;
	mstack.push(5);
	mstack.push(17);
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(12);

	std::cout << GREEN << "mstack:\n" << mstack << DEFAULT;

	std::cout << "Is the stack empty? " << (mstack.empty() ? "Yes" : "No") << std::endl;
	std::cout << "Stack size: " << mstack.size() << std::endl;

	std::cout << "Top element: " << mstack.top() << std::endl;
	std::cout << "Popping top element" << std::endl;
	mstack.pop();
	std::cout << "Stack size: " << mstack.size() << std::endl;
	std::cout << "Top element: " << mstack.top() << std::endl;

	std::cout << GREEN << "mstack:\n" << mstack << DEFAULT;

	// Testing iterators
	std::cout << YELLOW << "Testing iterators" << DEFAULT << std::endl;

	std::cout << "Element at index 2: " << *(mstack.cbegin() + 2) << std::endl;
	std::cout << "Element at index 4: " << *(mstack.cbegin() + 4) << std::endl;

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end() - 1;
	MutantStack<int>::reverse_iterator rit = mstack.rbegin();
	MutantStack<int>::reverse_iterator rite = mstack.rend() - 1;
	MutantStack<int>::const_iterator cit = mstack.cbegin();
	MutantStack<int>::const_iterator cite = mstack.cend() - 1;
	MutantStack<int>::const_reverse_iterator crit = mstack.crbegin();
	MutantStack<int>::const_reverse_iterator crite = mstack.crend() - 1;

	std::cout << "iterator begin = " << *it << std::endl;
	std::cout << "iterator end = " << *ite << std::endl;
	std::cout << "reverse_iterator rbegin = " << *rit << std::endl;
	std::cout << "reverse_iterator rend = " << *rite << std::endl;
	std::cout << "const_iterator cbegin = " << *cit << std::endl;
	std::cout << "const_iterator cend = " << *cite << std::endl;
	std::cout << "const_reverse_iterator crbegin = " << *crit << std::endl;
	std::cout << "const_reverse_iterator crend = " << *crite << std::endl;

	std::cout << "Pushing element 42 onto the stack" << std::endl;
	mstack.push(42);
	std::cout << GREEN << "mstack:\n" << mstack << DEFAULT;
	std::cout << "iterator begin = " << *it << std::endl;
	std::cout << "iterator end = " << *ite << std::endl;
	std::cout << "reverse_iterator rbegin = " << *rit << std::endl;
	std::cout << "reverse_iterator rend = " << *rite << std::endl;

	std::cout << RED << "IMPORTANT NOTE:\nThe end iterator no longer points to the last element, so only create your iterators after your done pushing." << DEFAULT << std::endl;
	std::cout << RED << "After modifying the stack, all previously created iterators are invalid and can cause undefined behavior." << DEFAULT << std::endl;

	// Testing copy constructor
	std::cout << YELLOW << "Testing copy constructor" << DEFAULT << std::endl;
	MutantStack<int> copyStack(mstack);
	std::cout << GREEN << "copyStack:\n" << copyStack << DEFAULT;

	// Testing copy assignment operator
	std::cout << YELLOW << "Testing copy assignment operator" << DEFAULT << std::endl;
	MutantStack<int> assignedStack;
	assignedStack = mstack;
	std::cout << GREEN << "assignedStack:\n" << assignedStack << DEFAULT;

	// Testing with different data type (std::string)
	std::cout << YELLOW << "Testing with std::string as data type" << DEFAULT << std::endl;
	MutantStack<std::string> stringStack;
	stringStack.push("Hello");
	stringStack.push("My");
	stringStack.push("Lovely");
	stringStack.push("Evaluator");
	stringStack.push("!");
	std::cout << GREEN << "stringStack:\n" << stringStack << DEFAULT;

	// Testing with different container type (std::vector)
	std::cout << YELLOW << "Testing with std::vector as underlying container" << DEFAULT << std::endl;
	MutantStack<int, std::vector<int>> vectorStack;
	vectorStack.push(10);
	vectorStack.push(20);
	vectorStack.push(30);
	std::cout << GREEN << "vectorStack:\n" << vectorStack << DEFAULT;

	// Testing with std::list as underlying container
	std::cout << YELLOW << "Testing with std::list as underlying container" << DEFAULT << std::endl;
	MutantStack<int, std::list<int>> listStack;
	listStack.push(100);
	listStack.push(200);
	listStack.push(300);
	std::cout << GREEN << "listStack:\n" << listStack << DEFAULT;
	std::cout << RED << "NOTE:\nWhat happens here is that the std::stack will use the std::list or std::vector instead of a std::deque as its underlying container,\n  which is perfectly valid as long as the std::list supports the necessary operations\n  (like push_back, pop_back, back, etc.) that std::stack relies on." << DEFAULT << std::endl;
	std::cout << RED << "The MutantStack class should work seamlessly with std::list as the underlying container,\n  allowing us to use all the functionalities of MutantStack while benefiting from the properties of std::list\n  (like fast insertions and deletions)." << DEFAULT << std::endl;
	std::cout << RED << "The output will show the elements in listStack in the order they were added,\n  demonstrating that MutantStack can indeed work with different container types." << DEFAULT << std::endl;

	return (0);
}
