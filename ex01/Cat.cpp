#include "Cat.hpp"
#include "Dog.hpp"

Cat::Cat() : Animal()
{
    type = "Cat";
    brain = new Brain();

    std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const std::string& type) : Animal(type)
{
    brain = new Brain();
    std::cout << "Dog parameterized constructor called" << std::endl;
}


Cat::Cat(const Cat& other) : Animal(other)
{
    brain = new Brain(*other.brain);
    *this = other;
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat&    Cat::operator=(const Cat& other)
{
    if (this != &other)
    {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }

    return (*this);
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Cat Sound !" << std::endl;
}
