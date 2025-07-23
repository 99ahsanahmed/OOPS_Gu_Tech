#include<iostream>
using namespace std;
int main()
{
    int num;
    cout << "Enter a positive number\n";
    cin >> num;
    try
    {
        if (num < 0)
            throw "Negative number detected";
        
    }
    catch(const char *msg)
    {
        cout << "Exception : " << msg << endl;
    }
    
    return 0;
}