#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria
{
public :
    // constructor  && destructor 
    Ice();
    Ice(const std::string& type);
    Ice(const Ice& other);
    Ice& operator=(const Ice& other);
    ~Ice();

    AMateria* clone() const;
    // virtual void use(ICharacter& target);
};

#endif
