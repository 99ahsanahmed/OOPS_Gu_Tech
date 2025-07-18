#include<iostream>
using namespace std;
class Project{
    private:
        string title;
    public:
        Project(string t) : title(t) {};
        void getTitle(){
            cout << title << endl;
        }
};

class Freelancer{
    private:
        string freelancer_name;
        Project* projects[10];
        int projectCount;
    public:
        Freelancer(string n) : freelancer_name(n), projectCount(0) {};
        void addProject(Project* p){

            // TO CHECK DUPLICATION -- Will not run on 0
            for (int i = 0; i < projectCount; i++)
            {
                if (projects[i] == p)
                {
                    cout << "duplicate projects not allowed! \n";
                    return; 
                }
            }

            // CHECK 2
            if (projectCount >= 10) {
                cout << "Cannot add more projects. Limit reached.\n";
                return;
            }

            projects[projectCount] = p;
            projectCount++;
            cout << "Project added successfully.\n";
            return;
        }

        void listProjects(){
            cout << freelancer_name << "'s projects:\n";
            for (int i = 0; i < projectCount; i++){
                cout << i+1 <<".";
                projects[i]->getTitle();
            }
            
        }
};

int main()
{

    Project p1("App design");
    Project p2("autocad");
    Project p3("graphic designing");

    Freelancer F("Ahsan");

    F.addProject(&p1);
    F.addProject(&p2);
    F.addProject(&p1);
    F.addProject(&p3);

    F.listProjects();   


    return 0;
}