#include <iostream>
using namespace std;

class Teacher; //Had to see this from GPT, because it is new to me.
class Student{
    private:
    string name;
    public:
    Student(string n) : name(n) {}
    friend void printName(Student s, Teacher t);
};
class Teacher{
    private:
    string name;
    public:
    Teacher(string n) : name(n) {}
    friend void printName(Student s, Teacher t);
};
void printName(Student s,Teacher t){
    cout << "Student name: " << s.name << endl;     
    cout << "Teacher name: " << t.name << endl;
}
int main(){
    Student s("zain");
    Teacher t("chandioooo");
    printName(s,t);
    return 0;
}   