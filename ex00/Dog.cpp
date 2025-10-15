#include "Dog.hpp"

Dog::Dog() : Animal()
{
    type = "Dog";
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const std::string& type) : Animal(type)
{
    std::cout << "Dog parameterized constructor called" << std::endl;
}


Dog::Dog(const Dog& other) : Animal(other)
{
    *this = other;
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog&    Dog::operator=(const Dog& other)
{
    if (this != &other)
        type = other.type;

    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Dog Sound !" << std::endl;
}
