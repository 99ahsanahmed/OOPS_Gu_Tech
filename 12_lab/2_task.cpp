#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

class student{
    public:
    string id,name;
    student(){};
    student(string id, string name) : id(id) , name(name){};

    bool operator<(const student& other )const{
        string id1 = id, id2 = other.id;

        transform(id1.begin(), id1.end(), id1.begin(), ::tolower);
        transform(id2.begin(), id2.end(), id2.begin(), ::tolower);

        return id1 < id2;
    }
};

int main() {
    fstream data("students.csv");
    if (!data)
    {
        cout << "File not found";
    }

    string id,name;
    set<student> students;
    
    while(getline(data , id, ',') && getline(data, name, ',')){
        students.insert(student(id, name));
    }

    data.close();

    for (const auto& i : students)
    {
        cout << i.id << " , " << i.name << endl;
    }
    
    return 0;
}