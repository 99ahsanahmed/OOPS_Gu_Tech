#include <iostream>
using namespace std;

class Item
{
protected:
    int productId;
    string name;

public:
    Item(int productId, string name) : productId(productId), name(name) {};
    virtual void display () = 0;
};

class Product : public Item{
    int expiryDate; //(as day, month, year integers)
    double cost;
    Item *items[5];
    int ItemsCount;
    public:
        Product(int expirydate, double cost, int productId, string name) : expiryDate(expirydate), cost(cost),ItemsCount(0), Item(productId, name) {}

        int getexpiryDate(){
            return expiryDate;
        }

        // bool operator==(const Product &s){
        //     expiryDate == s.expiryDate;
        // }

        // void display() override{
        //     cout << 
        // }
};

int main()
{
    Product p1(02,50,8,"milkpak");
    // Item *item = new Product();
    return 0;
}