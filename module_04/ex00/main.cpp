
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#define BLACK   "\033[30m"
#define RED     "\033[31m" 
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define DEFAULT "\033[0m"


// Polymorphism allows objects of different types to be treated as objects of a common base type, 
// while still maintaining their specific behavior.

int main()
{
	const Animal* animal_ptr = new Animal();
	const Animal* dog_ptr = new Dog(); // [Animal* pointer] → [Dog object in memory]
	const Animal* cat_ptr = new Cat();

	const WrongAnimal* wrong_animal_ptr = new WrongAnimal();
	const WrongAnimal* wrong_cat_ptr = new WrongCat();
	const WrongCat wrong_cat;

	// Both dog_ptr and cat_ptr are of type Animal*
	// At runtime, C++ determines the actual object type (Dog or Cat)
	// The correct makeSound() method is called based on the actual object, not the pointer type
	// This works because Animal::makeSound() is declared as virtual

	std::cout << YELLOW;
	std::cout << "animal_ptr is of type " << animal_ptr->getType() << " and makes this sound:		";
	animal_ptr->makeSound(); //will output the animal sound!

	std::cout << "dog_ptr is of type " << dog_ptr->getType() << " and makes this sound:			";
	dog_ptr->makeSound(); //will output the dog sound!

	std::cout << "cat_ptr is of type " << cat_ptr->getType() << " and makes this sound:			";
	cat_ptr->makeSound(); //will output the cat sound!

	std::cout << "wrong_animal_ptr is of type " << wrong_animal_ptr->getType() << " and makes this sound:	";
	wrong_animal_ptr->makeSound(); //will output the Animal sound!
	
	std::cout << "wrong_cat is of type " << wrong_cat_ptr->getType() << " and makes this sound:		";
	wrong_cat_ptr->makeSound(); //will output the wrong Animal sound!
	
	std::cout << "wrong_cat is of type " << wrong_cat.getType() << " and makes this sound:		";
	wrong_cat.makeSound(); //will output the wrong Cat sound!
	std::cout << DEFAULT;

	delete animal_ptr;
	delete dog_ptr;
	delete cat_ptr;
	delete wrong_animal_ptr;
	delete wrong_cat_ptr;

	return (0);
}

// WrongCat makes a WrongAnimal sound because it inherits from WrongAnimal.
// The WrongAnimal class is a base class that does not have a virtual function for makeSound
// so the WrongCat class does not override it properly. 

