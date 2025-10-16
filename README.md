###  Polymorphism

🧩 The Rule About virtual Destructors

If your class is meant to be inherited from (i.e. used as a base class) and it contains at least one virtual function,
then its destructor must also be virtual.

🔥 Why?

Because when you delete an object through a base class pointer,
C++ will only call the base destructor — unless it’s virtual.
That would cause memory leaks (child destructors never run).

❌ Bad Example (no virtual destructor)
```cpp
class Animal {
public:
    ~Animal() { std::cout << "Animal destroyed\n"; }
    virtual void makeSound() const { std::cout << "Some sound\n"; }
};

class Dog : public Animal {
public:
    ~Dog() { std::cout << "Dog destroyed\n"; }
};

int main() {
    Animal* a = new Dog();
    delete a; // ⚠️ Only Animal::~Animal() is called!
}
```

🧨 Output:
    Animal destroyed

➡️ The Dog part is never destroyed → memory leak or undefined behavior.

✅ Correct Example (virtual destructor)
```cpp
class Animal {
public:
    virtual ~Animal() { std::cout << "Animal destroyed\n"; }
    virtual void makeSound() const { std::cout << "Some sound\n"; }
};

class Dog : public Animal {
public:
    ~Dog() { std::cout << "Dog destroyed\n"; }
};

int main() {
    Animal* a = new Dog();
    delete a; // ✅ Both destructors are called properly
}
```

🟢 Output:

Dog destroyed
Animal destroyed


### 🧩 1️⃣ Composition, not Aggregation : 

| Relationship Type | Description                                                                                                                         | Example                                                                              |
| ----------------- | ----------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------ |
| **Composition**   | A strong “has-a” relationship. The child object **cannot exist without** the parent. The parent **owns** the lifetime of the child. | A `Cat` **has a** `Brain`. When `Cat` dies, its `Brain` is deleted too.              |
| **Aggregation**   | A weak “has-a” relationship. The child can exist independently and is **not owned** by the parent.                                  | A `Teacher` **has** a `Classroom` pointer, but the `Classroom` exists independently. |

### 🧩 2️⃣ Why Cat–Brain is Composition

✅ Brain is created inside the Cat constructor.
✅ It is deleted inside the Cat destructor.
✅ Brain cannot exist without Cat.
✅ Each Cat has its own unique Brain.

Hence, this is a composition relationship.

If it were aggregation, you would pass the Brain from outside:

```cpp
class Cat
{
private:
    Brain* brain;
public:
    Cat(Brain* existingBrain) : brain(existingBrain) {}
};
```

### 🧩 Abstract Class vs Interface :

| **Feature**     | **Abstract Class (C++)**                                 | **Interface (Java / C++)**                                        |
| --------------- | -------------------------------------------------------- | ----------------------------------------------------------------- |
| **Methods**     | Can have both implemented and pure virtual methods       | All methods are pure virtual (no implementation)                  |
| **Inheritance** | Supports single or multiple inheritance                  | Simulates multiple inheritance in C++ via multiple abstract bases |
| **Use**         | Used as a common base with partial shared code           | Defines a strict contract — no implementation                     |
| **In C++**      | Declared with at least one pure virtual function (`= 0`) | A class with *only* pure virtual functions acts as an interface   |
| **In Java**     | Declared with the `abstract` keyword                     | Declared with the `interface` keyword (dedicated syntax)          |


- here’s a text-based Class diagram that clearly shows the relationships in your CPP04/ex02 setup — including inheritance and composition:

```
                    +-------------------+
                    |   <<abstract>>    |
                    |      Animal       |
                    +-------------------+
                    | - type: std::string
                    +-------------------+
                    | + getType() const
                    | + makeSound() const = 0    ← pure virtual
                    | + ~Animal()                ← virtual destructor
                    +-------------------+
                            ▲
                ┌──────────┴──────────┐
                │                     │
        +-------------------+   +-------------------+
        |       Cat         |   |       Dog         |
        +-------------------+   +-------------------+
        | - brain: Brain*   |   | - brain: Brain*   |
        +-------------------+   +-------------------+
        | + makeSound()     |   | + makeSound()     |
        | + getBrain()      |   | + getBrain()      |
        | + ...             |   | + ...             |
        +-------------------+   +-------------------+
                │                     │
                │  Composition        │  Composition
                │  (owns and deletes) │  (owns and deletes)
                ▼                     ▼
                +---------------------------+
                |           Brain           |  
                +---------------------------+ 
                | - ideas[100]: std::string |
                +---------------------------+
                | + getIdeas(i)             |
                | + setIdeas(i, value)      |
                +---------------------------+
```
The above informal interface is not a valid construct in C++; it is just a documentation aid. In particular, it does not contain any data members or definitions of
member functions. Nonetheless, it is useful, since it provides important information about a stack’s public member functions and how they are called.

An abstract class in C++ is a class that is used only as a base class for inheritance; it cannot be used to create instances directly. At first the idea of creating a
class that cannot be instantiated seems to be nonsense, but it is often very important.
For example, suppose that we want to define a set of geometric shape classes, say,
Circle, Rectangle, and Triangle. It is natural to derive these related classes from a
single generic base class, say, Shape. Each of the derived classes will have a virtual
member function draw, which draws the associated object. The rules of inheritance
require that we define such a function for the base class, but it is unclear what such
a function means for a generic shape.

One way to handle this would be to define Shape::draw with an empty function
body ({ }), which would be a rather unnatural solution. What is really desired
here is some way to inform the compiler that the class Shape is abstract; it is not
possible to create objects of type Shape, only its subclasses. In C++, we define
a class as being abstract by specifying that one or more members of its functions
are abstract, or pure virtual. A function is declared pure virtual by giving “=0” in place of its body. C++ does not allow the creation of an object that has one or more pure virtual functions. Thus, any derived class must provide concrete definitions
for all pure virtual functions of the base class.


### --- Class Diag. for ex03 : 

                 +--------------------+
                |    AMateria        |  <<Abstract>>
                +--------------------+
                | - _type: std::string |
                +--------------------+
                | + AMateria(type: std::string) |
                | + virtual ~AMateria()          |
                | + getType(): std::string const |
                | + virtual clone() const = 0    |
                | + virtual use(target: ICharacter&) |
                +--------------------+
                         ▲
          ┌──────────────┼──────────────┐
          │                               │
+------------------+         +------------------+
|      Ice         |         |      Cure        |
+------------------+         +------------------+
| (inherits type="ice") |   | (inherits type="cure") |
+------------------+         +------------------+
| + clone(): AMateria* |     | + clone(): AMateria* |
| + use(target)        |     | + use(target)        |
+------------------+         +------------------+


+---------------------+
|   ICharacter        |  <<Interface>>
+---------------------+
| + getName() const = 0        |
| + equip(m: AMateria*) = 0    |
| + unequip(idx: int) = 0      |
| + use(idx: int, target: ICharacter&) = 0 |
+---------------------+
          ▲
          │
+---------------------+
|   Character         |
+---------------------+
| - _name: std::string    |
| - _inventory[4]: AMateria* |
+---------------------+
| + getName() const        |
| + equip(m: AMateria*)    |
| + unequip(idx: int)      |
| + use(idx: int, target: ICharacter&) |
+---------------------+


+----------------------+
|   IMateriaSource     |  <<Interface>>
+----------------------+
| + learnMateria(m: AMateria*) = 0 |
| + createMateria(type: std::string) = 0 |
+----------------------+
          ▲
          │
+----------------------+
|   MateriaSource      |
+----------------------+
| - _materias[4]: AMateria* |
+----------------------+
| + learnMateria(m: AMateria*) |
| + createMateria(type: std::string) |
+----------------------+
