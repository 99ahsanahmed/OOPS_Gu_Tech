#include<iostream>
using namespace std;

class Student{
string name;
int id;
float marks;
public :
 void addStudent_record(){
    cout << "Enter name, id and marks\n";
    cin >> name >> id >> marks;
 }
};
int main()
{
    return 0;
}