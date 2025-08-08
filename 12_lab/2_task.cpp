#include <iostream>
#include <fstream>
#include <map>
#include <string>
using namespace std;

class student{
    public:
    string id,name;
    student(){};
    student(string id, string name) : id(id) , name(name){};

    // bool operator < (const student& other ){
    //     string id1 = id, id2 = other.id;
    //     return id1 < id2;
    // }
};

int main() {
    fstream data("students.csv");
    if (!data)
    {
        cout << "File not found";
    }

    string id,name;
    map<string,student> students;
    
    while(getline(data , id, ',') && getline(data, name, ',')){
        students[id] = student(id, name);
    }

    data.close();

    for (std::pair<string, student>  i : students)
    {
        student std = i.second;
        cout << std.id << " , " << std.name << endl;
    }
    
    return 0;
}