#include "WrongAnimal.hpp"

// Default constructor
WrongAnimal::WrongAnimal() : type("Unknown")
{
    std::cout << "WrongAnimal default constructor called" << std::endl;
}

// Parameterized constructor
WrongAnimal::WrongAnimal(const std::string& type) : type(type)
{
    std::cout << "WrongAnimal parameterized constructor called" << std::endl;
}

// Copy constructor
WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    *this = other;
}

// Copy assignment operator
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    std::cout << "WrongAnimal copy assignment operator called" << std::endl;
    if (this != &other)
        this->type = other.type;
    return *this;
}

// Destructor
WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}

// Setter
void WrongAnimal::setType(const std::string& type)
{
    this->type = type;
}

// Getter
const std::string& WrongAnimal::getType() const
{
    return (this->type);
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal Sound !" << std::endl;
}
