#include <iostream>
#include <cstring>
using namespace std;
class Address
{
public:
    char *city;
    Address() : city(nullptr) {}
    Address(const char *c)
    {
        city = new char[strlen(c) + 1];
        strcpy(city, c);
    }

    Address(const Address &original)
    {
        city = new char[strlen(original.city) + 1];
        strcpy(city, original.city);
    }

    ~Address()
    {
        delete[] city;
    }
};

class Person
{
    char *name;
    Address address;

public:
    Person() : name(nullptr), address() {}
    Person(const char *c, const char *n) : address(c) // "NEW-GPT"
    {

        // address.city = new char[ strlen(c) + 1];
        // strcpy(name, c);  "OLD" 
        
        name = new char[ strlen(n) + 1];
        strcpy(name, n); 

    }
    Person(const Person &original) : address(original.address) // "NEW-GPT"
    {
        // address.city = new char[strlen(adr.city) + 1];
        // strcpy(address.city, adr.city); "OLD"

        name = new char[strlen(original.name) + 1];
        strcpy(name, original.name);
    }

    void upateNameCity(const char *c, const char *n)
    {
        delete[] address.city;
        delete[] name;
        address.city = new char[strlen(c) + 1];
        strcpy(address.city, c);

        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }

    void view(){
        cout << "Name : " << name << ",City : " << address.city << endl; 
    }
    ~Person(){
        delete[] name;
    }
};
int main()
{
    Person p1("karachi", "ahsan");
    Person p2 = p1;
    Person p3 = p1;
    cout << "Before Update:\n";
    p1.view();
    p2.view();
    p3.view();
    
    cout << "\nAfter Updating P1 only:\n";
    p1.upateNameCity("Lahore","moosa");
    p1.view();
    p2.view();
    p3.view();
    return 0;
}