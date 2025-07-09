#include<iostream>
using namespace std;
class PaymentGateway{
    public : 
    virtual bool pay(double amount) = 0;
};

class StripeGateway : public PaymentGateway{
    public : 
    bool pay(double amount) override {
        if (amount < 1000)
        {
            cout<<"Payment of " << amount <<" using Stripe: Success \n";
            return true;
        }else{
            cout<<"Payment of " << amount <<" using Stripe: Failed \n";
            return false;
        }
        
    }
};
class PayPalGateway : public PaymentGateway{
    public : 
    bool pay(double amount) override {
        if (amount > 10)
        {
            cout<<"Payment of " << amount <<" using PayPal: Success \n";
            return true;
        }else{
            cout<<"Payment of " << amount <<" using PayPal: Failed \n";
            return false;
        }
        
    }
};
class CryptoGateway : public PaymentGateway{
    public : 
    bool pay(double amount) override {
            cout<<"Payment of " << amount <<" using Crypto: Success \n";
            return true; 
        }
};
int main()
{
    StripeGateway s;
    PayPalGateway p;
    CryptoGateway c;

    s.pay(1100);
    p.pay(11);
    c.pay(1100.567);

    return 0;
}