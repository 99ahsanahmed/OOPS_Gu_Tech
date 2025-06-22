#include <iostream>
using namespace std;

class Birthday
{
    int day;
    int month;
    int year;

public:
    Birthday() : day(1), month(1), year(2000) {}

    Birthday(int d, int m, int y) : day(d), month(m), year(y) {}

    void show() const
    {
        cout << day << "/" << month << "/" << year << endl;
    }
};

class Person
{
    string name; 
    string city;
    Birthday birthday;

public:
    Person(string n, string c, Birthday b) : name(n), city(c), birthday(b) {}

    void display() const
    {
        cout << "Name: " << name << endl;
        cout << "City: " << city << endl;
        cout << "Birthday: ";
        birthday.show();
        cout << endl;
    }
};

int main()
{
    Birthday b(14, 8, 1947);
    Person p("Ahsan", "Delhi", b);
    p.display();

    return 0;
}
