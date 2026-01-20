#include "Animal.hpp"
#include "Dog.hpp"
#include <iostream>

int main() {
    // This should NOT compile if uncommented:
    // const Animal* a = new Animal();
    
    // This should compile:
    const Animal* d = new Dog();
    d->makeSound();
    delete d;
    return 0;
}
