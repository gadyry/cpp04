#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"


class Cat : public Animal
{
private :
    Brain*  brain;

public :
    //  Arthodox Canonic form :
    Cat();
    Cat(const std::string& name);
    Cat(const Cat& other);
    Cat&    operator=(const Cat& other);

    ~Cat();

    // Special method :
    void makeSound() const;

    Brain* getBrain() const;
};

#endif
