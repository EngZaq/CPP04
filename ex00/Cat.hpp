#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include "Animal.hpp"

class Cat : public Animal 
{


    public:
        Cat();
        Cat(const Cat& other);
        Cat& operator=(const Cat& other);
        ~Cat() override;

        void makeSound() const override;
};

#endif