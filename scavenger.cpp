#include<iostream>
using namespace std;
class Bank{
    private:
    float balance;
    int number;
    string type;
    public:
    virtual void limit() = 0;
    virtual void interest() = 0;    

    virtual void getBalance() = 0;
    virtual void setBalance() = 0;

};

class savings : public Bank{
private:
    int amount;
    int deposit;
protected:
    void getBalance() override {
        if (amount < balance)
        {
            balance -= amount;
        }
    }
    void setBalance() override {
        balance += deposit;
    }
};
class current : public Bank{
};
int main()
{

    return 0;
}