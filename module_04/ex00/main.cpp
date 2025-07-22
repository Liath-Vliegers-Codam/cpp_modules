
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#define DEFAULT     		"\033[0m"   // Reset to default colour
#define RED         		"\033[31m"  // Red text
#define GREEN       		"\033[32m"  // Green text
#define YELLOW      		"\033[33m"  // Yellow text
#define BLUE        		"\033[34m"  // Blue text
#define MAGENTA     		"\033[35m"  // Magenta text
#define CYAN        		"\033[36m"  // Cyan text

// Running this code should print the specific sounds of the Dog and Cat classes, not the Animal’s.


// SUBJECT main

// int main()
// {
// 	const Animal* meta = new Animal();
// 	const Animal* i = new Cat();
// 	const Animal* j = new Dog();

// 	std::cout << i->getType() << " " << std::endl;
// 	std::cout << j->getType() << " " << std::endl;

// 	i->makeSound(); //will output the cat sound!
// 	j->makeSound(); //will output the dog sound!
// 	meta->makeSound(); //will output an animal sound!

// 	return 0;
// }


// To ensure you understood how it works, implement a WrongCat class that inherits
// from a WrongAnimal class. If you replace the Animal and the Cat by the wrong ones
// in the code above, the WrongCat should output the WrongAnimal sound.
// Implement and turn in more tests than the ones given above.


// polymorphism is a core concept in object-oriented programming that allows objects to be treated as instances of their parent class, while still invoking the methods of their actual derived class. In this example, we demonstrate polymorphism with the Animal, Dog, and Cat classes, as well as the WrongAnimal and WrongCat classes.
// GOOD main

// int main()
// {
// 	const Animal* default_animal = new Animal();
// 	const Animal* cat = new Cat();
// 	const Animal* dog = new Dog();
// 	const WrongAnimal* wrong_animal = new WrongAnimal();
// 	const WrongAnimal* not_a_cat = new WrongCat();

// 	std::cout << "Animal type of default_animal = " << default_animal->getType() << std::endl;
// 	std::cout << "Animal type of cat = " << cat->getType() << std::endl;
// 	std::cout << "Animal type of dog = " << dog->getType() << std::endl;
// 	std::cout << "Animal type of wrong_animal = " << wrong_animal->getType() << std::endl;
// 	std::cout << "Animal type of not_a_cat = " << not_a_cat->getType() << std::endl;

// 	std::cout << "default_animal: ";
// 	default_animal->makeSound(); // will output an animal sound!
// 	std::cout << "cat: ";
// 	cat->makeSound(); // will output the cat sound!
// 	std::cout << "dog: ";
// 	dog->makeSound(); // will output the dog sound!
// 	std::cout << "wrong_animal: ";
// 	wrong_animal->makeSound(); // will output the wrong animal sound!
// 	std::cout << "not_a_cat: ";
// 	not_a_cat->makeSound(); // will output the wrong cat sound!

// 	delete default_animal;
// 	delete cat;
// 	delete dog;
// 	delete wrong_animal;
// 	delete not_a_cat;

// 	return (0);
// }


// this is not polymorphism, but it is a test of the classes and their methods. (not-a-cat will make the not-a-cat sound)
// NOT GOOD main

int main()
{
	const Animal default_animal;
	const Cat cat;
	const Dog dog;
	const WrongAnimal wrong_animal;
	const WrongCat not_a_cat;

	std::cout << YELLOW;
	std::cout << "Animal type of default_animal	= " << default_animal.getType() << std::endl;
	std::cout << "Animal type of cat		= " << cat.getType() << std::endl;
	std::cout << "Animal type of dog		= " << dog.getType() << std::endl;
	std::cout << "Animal type of wrong_animal	= " << wrong_animal.getType() << std::endl;
	std::cout << "Animal type of not_a_cat	= " << not_a_cat.getType() << std::endl;

	std::cout << GREEN;
	std::cout << "default_animal:	";
	default_animal.makeSound(); // will output an animal sound!
	std::cout << "cat:		";
	cat.makeSound(); // will output the cat sound!
	std::cout << "dog:		";
	dog.makeSound(); // will output the dog sound!
	std::cout << "wrong_animal:	";
	wrong_animal.makeSound(); // will output the wrong animal sound!
	std::cout << "not_a_cat:	";
	not_a_cat.makeSound(); // will output the wrong cat sound!
	std::cout << DEFAULT;

	return (0);
}
