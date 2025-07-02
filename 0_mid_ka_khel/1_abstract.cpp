#include<iostream>
using namespace std;
// What is it ? An abstract class cannot be instantiated.It's used to define a base template for derived classes.

// When to Use : When multiple classes share common behavior but should implement it differently

class animal {
    public:
    virtual string says(string animal) = 0;
};

class cow : public animal{
    public:
        string says(string a) override{
            return a + " says mooo \n" ;
        }
};

int main(){
    cow c1;
    cout << c1.says("sahiwali"); 
    return 0;
}