#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

#define DEFAULT "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"

void test_direct_vs_polymorphic()
{
	{
		std::cout << YELLOW << "\nDIRECT INSTANTIATION - Creating objects directly by their specific type:" << DEFAULT << std::endl;

		Animal		direct_animal;
		Dog			direct_dog;
		Cat			direct_cat;
		WrongAnimal	direct_wrong_animal;
		WrongCat	direct_wrong_cat;

		std::cout << GREEN << "\nDirect calls - compile-time binding:" << DEFAULT << std::endl;

		std::cout << "direct_animal is of type " << direct_animal.getType();
		direct_animal.makeSound();
		std::cout << "direct_dog is of type " << direct_dog.getType();
		direct_dog.makeSound();
		std::cout << "direct_cat is of type " << direct_cat.getType();
		direct_cat.makeSound();
		std::cout << "direct_wrong_animal is of type " << direct_wrong_animal.getType();
		direct_wrong_animal.makeSound();
		std::cout << "direct_wrong_cat is of type " << direct_wrong_cat.getType();
		direct_wrong_cat.makeSound();
		std::cout << std::endl;
	}

	{
		std::cout << YELLOW << "/nPOLYMORPHIC INSTANTIATION - Creating objects through base class pointers:" << DEFAULT << std::endl;

		const Animal* poly_animal = new Animal();
		const Animal* poly_dog = new Dog();
		const Animal* poly_cat = new Cat();
		const WrongAnimal* poly_wrong_animal = new WrongAnimal();
		const WrongAnimal* poly_wrong_cat = new WrongCat();

		std::cout << GREEN << "\nPolymorphic calls - runtime binding:" << DEFAULT << std::endl;

		std::cout << "poly_animal is of type " << poly_animal->getType();
		poly_animal->makeSound();
		std::cout << "poly_dog is of type " << poly_dog->getType();
		poly_dog->makeSound();
		std::cout << "poly_cat is of type " << poly_cat->getType();
		poly_cat->makeSound();
		std::cout << "poly_wrong_animal is of type " << poly_wrong_animal->getType();
		poly_wrong_animal->makeSound();
		std::cout << "poly_wrong_cat is of type " <<  poly_wrong_cat->getType();
		poly_wrong_cat->makeSound();
		std::cout << std::endl;

		// Key differences:
		// 1. Animal classes: Same Animal* pointer type, different behaviors (virtual functions)
		// 2. WrongAnimal classes: Same WrongAnimal* pointer type, SAME behavior (no virtual)
		// Notice: poly_wrong_cat calls WrongAnimal::makeSound(), not WrongCat::makeSound()!

		delete poly_animal;
		delete poly_dog;
		delete poly_cat;
		delete poly_wrong_animal;
		delete poly_wrong_cat;
	}
}

void test_array_of_animals()
{
	std::cout << YELLOW << "\nARRAY TEST - creating 5 dogs and 5 cats" << DEFAULT << std::endl;
    
    const int array_size = 10;
    Animal* animals[array_size];
    
    for (int i = 0; i < array_size; i++)
    {
        if (i < array_size / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }
    
    std::cout << GREEN << "Testing polymorphic behavior:" << DEFAULT << std::endl;
    for (int i = 0; i < array_size; i++)
    {
        std::cout << animals[i]->getType() << ": ";
        animals[i]->makeSound();
    }
	std::cout << std::endl;
    for (int i = 0; i < array_size; i++)
    {
        delete animals[i];
    }
}

void test_deep_copy()
{
   	std::cout << YELLOW << "\nDEEP COPY TEST - copying ideas of the animals" << DEFAULT << std::endl;

    Dog original_dog;
    Dog copied_dog(original_dog);
    Dog assigned_dog;
    assigned_dog = original_dog;

    std::cout << "\nOriginal dog address: " << &original_dog << std::endl;
    std::cout << "Copied dog address: " << &copied_dog << std::endl;
    std::cout << "Assigned dog address: " << &assigned_dog << std::endl;

    if (&original_dog != &copied_dog && &original_dog != &assigned_dog)
        std::cout << GREEN << "Deep copy successful - different addresses\n" << DEFAULT << std::endl;
}

int main()
{
    test_direct_vs_polymorphic();
    test_array_of_animals();
    test_deep_copy();
	return (0);
}
