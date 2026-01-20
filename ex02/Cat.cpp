#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat() {
    this->_brain = new Brain();
    this->type = "Cat";
    std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other){
    this->_brain = new Brain();
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat assignment operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
    }
    return *this;
}

Cat::~Cat() {
    delete this->_brain;
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "meaow!" << std::endl;
}

Brain* Cat::getBrain() const {
    return this->_brain;
}
