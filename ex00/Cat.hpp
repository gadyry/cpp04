#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
public :
    //  Arthodox Canonic form :
    Cat();
    Cat(const std::string& name);
    Cat(const Cat& other);
    Cat&    operator=(const Cat& other);

    // Special method :
    
};

#endif