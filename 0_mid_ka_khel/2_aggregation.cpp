#include<iostream>
using namespace std;

// max 12 students in a course and monitor of that course and a teacher
class student{
    string name;
    int roll_no;
    public:
    student(string n, int roll) : name(n), roll_no(roll) {};
    void get_student_details(){
        cout << name << " - " << roll_no << endl;
    }
};

class course{
    string cr, teacher, course_name;
    student* students[12];
    int students_count; 
    public:
        course(string cr, string teacher, string course_name) : cr(cr), teacher(teacher), course_name(course_name), students_count(0) {};

        void add_new_Student(student* st){
            if (students_count < 12)
            {
                students[students_count] = st;
                cout << "new student added \n";
            }else{
                cout << "limits reached!";
            }
            students_count++;
        }

        void list_Students(){
            
            cout << "students : \n";
            
            for (int i = 0; i < students_count; i++)
            {
                cout << i+1 << ". ";
                students[i]->get_student_details();
            }
        }
};

int main()
{
    student s1("ahsan", 123);
    student s2("shamoeel", 124);
    student s3("yamman", 125);
    student s4("ahmed", 126);
    student s5("sadqain", 127);
    student s6("zain", 128);

    course calculas("zaman", "sir furqan", "calculas");

    calculas.add_new_Student(&s1);
    calculas.add_new_Student(&s2);
    calculas.add_new_Student(&s3);
    calculas.add_new_Student(&s4);
    calculas.add_new_Student(&s5);
    calculas.add_new_Student(&s6);

    calculas.list_Students(); 
    return 0;
}