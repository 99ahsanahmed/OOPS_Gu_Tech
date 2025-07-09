#include <iostream>
using namespace std;
class Engine
{
    int horsepower;

public:
    Engine(int hp) : horsepower(hp)
    {
        cout << "Engine created with " << horsepower << " HP\n";
    }
    void showPower() const
    {
        cout << "Engine power: " << horsepower << " HP\n";
    }
};
class Car
{
    Engine *engine; // Aggregation: Car has a pointer to Engine, but does not own it
public:
    Car(Engine *eng) : engine(eng)
    {
        cout << "Car created\n";
    }
    void showDetails() const
    {
        if (engine)
            engine->showPower();
        cout << "Car ready to drive\n";
    }
};
int main()
{
    Engine myEngine(300);
    Engine myEngine1(450);
    Engine myEngine2(100);
    Car myCar(&myEngine); // Engine exists independently of Car
    myCar.showDetails();
    return 0;
}