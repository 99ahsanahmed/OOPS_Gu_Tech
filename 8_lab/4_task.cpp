#include <iostream>
#include <cstring>
using namespace std;
class Student
{
    char *name;

public:
    Student(const char *n)
    {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }
    // Faulty copy constructor
    Student(const Student &s)
    {
        name = s.name; // shallow copy!

        // FIX :
        // name = new char[strlen(s.name + 1)];
        // strcpy(name, s.name);
        // This will allocate new memory location or address unlike name = s.name;
    }
    void display()
    {
        cout << name << endl;
    }
    void updateName(const char *n)
    {
        delete[] name; // Learned it from GPT, without delete[]name this code will work like deep copy
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }
    ~Student()
    {
        delete[] name;
    }
};

int main()
{
    Student s1("king babar");
    Student s2 = s1;

    s1.display();
    s2.display();

    s1.updateName("jain");

    s1.display();
    s2.display();

    // output :
    // king babar
    // king babar
    // jain | Shallow
    // jain | Copy

    return 0;
}