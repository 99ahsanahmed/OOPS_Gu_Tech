// COMPOSITION

#include <iostream>
using namespace std;
class Battery {
    int capacity;
    public:
    Battery(int cap) : capacity(cap) {
        cout << "Battery created with capacity " << capacity << "mAh\n";}
    void showCapacity() const {
        cout << "Battery capacity: " << capacity << "mAh\n";}
    };
class ElectricCar {
    Battery battery; // Composition: ElectricCar owns Battery
    /* NOTES of Battery battery👆
    Battery object battery automatically created when ElectricCar object is created.
    Memory allocated on stack.
    Simple and efficient.
    */

    public:
    ElectricCar(int batteryCapacity) : battery(batteryCapacity) {
        cout << "ElectricCar created\n";
    }
    void showDetails() const {
        battery.showCapacity();
        /* CONST notes
        battery = Battery(2000); 
        CONST ki wajah se ap isko nahi change kar sakhtay 
        cout << "ElectricCar ready to drive\n";
        */
    }
};
int main() {
    ElectricCar car(5000);
    car.showDetails();

    // Battery b1(200);
    // b1.showCapacity();
    return 0;
}