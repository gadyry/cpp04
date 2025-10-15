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

### 🧩 Abstract Class vs Interface :

| **Feature**     | **Abstract Class (C++)**                                 | **Interface (Java / C++)**                                        |
| --------------- | -------------------------------------------------------- | ----------------------------------------------------------------- |
| **Methods**     | Can have both implemented and pure virtual methods       | All methods are pure virtual (no implementation)                  |
| **Inheritance** | Supports single or multiple inheritance                  | Simulates multiple inheritance in C++ via multiple abstract bases |
| **Use**         | Used as a common base with partial shared code           | Defines a strict contract — no implementation                     |
| **In C++**      | Declared with at least one pure virtual function (`= 0`) | A class with *only* pure virtual functions acts as an interface   |
| **In Java**     | Declared with the `abstract` keyword                     | Declared with the `interface` keyword (dedicated syntax)          |
