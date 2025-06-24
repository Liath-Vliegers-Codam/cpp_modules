
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

// Running this code should print the specific sounds of the Dog and Cat classes, not the Animal’s.

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


int main()
{
	// const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	const Animal* copy = new Cat(*((Cat *)j));

	delete j;
	delete i;
	delete copy;
	system("leaks dog");

	Animal *Animals[100];

	for (int i = 0; i < 50; i++)
		Animals[i] = new Dog();
	for (int i = 50; i < 100; i++)
		Animals[i] = new Cat();
	for (int i = 0; i < 100; i++)
		delete Animals[i];
	system("leaks dog");

	const WrongAnimal* wrong_meta = new WrongAnimal();
	const WrongAnimal* wrong_i = new WrongCat();

	std::cout << wrong_i->getType() << " " << std::endl;
	wrong_i->makeSound(); //will output the Animal sound!
	wrong_meta->makeSound(); //will output the Animal sound!
	return (0);
}

