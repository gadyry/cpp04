#include "Character.hpp"

Character::Character() : name("Unknown")  {}

Character::Character(std::string const & name) : name(name)  {}

Character::Character(const Character& other) { *this = other; }

Character& Character::operator=(const Character& other)
{
    if (this != &other)
    {
        this->name = other.name;
        
        for(int i = 0; i < 4; i++)
        {
            delete this->inventory[i];
            this->inventory[i] = NULL;
        }

        for(int i = 0; i < 4; i++)
        {
            if (other.inventory[i])
                this->inventory[i] = other.inventory[i]->clone();
            else
                this->inventory[i] = NULL;
        }
    }
    return (*this);
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
    {
        if (inventory[i])
            delete inventory[i];
    }
    std::cout << "Character destructor called" << std::endl;
}

std::string const & Character::getName() const
{
    return (this->name);
}

void    Character::setName(std::string const & name)
{
    this->name = name;
}

AMateria* Character::getInvontory(int index) const
{
    if (index >= 0 && index < 4)
        return (this->inventory[index]);
    return (NULL);
}

void    setInvontory(int index, AMateria& inventory)
{
    // TODO :
    
}