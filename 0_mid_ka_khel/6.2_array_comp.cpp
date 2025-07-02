#include <iostream>
using namespace std;

class Subject
{
    int marks;

public:
    void setMarks(int m) { marks = m; }
    int getMarks() const { return marks; }
};

class Student
{
    Subject subjects[3]; // array of Subject objects
public:
    void input()
    {
        int m;
        for (int i = 0; i < 3; ++i)
        {
            cout << "Enter marks for subject " << i + 1 << ": ";
            cin >> m;
            subjects[i].setMarks(m);
        }
    }

    void displayTotal() const
    {
        int total = 0;
        for (int i = 0; i < 3; ++i)
            total += subjects[i].getMarks();
        cout << "Total marks: " << total << endl;
    }
};

int main()
{
    Student s;
    s.input();
    s.displayTotal();
    return 0;
}
