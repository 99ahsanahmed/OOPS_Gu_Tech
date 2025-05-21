#include<iostream>
using namespace std;

bool isPalindrome(string str){
    int j;
    j = str.length()-1;
    cout << j << endl;
    for (int i = 0; i <= j/2; i++)
    { 

        if (str[i] != str[j] ){
            cout << str << " is not a palindrome\n";
            return false;
        }
        j--;
    }
    cout << str << " is a palindrome\n";
    return true;
}

bool isPalindrome(int number){
    string str = to_string(number);
    return isPalindrome(str);
}


int main()
{
    cout << isPalindrome("madama") << endl;
    cout << isPalindrome(123);
    

    return 0;
}