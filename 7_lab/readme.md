## 🧱 Composition Example — Key Code with Notes (File : prac_composition)

```cpp
class ElectricCar {
    Battery battery; // Composition: ElectricCar owns Battery

    /*
    📝 NOTES on: Battery battery
    - Battery object `battery` is automatically created when ElectricCar object is created.
    - Memory is allocated on the stack.
    - This is called *composition* and is simple and efficient.
    */

public:
    ElectricCar(int batteryCapacity) : battery(batteryCapacity) {
        cout << "ElectricCar created\n";
    }

    void showDetails() const {
        battery.showCapacity();

        /*
        📝 CONST Notes:
        - This is a `const` member function.
        - You **cannot modify** any member variable here.
        - Example (won't compile):
            battery = Battery(2000); // ❌ Not allowed due to `const`
        */

        cout << "ElectricCar ready to drive\n";
    }
};
