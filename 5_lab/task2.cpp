#include <iostream>
using namespace std;
class Printer{
public:
    void print()
    {
        cout << "Printing..\n";
    }
};
class Scanner{
public:
    void scan()
    {
        cout << "Scanning\n";
    }
};
class Copier : public Scanner, public Printer
{
public:
    void copy()
    {
        scan();
        print();
        cout << "Copying..\n";
    }
};
int main()
{
    Copier c;
    c.copy();
    return 0;
}