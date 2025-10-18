#include "AMateria.hpp"

AMateria::AMateria() : type("Unknown") {}

AMateria::AMateria(const std::string& type) : type(type) {}

AMateria::AMateria(const AMateria& other) { *this = other;}

AMateria& AMateria::operator=(const AMateria& other)
{
    if (this != &other)
        this->type  = other.type;
    return (*this);
}

AMateria::~AMateria()
{
    std::cout << "" << std::endl;
}

// SETTERS && GETTERS :

const std::string&    AMateria::getType() const
{
    return (this->type);
}

void    AMateria::setType(const std::string& type)
{
    this->type = type;
}

void AMateria::use(ICharacter& target)
{
    std::cout << "* uses " << type << " on " << target.getName() << " *" << std::endl;
}
