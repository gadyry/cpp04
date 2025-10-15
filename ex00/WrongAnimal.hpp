#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
protected :
    std::string type;
public :
    // constructor  && destructor 
    WrongAnimal();
    WrongAnimal(const std::string& type);
    WrongAnimal(const WrongAnimal& WrongAnimal);
    WrongAnimal& operator=(const WrongAnimal& other);
    ~WrongAnimal();

    // SETTERS && GETTERS 
    void    setType(const std::string& type);
    const std::string&    getType() const;

    void    makeSound() const;
};

#endif
