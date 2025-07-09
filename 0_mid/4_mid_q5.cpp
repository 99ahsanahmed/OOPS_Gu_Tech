#include <iostream>
using namespace std;

const int max_staff = 12;
class Order
{
protected:
    string ownerName;
    int no_items;
    string items[10];
public:
    void makeOrder(){
        cout << "owner name\n";
        cin >> ownerName;
        cout << "Number of items should be less than 10\n";
        cin >> no_items;
        for (int i = 0; i < no_items; i++)
        {
            cout << i + 1 << "-item:\n";
            cin >> items[i];
        }
        cout << "Your [" << ownerName << "] order is : \n";
        for (int i = 0; i < no_items; i++)
        {
            cout << items[i] << ", ";
        }
    }
};

class Reservation
{
    public:
        string ownerName;
        int table_no;
        int no_people;
        int date;

        void reserveTable(){
            cout << "owner name\n";
            cin >> ownerName;
            cout << "table no\n";
            cin >> table_no;
            cout << "number of people\n";
            cin >> no_people;
            cout << "date [format : dd/mm/yy]:\n";
            cin >> date;
            cout << "seat reserved for " << ownerName << " at table no " << table_no << " for " << no_people << " people on " << date << endl;
        }        
};

class LoyaltyProgram
{
    public:
    int no_orders;
    string client_Name;

    void loyaltyEligible(){
        cout << "Check whether you are eligible for loyalty program\n";
        cout << "Your name\n";
        cin >> client_Name;
        cout << "Your number of orders in 1 year:\n";
        cin >> no_orders;
        if (no_orders > 15)
        {
            cout << "Congratulations you are eligible for 15 percent discount\n";
        }
        else if (no_orders > 10 && no_orders < 15 )
        {
            cout << "Congratulations you are eligible for 10 percent discount\n";
        }
        else{
            cout << "Sorry you are not eligible for discount\n";
        }
        
    }

};


class Client
{
    Order order;
    Reservation reservation;
    LoyaltyProgram loyalty;
public:
    void makeOrder(){
        order.makeOrder();
    }

    void reserveTable(){
        reservation.reserveTable();
    }

    void checkLoyalty(){
        loyalty.loyaltyEligible();
    }
};

class Menu
{
public:
    string items[6] = {"biryani", "chicken", "mutton", "beef", "naan", "drinks"};
    void getMenu()
    {
        for (int i = 0; i < 6; i++)
        {
            cout << items[i] << endl;
        }
    }

    void editMenu()
    {
        string updatedItem, item;
        bool correctItem;
        cout << "which item do you want to update?\n";
        cin >> item;
        cout << "with what item?\n";
        cin >> updatedItem;

        for (int i = 0; i < 6; i++)
        {
            if (items[i] == item)
            {
                items[i] = updatedItem;
                cout << "Item updated successfully\n";
                correctItem = true;
                break;
            }
        }
        if (!correctItem)
        {
            cout << "You entered wrong item\n";
        }
    }
};

class Staff
{
    string order;

public:
    int id;
    string name, shift;
    
    Staff(string n, int id, string shift) : name(n), id(id), shift(shift) {};
    
    void takeOrder(string order)
    {
        this->order = order;
    }
};

class Owner
{
    Staff *staff[max_staff];
    Menu menu;
    int count;

public:
    Owner() : count(0) {}

    void addStaff(Staff *stf)
    {
        if (count < max_staff)
        {
            staff[count++] = stf;
        }

        else
        {
            cout << "Cannot add more staff. Limit reached.\n";
        }
    }
    void showStaff()
    {
        cout << "Staff in your restaurant:\n";
        for (int i = 0; i < count; ++i)
        {
            cout << i + 1 << ". ";
            cout << staff[i]->name << "-" << staff[i]->id << endl;
        }
    }

    void editMenu()
    {
        menu.editMenu();
    }
};
int main()
{
    // Staff s1("ahsan", 123, "morning");
    // Owner o1;
    // o1.addStaff(&s1);
    // o1.showStaff();

    // o1.editMenu();
    // Menu m;
    // m.editMenu();
    // m.getMenu();

    Client ahsan;
    ahsan.makeOrder();
    // ahsan.reserveTable();
    // ahsan.checkLoyalty(); 
    return 0;
}