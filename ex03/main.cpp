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


// int main()
// {
//     IMateriaSource* src = new MateriaSource();

//     src->learnMateria(new Ice());
//     src->learnMateria(new Cure());

//     ICharacter* me = new Character("me");

//     AMateria* tmp;

//     tmp = src->createMateria("ice");
//     me->equip(tmp);
//     tmp = src->createMateria("cure");
//     me->equip(tmp);

//     ICharacter* bob = new Character("bob");
//     me->use(0, *bob);
//     me->use(1, *bob);

//     delete bob;
//     delete me;
//     delete src;

//     return 0;
// }

int main()
{
    std::cout << "\n=== [ STEP 1: Create Materia Source ] ===" << std::endl;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    std::cout << "\n=== [ STEP 2: Create Characters ] ===" << std::endl;
    ICharacter* me = new Character("David");
    ICharacter* enemy = new Character("Goblin");

    std::cout << "\n=== [ STEP 3: Create and Equip Materias ] ===" << std::endl;
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);

    tmp = src->createMateria("cure");
    me->equip(tmp);

    tmp = src->createMateria("ice");
    me->equip(tmp);

    tmp = src->createMateria("cure");
    me->equip(tmp);

    // Try to equip one more than 4 -> should do nothing
    std::cout << "\n--- Trying to equip more than 4 Materias ---" << std::endl;
    tmp = src->createMateria("ice");
    me->equip(tmp); // should be ignored
    delete tmp;     // clean manually

    std::cout << "\n=== [ STEP 4: Using Materias ] ===" << std::endl;
    me->use(0, *enemy);
    me->use(1, *enemy);
    me->use(2, *enemy);
    me->use(3, *enemy);

    // invalid index
    me->use(5, *enemy);

    std::cout << "\n=== [ STEP 5: Unequip Materia ] ===" << std::endl;
    me->unequip(2); // should not delete
    me->use(2, *enemy); // should do nothing

    std::cout << "\n=== [ STEP 6: Copy Character (Deep Copy Test) ] ===" << std::endl;
    Character copy = *(dynamic_cast<Character*>(me));
    std::cout << "Original name: " << me->getName() << std::endl;
    std::cout << "Copy name:     " << copy.getName() << std::endl;

    std::cout << "\n--- Using Materias from copy ---" << std::endl;
    copy.use(0, *enemy);
    copy.use(1, *enemy);

    std::cout << "\n=== [ STEP 7: Destructor test ===" << std::endl;
    delete enemy;
    delete me;
    delete src;

    std::cout << "\n=== [ END TEST - check for leaks ] ===" << std::endl;

    return 0;
}
