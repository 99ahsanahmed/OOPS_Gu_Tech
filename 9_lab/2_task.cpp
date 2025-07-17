#include<iostream>
#include<cmath>
using namespace std;
class Complex
{
private:
    double real, imag;

public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}
    // TODO: Implement these operators
    // Complex operator+(const Complex& other) const;✅
    // Complex operator-(const Complex& other) const;✅
    // Complex operator*(const Complex& other) const;✅
    // bool operator==(const Complex& other) const;
    // friend ostream& operator<<(ostream& os, const Complex& c);
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }
    Complex operator*(const Complex& other) const {
        double realEq, imagEq;

        realEq = real * other.real - imag * other.imag;
        imagEq = real * other.imag + imag * other.real;

        return Complex(realEq, imagEq);
    }
    bool operator==(const Complex& other) const{
        return real == other.real && imag == other.imag;
    }
    friend ostream& operator<<(ostream& os, const Complex& c){
        os << c.real << "+" << c.imag << "i";
        return os;
    }
    double magnitude() const
    {
        return sqrt(real * real + imag * imag);
    }

    // void display(){
    //     cout << real << "+" << imag << "i\n";
    // }
};
int main()
{
    Complex c1(3,2);
    Complex c2(1,4);
    Complex c3 = c1 * c2;
    Complex c4 = c1 + c2;
    Complex c5 = c1 - c2;
    if(c1 == c2){
        cout << "Equal\n";
    }else{
        cout << "Not equal\n";
    }
    cout << "Product: " << c3 << endl;
    cout << "Sum: " << c4 << endl;
    cout << "Difference: " << c5 << endl;
    return 0;
}