#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
public :
    // Canonic form :
    dog();
    dog(const std::string& name);
};

#endif