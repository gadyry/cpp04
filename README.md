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


--> here’s a text-based Class diagram that clearly shows the relationships in your CPP04/ex02 setup — including inheritance and composition:


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
