#include <iostream>
using namespace std;

class Animal
{
public:
    virtual void speak() { cout << "Animal sound\n"; }
};

class Dog : public Animal
{
public:
    void speak() { cout << "Woof!\n"; }
};

class Cat : public Animal
{
public:
    void speak(){ cout << "Meow!\n"; }
};

void makeItSpeak(Animal* a)
{
    a->speak(); // Works with any subclass of Animal
}

int main()
{
    Animal a;
    Dog d;
    Cat c;

    makeItSpeak(&a);
    makeItSpeak(&d); // Output: Woof!
    makeItSpeak(&c); // Output: Meow!
}
