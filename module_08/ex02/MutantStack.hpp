#pragma once

#include <iostream>
#include <stack>
#include <deque>
#include <vector>
#include <list>


#define DEFAULT	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define MAGENTA	"\033[35m"
#define CYAN	"\033[36m"
#define WHITE	"\033[37m"


template <typename T, class Container = std::deque<T>>
class MutantStack: public std::stack<T, Container>
{
	private:
		// Add member variables here

	public:
		// Constructors
		MutantStack(void)
		{
			std::cout << BLUE << "MutantStack default constructor is called" << DEFAULT << std::endl;
		}

		MutantStack(const MutantStack& other)
		{
			*this = other;
			std::cout << BLUE << "MutantStack copy constructor is called" << DEFAULT << std::endl;
		}

		// Destructor
		~MutantStack(void)
		{
    		std::cout << BLUE << "MutantStack destructor is called" << DEFAULT << std::endl;
		}

		// Operators
		MutantStack &operator=(const MutantStack& other)
		{
			if (this != &other)
			{
				this->c = other.c;
				std::cout << BLUE << "MutantStack copy assignment is called" << DEFAULT << std::endl;
			}
			return (*this);
		}

		// Getters and Setters

		// Member functions
		typedef typename Container::iterator iterator;
		typedef typename Container::const_iterator const_iterator;
		typedef typename Container::reverse_iterator reverse_iterator;
		typedef typename Container::const_reverse_iterator const_reverse_iterator;

		iterator begin(void)
		{
			return (this->c.begin());
		}

		iterator end(void)
		{
			return (this->c.end());
		}

		const_iterator cbegin(void) const
		{
			return (this->c.cbegin());
		}

		const_iterator cend(void) const
		{
			return (this->c.cend());
		}

		reverse_iterator rbegin(void)
		{
			return (this->c.rbegin());
		}

		reverse_iterator rend(void)
		{
			return (this->c.rend());
		}

		const_reverse_iterator crbegin(void) const
		{
			return (this->c.crbegin());
		}

		const_reverse_iterator crend(void) const
		{
			return (this->c.crend());
		}
	};


template <typename T, class Container>
std::ostream& operator<<(std::ostream& output_stream, const MutantStack<T, Container>& src)
{
    typename MutantStack<T, Container>::const_reverse_iterator it = src.crbegin();
    while (it != src.crend())
    {
        output_stream << "  [";
        output_stream << *it;
        output_stream << "]" << std::endl;
        ++it;
    }
	output_stream << "-----------" << std::endl;
    return (output_stream);
}
