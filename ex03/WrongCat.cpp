#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    type = "WrongCat";
    std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const std::string& type) : WrongAnimal(type)
{
    std::cout << "WrongCat parameterized constructor called" << std::endl;
}


WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
    *this = other;
    std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat&    WrongCat::operator=(const WrongCat& other)
{
    if (this != &other)
        type = other.type;

    return (*this);
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "WrongCat Sound !" << std::endl;
}
