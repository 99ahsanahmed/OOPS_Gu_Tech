#include <iostream>
using namespace std;

class Animal
{
public:
    virtual void sound() { cout << "Animal sound\n"; }
};

class Dog : public Animal
{
public:
    void sound() override { cout << "Bark\n"; }
};

int main()
{
    // Animal *a = new animak[10];
    // animal[0] = new
    // a->sound(); // Outputs: Bark

    Dog kutta;
    kutta.sound();

    cout << "----------------\n";
    
    Animal cat;
    cat.sound();
    return 0;
}
