#include "Ice.hpp"
#include "ICharacter.hpp"

// Default constructor
Ice::Ice() : AMateria("ice")
{
    std::cout << "Ice default constructor called" << std::endl;
}

// Parameterized constructor
Ice::Ice(const std::string& type) : AMateria(type)
{
    std::cout << "Ice parameterized constructor called" << std::endl;
}

// Copy constructor
Ice::Ice(const Ice& other) : AMateria(other)
{
    std::cout << "Ice copy constructor called" << std::endl;
    *this = other;
}

// Copy assignment operator
Ice& Ice::operator=(const Ice& other)
{
    if (this != &other)
        this->type = other.type;
    return (*this);
}

// Destructor
Ice::~Ice()
{
    std::cout << "Ice destructor called" << std::endl;
}

AMateria* Ice::clone() const
{
    return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
    std::cout << "Ice: \"* shoots an ice bolt at" << target.getName() << "*\"" << std::endl;
}
