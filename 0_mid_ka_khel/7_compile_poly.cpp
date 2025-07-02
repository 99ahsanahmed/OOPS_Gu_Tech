#include<iostream>
using namespace std;

class player{
    public:
    void celebrate (int num){
        cout << num;    
    }
    void celebrate (string letters){
        cout << letters;
    }
};

int main()
{
    //Compile time polymorphism
    player p1;
    p1.celebrate("siuuuuuu"); 
    return 0;
}