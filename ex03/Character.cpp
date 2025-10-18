#include "Character.hpp"

Character::Character() : name("Unknown")
{
    for (int i = 0; i < 4; i++)
        this->inventory[i] = NULL;
}

Character::Character(std::string const & name) : name(name)
{
    for (int i = 0; i < 4; i++)
        this->inventory[i] = NULL;
}

Character::Character(const Character& other) { *this = other; }

Character& Character::operator=(const Character& other)
{
    if (this != &other)
    {
        this->name = other.name;

        for(int i = 0; i < 4; i++)
        {
            delete this->inventory[i];

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

    for (int i = 0; i < unequippedCount; i++)
        delete unequipped[i];

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

void    Character::setInvontory(int index, AMateria* materia)
{
    if (index >= 0 && index < 4)
    {
        if (this->inventory[index])
            delete this->inventory[index];
    
        this->inventory[index] = materia;
    }
}

// Put the given Materia (m) into the first empty slot (from 0 → 3).
void Character::equip(AMateria* m)
{
    if (!m)
        return ;

    for(int i = 0; i < 4; i++)
    {
        if (!this->inventory[i])
        {
            this->inventory[i] = m;
            return;
        }
    }
}

// Remove the Materia from the given slot without deleting it.
void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4 && this->inventory[idx])
    {
        if (unequippedCount < 4)
            unequipped[unequippedCount++] = this->inventory[idx];

            this->inventory[idx] = NULL;
    }
}

// Use the Materia in slot idx on the target character
void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < 4 && this->inventory[idx])
        this->inventory[idx]->use(target);
}
