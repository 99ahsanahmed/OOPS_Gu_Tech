#include <iostream>
using namespace std;
class Engine
{
public:
    Engine() { cout << "Engine created\n"; }
    ~Engine() { cout << "Engine destroyed\n"; }
};

class Car
{
    Engine engine; // Composition
public:
    Car() { cout << "Car created\n"; }
    ~Car() { cout << "Car destroyed\n"; }
};

int main()
{
    Car BMW;
    cout << "---------";
    Engine toyota;
    return 0;
}