#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <iostream>
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
    AMateria* inventory[4];

public:
    // Orthodox Canonical Form
    MateriaSource();
    MateriaSource(const MateriaSource& other);
    MateriaSource& operator=(const MateriaSource& other);
    ~MateriaSource();

    // Interface implementation
    void learnMateria(AMateria* m);
    AMateria* createMateria(std::string const & type);
};

#endif
