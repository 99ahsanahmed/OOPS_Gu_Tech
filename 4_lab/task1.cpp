#include<iostream>
using namespace std;

class Employee{
    public:
        string name; 
        int age;
        float salary;
        void work(){
            cout<<"kam karo";
        } 
};

class Manager : public Employee{
    public: 
    void conductMeeting(){
        cout<<"itss meeting time!";
    }
};

class Developer : public Employee{
    public: 
    void writeCode(){
        cout<<"hack nasa";
    }
};

int main()
{
    Manager m1;
    Developer d1;
    m1.work();
    m1.conductMeeting();


    d1.work();
    d1.writeCode();
    return 0;
}