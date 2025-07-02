#include <iostream>
using namespace std;

class Student
{
    int marks[5]; // array as data member
public:
    void inputMarks()
    {
        cout << "Enter 5 marks: ";
        for (int i = 0; i < 5; ++i)
            cin >> marks[i];
    }

    void showMarks() const
    {
        cout << "Marks: ";
        for (int i = 0; i < 5; ++i)
            cout << marks[i] << " ";
        cout << endl;
    }
};

int main()
{
    Student s;
    s.inputMarks();
    s.showMarks();
    return 0;
}
