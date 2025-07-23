#include<iostream>
#include<stdexcept>
using namespace std;
int main()
{
    int age;
    cin >> age;
    try
    {
        if (age < 0) throw age;
        if (age > 150) throw "Unrealistic age";
        
    }
    catch(const int e)
    {
        cout << e << '\n';
    }
    catch(const char* msg)
    {
        cout << "String exception caught:" << msg << '\n';
    }
    
    return 0;
}