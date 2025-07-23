#include<iostream>
#include<stdexcept>
using namespace std;
int main()
{
    int nums[5] = {1,2,3,4,5};
    int index;
    cin >> index;
    try
    {
        if (index < 0 || index > 4) throw out_of_range("Invalid index"); 
        cout << nums[index];
    }
    catch(const out_of_range& e)
    {
        cout << " error : " << e.what() << '\n';
    }
    
    return 0;
}