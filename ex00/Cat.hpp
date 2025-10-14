#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include "Animal.hpp"

class Cat : public Animal
{
public :
    // Canonic form :
    Cat();
    Cat(const std::string& name);
};

#endif