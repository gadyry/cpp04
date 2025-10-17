#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{
private:
    std::string name;
    AMateria* inventory[4];
    AMateria* unequipped[4];
    int unequippedCount;
public:
    Character();
    Character(std::string const & name);
    Character(const Character& other);
    Character& operator=(const Character& other);
    ~Character();

    // setters and getters 
    std::string const & getName() const;
    void    setName(std::string const & name);
    AMateria*   getInvontory(int index) const;
    void    setInvontory(int index, AMateria* materia);

    // special methods :
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
};

#endif
