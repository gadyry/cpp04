
#include "Cat.hpp"
#include "Dog.hpp"

#include "WrongCat.hpp"

int main()
{
    std::cout << "================ sub-typing polymorphism : ================\n\n";

    std::cout << "=============== Testing with a virtual method :   ==============\n"<<std::endl;
    // const Animal* meta = new Animal(); //  Not allowed

    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    i->makeSound(); //will output the cat sound!
    j->makeSound();
    // meta->makeSound();

    std::cout << "\n============== Testing without a virtual method : ================\n"<<std::endl;

    const WrongAnimal* wrongMeta = new WrongAnimal();
       
    const WrongAnimal* w = new WrongCat();

    std::cout << w->getType() << " " << std::endl;

    w->makeSound(); //will output the WrongAnimal sound!
    wrongMeta->makeSound();

    std::cout << "\n---------------------------------------------------------------\n"<<std::endl;

    delete i;
    delete j;
    // delete meta;

    delete wrongMeta;
    delete w;

    return (0);
}
