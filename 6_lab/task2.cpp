// TOOK HELP FROM HUZAIFA SOOMAR, WAS ABSENT IN LAB.
#include <iostream>
using namespace std;

class CryptoExchange
{
public:
    double balance = 100;
    virtual void buyCrypto(double amount) = 0;
    virtual void sellCrypto(double amount) = 0;
    virtual void accBalance() = 0;
    virtual double calcTradingFees(double amount) = 0;
};

class BinanceExchange : public CryptoExchange
{
public:
 
  void buyCrypto(double amount) override {
    double fee = calcTradingFees( amount);
    double totalCost = amount + fee;

    if (balance >=totalCost)
    {
        balance -=totalCost;
        cout << "[Binance] Bought crypto worth $" << amount << " with fee $" << fee << "\n";
    }else{
        cout << "[Binance] Insufficient balance to buy $" << amount << " of crypto \n";
    }
    
  }

  void sellCrypto(double amount) override {
    double fee = calcTradingFees(amount);
    balance += (amount - fee);
    cout << "[Binance] Sold crypto worth $" << amount << " with fee $" << fee << endl;

  }

  void accBalance() override{
    cout << "[Binance] Current Balance: $" << balance << endl;

  }

  double calcTradingFees(double amount) override{
    return amount * 0.01;

  }


  
  
};

class CoinBaseExchange : public CryptoExchange
{
    public:
    void buyCrypto(double amount) override{
        double fee = calcTradingFees(amount);
        double totalCost = amount + fee;

        if (balance >= totalCost)
        {
            balance -= totalCost;
            cout << "[CoinBase] Bought crypto worth $" << amount << " with fee $" << fee << endl;
        }else{
           cout << "[CoinBase] Insufficient balance to buy $" << amount << " of crypto \n"; 
        }
        
    }

    void sellCrypto(double amount) override {
        double fee = calcTradingFees(amount);
        balance += (amount - fee);
        cout << "[CoinBase] Sold crypto worth $" << amount << " with fee $" << fee << endl; 
    }

    void accBalance() override {
        cout << "[CoinBase] current Blance : $" << balance << endl;
    }

   double calcTradingFees(double amount) override{
    return amount *0.025;
   }
   
   
};

class PortfolioManager{

    public:
    CryptoExchange *ex1;
    CryptoExchange *ex2;

    void showBalance(){
        ex1->accBalance();
        ex2->accBalance();
    }

    void performTrades(double binanceBuy, double binanceSell, double coinbaseBuy, double coinbaseSell){
        cout << "\nPerforming Trades\n";
        ex1 ->buyCrypto(binanceBuy);
        ex1 ->sellCrypto(binanceSell);
        
        ex2 ->buyCrypto(coinbaseBuy);
        ex2 ->sellCrypto(coinbaseSell);
    }

};

int main()
{
    BinanceExchange binance;
    CoinBaseExchange coinbase;
    PortfolioManager Pm;
    Pm.ex1 = &binance;
    Pm.ex2 = &coinbase;

    cout << "Initial Balances\n";
    Pm.showBalance();

    Pm.performTrades(200 , 123.4, 300, 45.6);

    cout << "Final Balances\n";
    Pm.showBalance();
    


    return 0;
}