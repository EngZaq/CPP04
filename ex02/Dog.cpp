#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog() {
    this->_brain = new Brain();
    this->type = "Dog";
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other){
    this->_brain = new Brain(*other.getBrain()); 
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog assignment operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        *(this->_brain) = *(other.getBrain());
    }
    return *this;
}

Dog::~Dog() {
    delete this->_brain;
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "3au, 3au!" << std::endl;
}

Brain* Dog::getBrain() const {
    return this->_brain;
}
