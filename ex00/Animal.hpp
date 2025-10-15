#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
protected :
    std::string type;
public :
    // constructor  && destructor 
    Animal();
    Animal(const std::string& type);
    Animal(const Animal& Animal);
    Animal& operator=(const Animal& other);
    virtual ~Animal();

    // SETTERS && GETTERS 
    void    setType(const std::string& type);
    const std::string&    getType() const;

    virtual void    makeSound() const;
};

#endif
