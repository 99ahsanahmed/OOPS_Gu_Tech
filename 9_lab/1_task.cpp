#include<iostream>
using namespace std;

class Fraction
{
private:
    int numerator, denominator;
    int gcd(int a, int b)
    {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
    // Helper function to simplify fraction
    void simplify()
    {
        int g = gcd(abs(numerator), abs(denominator));
        numerator /= g;
        denominator /= g;
        if (denominator < 0)
        {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    // Constructor
    Fraction(int num = 0, int den = 1) : numerator(num), denominator(den)
    {
        if (denominator == 0)
        {
            cout << "Error: Denominator cannot be zero!" << endl;
            denominator = 1;
        }
        simplify();
        cout << "after simplification : " << numerator << "/" << denominator << endl;
    }
    Fraction operator+(const Fraction &other) const
    {
        int r,l,d,result;
        r = numerator * other.denominator;
        l = denominator * other.numerator;
        d= denominator * other.denominator;
        result = r + l;
        return Fraction(result, d);
    }
    Fraction operator-(const Fraction &other) const
    {
        int r,l,d,result;
        r = numerator * other.denominator;
        l = denominator * other.numerator;
        d= denominator * other.denominator;
        result = r - l;
        return Fraction(result, d);
    }
    Fraction operator*(const Fraction &other) const
    {
        return Fraction(numerator * other.numerator, denominator * other.denominator);
    }
    Fraction operator/(const Fraction &other) const
    {
        return Fraction(numerator * other.denominator, denominator * other.numerator);
    }
    bool operator==(const Fraction &other) const
    {
        return (numerator == other.numerator, denominator == other.denominator);
    }
    void display(){
        cout << numerator << "/" << denominator << endl;
    }
//     // TODO: Implement these operators✅✅
//     // Fraction operator+(const Fraction& other) const;✅✅
//     // Fraction operator-(const Fraction& other) const;✅✅
//     // Fraction operator*(const Fraction& other) const;✅✅
//     // Fraction operator/(const Fraction& other) const;✅✅
//     // bool operator==(const Fraction& other) const;✅✅

};
int main()
{
    Fraction f1(8,12);
    Fraction f2(25,30);
    Fraction sum = f1 + f2;
    Fraction sub = f1 - f2;
    Fraction product = f1 * f2;
    Fraction divide = f1 / f2;
    if (f1 == f2)
    {
        cout << "Equal\n";
    }else{
        cout << "Not equal\n";
    }

    sum.display();
    sub.display();
    product.display();
    divide.display();
    
    return 0;
}
