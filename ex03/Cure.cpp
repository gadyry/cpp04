#include "Cure.hpp"

// Default constructor
Cure::Cure() : AMateria("cure")
{
    std::cout << "Cure default constructor called" << std::endl;
}

// Copy constructor
Cure::Cure(const Cure& other) : AMateria(other)
{
    std::cout << "Cure copy constructor called" << std::endl;
    *this = other;
}

// Copy assignment operator
Cure& Cure::operator=(const Cure& other)
{
    if (this != &other)
        this->type = other.type;
    return (*this);
}

// Destructor
Cure::~Cure()
{
    std::cout << "Cure destructor called" << std::endl;
}

// clone() method
AMateria* Cure::clone() const
{
    return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
