#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public :
    //  Arthodox Canonic form :
    WrongCat();
    WrongCat(const std::string& name);
    WrongCat(const WrongCat& other);
    WrongCat&    operator=(const WrongCat& other);

    ~WrongCat();

    // Special method :
    void makeSound() const;
};

#endif