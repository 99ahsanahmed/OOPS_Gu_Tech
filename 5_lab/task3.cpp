#include<iostream>
using namespace std;
class Person{
    private :
        string name;
        int age;
    public : 
        void setName(string name){
            this-> name = name;
        }
        void setAge(int age){
            this-> age = age;
        }

        string getName(){
            return name;
        }
        int getAge(){
            return age;
        }
};

class Student : virtual public Person{
    public :
    void study(){
        cout << "Studying.." << endl;
    }
};
class Teacher : virtual public Person{
    public :
    void teach(){
        cout << "Teaching.." << endl;
    }
};

class TeacherAssistant : public Student, public Teacher{

};
int main()
{
    TeacherAssistant t1;
    t1.setAge(10);
    t1.setName("jain");
    cout << t1.getAge() << endl;
    cout << t1.getName()<< endl;
    t1.study();
    t1.teach();

    return 0;
}