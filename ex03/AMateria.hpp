#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>

class AMateria
{
protected :
    std::string type;

public :
    // constructor  && destructor 
    AMateria();
    AMateria(const std::string& type);
    AMateria(const AMateria& other);
    AMateria& operator=(const AMateria& other);
    virtual ~AMateria();

    // SETTERS && GETTERS :
    const std::string&    getType() const;
    void    setType(const std::string& type);
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);

};

#endif