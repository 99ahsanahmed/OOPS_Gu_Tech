#include<iostream>
using namespace std;

class User{
    public:
    int userId;
    string name;
    User(int userId, string name){
        this->userId = userId;
        this->name = name;
    }
    virtual void displayProfile() const = 0;
    virtual string getRole() const = 0;
};

class Employer : public User{
    public:
        string companyName; 
        int jobPosts;

        Employer(string companyName, int jobPosts, int userId, string name) : User(userId,name)
        {
            this->companyName = companyName;
            this->jobPosts = jobPosts;
        }

        string getRole() const override{
            return "Employer";
        }

        void displayProfile() const override {
            cout << " " << companyName << " " << jobPosts << " " << userId << " " << name << endl;
        }
};

class Applicant : public User{
    public:
        string resumeTitle; 
        int appliedJobs;

        Applicant(string resumeTitle, int appliedJobs, int userId, string name) : User(userId,name)
        {
            this->resumeTitle = resumeTitle;
            this->appliedJobs = appliedJobs;
        }

        string getRole() const override{
            return "Applicant";
        }

        void displayProfile() const override {
            cout << resumeTitle << appliedJobs << userId << name;
        }
};

int main()
{

    // VARIABLES:

    int no_applicants, no_empl, no_users;
    int jobPosts, userId_empl, userId_appl, appliedJobs;
    string companyName, name_empl, name_appl, resumeTitle;

    cout << "number of employees \n";
    cin >> no_empl;

    cout << "number of applicants \n";
    cin >> no_applicants;

    no_users = no_empl + no_applicants;

    User **usersList = new User *[no_users];

    
    cout << "For employees\n";
    for (int i = 0; i < no_empl; i++){
        
        cout << "for employee" << i+1 << endl;

        cin >> companyName >> jobPosts >> userId_empl >> name_empl;

        usersList[i] = new Employer(companyName, jobPosts, userId_empl, name_empl);
    }

    for (int i = no_empl; i < no_users; i++){
        int applicantCount=1;
        cout << "for applicant " << applicantCount << endl;

        cin >> resumeTitle >> appliedJobs >> userId_appl >> name_appl;

        usersList[i] = new Applicant(resumeTitle, appliedJobs, userId_appl, name_appl);
        
        applicantCount++;
    }
    

    for (int i = 0; i < no_empl; i++){     
        cout  << i+1 << ".";
        cout << "role : " << usersList[i]->getRole() << endl;
        usersList[i]->displayProfile();
    }

    for (int i = no_empl; i < no_users; i++){     
        cout << "role : " << usersList[i]->getRole() << endl;
        usersList[i]->displayProfile();
    }

    //DELETE

    for (int i = 0; i < no_users; i++)
    {
        delete usersList[i];
    }
    delete[] usersList;
    
    return 0;
}