/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: livliege <livliege@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/27 18:35:12 by livliege      #+#    #+#                 */
/*   Updated: 2025/03/28 17:53:39 by livliege      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./Zombie.hpp"

// #include <cstdlib>
#include <iostream>
// #include <iomanip> 
// #include <string>

class Zombie
{
	private:
		std::string name;

	public:
		void announce(void)
		{
			std::cout << this->name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
		}
		Zombie(std::string name) // constructor
		{
			this->name = name;
			std::cout << "oh no! a person was infected.. a new zombie was born.." << std::endl;
			std::cout << "his name is: " << this->name << std::endl;
		}
		~Zombie(void) // deconstructor
		{
			std::cout << "the zombie named " << this->name << "was destroyed" << std::endl;
		}
};

void randomChump(std::string name)
{
	// It creates a zombie, name it, and the zombie announces itself.
}

Zombie* newZombie(std::string name)
{
	// It creates a zombie, name it, and return it so you can use it outside of the function scope.
}

int main(int argc, char **argv)
{
	
}

/*
To implement this Zombie class in C++, we can break down the task step-by-step. Here's the structure and implementation based on your description.
Class Requirements:

    Private Attribute: The class will have a private string name.

    Member Function - announce(): This will print a zombie's name followed by the message "BraiiiiiiinnnzzzZ...".

    Helper Functions:

        Zombie* newZombie(std::string name): Creates a zombie, names it, and returns it (using dynamic memory allocation on the heap).

        void randomChump(std::string name): Creates a zombie, names it, and has it announce itself (allocated on the stack).

    Destructor: When a zombie is destroyed, the destructor should print a debug message with the zombie's name.

Zombie Class Implementation:

#include <iostream>
#include <string>

// Zombie class definition
class Zombie {
private:
    std::string name; // Zombie's name

public:
    // Constructor
    Zombie(std::string name) : name(name) {}

    // Destructor
    ~Zombie() {
        std::cout << "Zombie " << name << " is destroyed!" << std::endl;
    }

    // Announce the Zombie
    void announce() const {
        std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
    }
};

// Function that creates a new Zombie and returns it
Zombie* newZombie(std::string name) {
    return new Zombie(name); // Zombie created on the heap
}

// Function that creates a Zombie, makes it announce, and then destroys it
void randomChump(std::string name) {
    Zombie tempZombie(name);  // Zombie created on the stack
    tempZombie.announce();    // Zombie announces itself
}

int main() {
    // Using newZombie, which creates a Zombie on the heap
    Zombie* zombieHeap = newZombie("Foo");
    zombieHeap->announce();
    delete zombieHeap;  // Free the zombie created on the heap

    // Using randomChump, which creates a Zombie on the stack
    randomChump("Bar");

    return 0;
}

Explanation:

    Zombie Class:

        The Zombie class has a private attribute name (a string).

        The constructor initializes the name when a zombie is created.

        The announce() function prints the "BraiiiiiiinnnzzzZ..." message using the zombie's name.

        The destructor prints a message when a zombie is destroyed (useful for debugging).

    Functions:

        newZombie(std::string name) dynamically allocates a Zombie on the heap, sets its name, and returns a pointer to the zombie.

        randomChump(std::string name) creates a zombie on the stack, makes it announce itself, and then it is automatically destroyed when it goes out of scope.

    Memory Allocation:

        In newZombie, we allocate memory for the Zombie on the heap using new, which requires manual deallocation (delete).

        In randomChump, the zombie is allocated on the stack, so it will be automatically destroyed when it goes out of scope (no need to explicitly delete it).

Output Example:

Foo: BraiiiiiiinnnzzzZ...
Zombie Foo is destroyed!
Bar: BraiiiiiiinnnzzzZ...
Zombie Bar is destroyed!

Key Points:

    The heap allocation (newZombie) is useful when you want the zombie to persist beyond the scope in which it was created (you need to manually delete it).

    The stack allocation (randomChump) is suitable for temporary use since it gets destroyed when it goes out of scope, without requiring manual memory management.
*/
