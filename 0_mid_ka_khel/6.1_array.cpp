#include <iostream>
using namespace std;

class Student
{
    string name;
    int id;

public:
    void input()
    {
        cout << "Enter name and ID: ";
        cin >> name >> id;
    }

    void show() const
    {
        cout << "Name: " << name << ", ID: " << id << endl;
    }
};

int main()
{
    Student students[3]; // array of objects

    for (int i = 0; i < 3; ++i)
        students[i].input();

    cout << "\nStudent Details:\n";
    for (int i = 0; i < 3; ++i)
        students[i].show();

    return 0;
}
