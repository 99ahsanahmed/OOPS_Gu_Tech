#include<iostream>
using namespace std;
class Employee{
    private: 
        string name;
        int salary;
        string position;
    public :
        Employee(){
            name = "";
            salary = 0;
            position = "";
        }
        Employee(string n, int s, string p){
            name = n;
            salary = s;
            position = p;
        }
        void printDetails(){
            cout<<name<<" "<<salary<<" "<<position<<endl;
        }
};

int main()
{
    Employee e1;
    Employee e2("yousuf", 10, "coordinator");

    e1.printDetails();
    e2.printDetails();
    return 0;
}