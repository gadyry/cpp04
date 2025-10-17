#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria
{
public :
    // constructor  && destructor 
    Cure();
    Cure(const std::string& type);
    Cure(const Cure& other);
    Cure& operator=(const Cure& other);
    ~Cure();

    AMateria* clone() const;
    // virtual void use(ICharacter& target);

};

#endif