#include<iostream>
using namespace std;

class Student{
    private:
    string name;
    int age;
    string grade;
    public:
    Student(string n, int a, string g){

    }
    void setName(string n){
        name = n;
    } 
    void setAge(int a){
        age = a;
    } 
    void setGrade(string g){
        grade = g;
    }
    string getName(){
        return name;
    } 
    int getAge(){
        return age;
    } 
    string getGrade(){
        return grade;
    } 


};

int main()
{
    Student s1("umer" , 34 ,"A");
    s1.setName("ahsan");
    s1.setAge(10);
    s1.setGrade("A+");

    cout<<s1.getName();
    cout<<s1.getAge();
    cout<<s1.getGrade();

    return 0;
}