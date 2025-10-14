#include "Animal.hpp"

// Default constructor
Animal::Animal() : type("Unknown")
{
    std::cout << "Animal default constructor called" << std::endl;
}

// Parameterized constructor
Animal::Animal(const std::string& type) : type(type)
{
    std::cout << "Animal parameterized constructor called" << std::endl;
}

// Copy constructor
Animal::Animal(const Animal& other)
{
    std::cout << "Animal copy constructor called" << std::endl;
    *this = other;
}

// Copy assignment operator
Animal& Animal::operator=(const Animal& other)
{
    std::cout << "Animal copy assignment operator called" << std::endl;
    if (this != &other)
        this->type = other.type;
    return *this;
}

// Destructor
Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

// Setter
void Animal::setType(const std::string& type)
{
    this->type = type;
}

// Getter
const std::string& Animal::getType() const {
    return (this->type);
}
