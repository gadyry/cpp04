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
    Character* me = new Character("David");
    Character* enemy = new Character("Goblin");

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
    delete tmp;     // clean manually (since equip() refused it)

    std::cout << "\n=== [ STEP 4: Using Materias ] ===" << std::endl;
    me->use(0, *enemy);
    me->use(1, *enemy);
    me->use(2, *enemy);
    me->use(3, *enemy);
    me->use(5, *enemy); // invalid index -> should do nothing

    std::cout << "\n=== [ STEP 5: Unequip Materia ] ===" << std::endl;
    me->unequip(2); // should not delete the Materia
    me->use(2, *enemy); // should do nothing (slot empty)

    std::cout << "\n=== [ STEP 6: Copy Character (Deep Copy Test) ] ===" << std::endl;
    Character copy(*me); // ✅ Copy constructor (deep copy)

    std::cout << "Original name: " << me->getName() << std::endl;
    std::cout << "Copy name:     " << copy.getName() << std::endl;

    std::cout << "\n--- Using Materias from copy ---" << std::endl;
    copy.use(0, *enemy);
    copy.use(1, *enemy);

    std::cout << "\n--- Modifying copy ---" << std::endl;
    copy.unequip(0); // this should not affect 'me'
    std::cout << "Copy unequipped slot 0.\n";
    std::cout << "Using original again to verify deep copy:" << std::endl;
    me->use(0, *enemy); // should still work → proves deep copy


    // std::cout << "\n=== [ STEP 8: Copy Assignment Test ] ===" << std::endl;

    //     // Create a new character to test assignment
    //     Character assignTest("AssignTest");

    //     // Equip original character with Materias
    //     assignTest.equip(src->createMateria("ice"));
    //     assignTest.equip(src->createMateria("cure"));

    //     // Perform copy assignment from 'me' to 'assignTest'
    //     assignTest = *(dynamic_cast<Character*>(me));

    //     // Verify names
    //     std::cout << "Original name: " << me->getName() << std::endl;
    //     std::cout << "Assigned name: " << assignTest.getName() << std::endl;

    //     // Verify that Materias are deep-copied
    //     std::cout << "\n--- Using Materias from assigned character ---" << std::endl;
    //     for (int i = 0; i < 4; i++)
    //     {
    //         std::cout << "Slot " << i << ": ";
    //         assignTest.use(i, *enemy);
    //     }

    //     // Unequip a Materia from assigned character to check independence
    //     assignTest.unequip(0);
    //     std::cout << "\n--- After unequipping slot 0 from assigned character ---" << std::endl;
    //     assignTest.use(0, *enemy); // should do nothing
    //     me->use(0, *enemy);        // original should still work

    //     std::cout << "\n--- End of Copy Assignment Test ---" << std::endl;


    std::cout << "\n=== [ STEP 7: Destructor Test ] ===" << std::endl;
    delete enemy;
    delete me;
    delete src;

    std::cout << "\n=== [ END TEST - check for leaks ] ===" << std::endl;
    return 0;
}