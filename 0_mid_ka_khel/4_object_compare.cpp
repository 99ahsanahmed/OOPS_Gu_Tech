#include <iostream>
using namespace std;

class Student
{
    int id;

public:
    Student(int id) : id(id) {}

    bool operator==(const Student& s){
        id == s.id;
    }
};

int main()
{
    Student s1(10);
    Student s2(10);
    Student s3(20);

    if (s1 == s2)
        cout << "s1 and s2 are equal\n";
    else
        cout << "s1 and s2 are NOT equal\n";

    if (s1 == s3)
        cout << "s1 and s3 are equal\n";
    else
        cout << "s1 and s3 are NOT equal\n";
}
