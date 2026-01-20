#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	std::cout << "--- Array of Animals Test ---" << std::endl;
	
	const int arraySize = 10;
	Animal* animals[arraySize];
	
	for (int i = 0; i < arraySize / 2; i++)
		animals[i] = new Dog();
	
	for (int i = arraySize / 2; i < arraySize; i++)
		animals[i] = new Cat();
	
	// Test the animals
	std::cout << "\n--- Making sounds ---" << std::endl;
	for (int i = 0; i < arraySize; i++)
	{
		std::cout << animals[i]->getType() << ": ";
		animals[i]->makeSound();
	}
	
	// Delete all animals
	std::cout << "\n--- Deleting animals ---" << std::endl;
	for (int i = 0; i < arraySize; i++)
		delete animals[i];

	// Test deep copy for Dog
	std::cout << "\n--- Testing deep copy for Dog ---" << std::endl;
	Dog dog1;
	Dog dog2 = dog1;
	std::cout << "dog1 brain address: " << dog1.getBrain() << std::endl;
	std::cout << "dog2 brain address: " << dog2.getBrain() << std::endl;
	if (dog1.getBrain() != dog2.getBrain())
		std::cout << "✓ Dog copy is a DEEP COPY (different Brain instances)" << std::endl;
	else
		std::cout << "✗ Dog copy is a SHALLOW COPY (same Brain instance)" << std::endl;

	// Test deep copy for Cat
	std::cout << "\n--- Testing deep copy for Cat ---" << std::endl;
	Cat cat1;
	Cat cat2 = cat1;
	std::cout << "cat1 brain address: " << cat1.getBrain() << std::endl;
	std::cout << "cat2 brain address: " << cat2.getBrain() << std::endl;
	if (cat1.getBrain() != cat2.getBrain())
		std::cout << "✓ Cat copy is a DEEP COPY (different Brain instances)" << std::endl;
	else
		std::cout << "✗ Cat copy is a SHALLOW COPY (same Brain instance)" << std::endl;

	return 0;
}