#include <iostream>
using namespace std;
int main()
{
    char opt;
    float num1, num2;
    bool invalidDivide = false;
    while (!invalidDivide)
    {
        try
        {
            cout << "num1\nnum2\noperation\n";
            cin >> num1;
            cin >> num2;
            cin >> opt;
            if (num2 == 0 && opt == '/')
            {
                throw "Cannot divide by zero";
            }
            else
            {
                invalidDivide = true;
            }
            if (opt == '+')
                cout << num1 + num2 << '\n';
            else if (opt == '-')
                cout << num1 - num2 << '\n';
            else if (opt == '*')
                cout << num1 * num2 << '\n';
            else if (opt == '/')
                cout << num1 / num2 << '\n';
        }

        catch (const char *message)
        {
            cout << message << '\n';
        }
    }
}