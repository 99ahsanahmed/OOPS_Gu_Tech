#include <iostream>
using namespace std;

class Polynomial {
private:
    // ax^2 + bx + c
    int a, b, c;

public:
    Polynomial(int a, int b, int c) : a(a), b(b), c(c) {}

    void display() {
        cout << a << "x^2 + " << b << "x + " << c << endl;
    }

    Polynomial operator+(const Polynomial& p) const {
        return Polynomial(a + p.a, b + p.b, c + p.c);
    }

    Polynomial operator-(const Polynomial& p) const {
        return Polynomial(a - p.a, b - p.b, c - p.c);
    }

    Polynomial operator*(const Polynomial& p) const {
        int newA,newB,newC;
        newA = a * p.c + b * p.b + c * p.a; 
        newB = b * p.c + c * p.b;
        newC = c * p.c;
        return Polynomial(newA, newB, newC);
    }

    int evaluate(int x) const {
        return a * x * x + b * x + c;
    }
};


int main() {
    Polynomial p1(1, 2, 3);   
    Polynomial p2(2, 3, 4);   

    cout << "Polynomial 1: ";
    p1.display();

    cout << "Polynomial 2: ";
    p2.display();

    Polynomial sum = p1 + p2;
    cout << "Sum: ";
    sum.display();

    Polynomial diff = p1 - p2;
    cout << "Difference: ";
    diff.display();

    Polynomial product = p1 * p2;
    cout << "Product : ";
    product.display();

    int x = 2;
    cout << "Evaluation of p1 at x = " << x << ": " << p1.evaluate(x) << endl;

    return 0;
}
