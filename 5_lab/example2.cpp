// SCOPE RESERVATION
#include <iostream>
using namespace std;
class Father{
    public:
    Father(){
        cout << "Father's constructor\n";
    }
};
class Mother{
    public:
    Mother(){
        cout << "Mother's constructor\n";
    }
};
class Child : public Father, public Mother{
    public:
    Child(){
    cout << "Child's constructor\n";
    }
};
int main(){
    Child c;
    return 0;
}