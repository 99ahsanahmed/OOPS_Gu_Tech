#include<iostream>
using namespace std;

class Item{
    private:
        void whoAmI(){
            cout<<"I am base class"<<endl;
        }
};

class Fooditem : public Item{
    public:
        void calculateDiscount(){
            cout<<"You are rewarded 10 percent dicount"<<endl;
        }
};

class NonFooditem : public Item{
    public:
        void calculateTax(){
            cout<<"after tax your bill is increased to 10 percent"<<endl;
        }
};



int main()
{
    Fooditem f1;
    f1.calculateDiscount();

    NonFooditem nf1;
    nf1.calculateTax();
    return 0;
}