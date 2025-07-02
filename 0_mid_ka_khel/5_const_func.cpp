#include <iostream>
using namespace std;

class Student
{
    string name;

public:
    // Constructor to set the name
    Student(string n) : name(n) {}

    // const function means: "I will not change any member variables"
    void showName() const
    {
        cout << "Name: " << name << endl;
        // name = "Ali"; // ❌ This would give an error because the function is const
    }
};

int main()
{
    const Student s("Ahsan"); // s is a const object, cannot be modified

    s.showName(); // ✅ This works because showName() is a const function

    // s.name = "Ali"; // ❌ Not allowed — s is const
    return 0;
}
