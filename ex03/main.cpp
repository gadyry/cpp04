#include "Ice.hpp"
#include "Cure.hpp"
#include "AMateria.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"


// int main()
// {
//     std::cout << "\n--- Testing Ice ---" << std::endl;
//     {
//         AMateria* ice1 = new Ice();
//         AMateria* ice2 = ice1->clone();
//         AMateria* ice3 = new Ice("Lea Sydoux !");

//         std::cout << "ice1 type: " << ice1->getType() << std::endl;
//         std::cout << "ice2 type (cloned): " << ice2->getType() << std::endl;
//          std::cout << "ice3 type (cloned): " << ice3->getType() << std::endl;

//         delete ice1;
//         delete ice2;
//         delete ice3;
//     }

//     std::cout << "\n--- Testing Cure ---" << std::endl;
//     {
//         AMateria* cure1 = new Cure();
//         AMateria* cure2 = cure1->clone();

//         std::cout << "cure1 type: " << cure1->getType() << std::endl;
//         std::cout << "cure2 type (cloned): " << cure2->getType() << std::endl;

//         delete cure1;
//         delete cure2;
//     }

//     std::cout << "\n--- Copy and Assignment Test ---" << std::endl;
//     {
//         Ice iceOriginal;
//         Ice iceCopy(iceOriginal);
//         Ice iceAssigned;
//         iceAssigned = iceOriginal;

//         Cure cureOriginal;
//         Cure cureCopy(cureOriginal);
//         Cure cureAssigned;
//         cureAssigned = cureOriginal;
//     }

//     std::cout << "\n--- Test completed successfully ---" << std::endl;
//     return 0;
// }


int main()
{
    IMateriaSource* src = new MateriaSource();

    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");

    AMateria* tmp;

    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;

    return 0;
}