#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
public :
    // Canonic form :
    Dog();
    Dog(const std::string& name);
    Dog(const Dog& other);
    Dog&    operator=(const Dog& other);

    ~Dog();

    // Special method :
    void makeSound() const;
};

#endif