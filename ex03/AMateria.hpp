#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>

class AMateria
{
protected :
    // Data mumber !!
public :
    // constructor  && destructor 
    AMateria();
    AMateria(const std::string& idea);
    AMateria(const AMateria& other);
    AMateria& operator=(const AMateria& other);
    ~AMateria();

    // SETTERS && GETTERS :

};

#endif