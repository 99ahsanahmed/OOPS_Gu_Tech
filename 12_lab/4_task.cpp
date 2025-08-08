#include <iostream>
#include <vector>
using namespace std;

class Polynomial
{
public:
    vector<int> coeffs;

    Polynomial(int degree = 0)
    {
        coeffs.resize(degree + 1, 0);
    }

    void input()
    {
        int degree;
        cin >> degree;
        coeffs.resize(degree + 1, 0);
        for (int i = degree; i >= 0; i--)
            cin >> coeffs[i];
    }

    void display() const
    {
        for (int i = coeffs.size() - 1; i >= 0; i--)
        {
            cout << coeffs[i];
            if (i > 0)
                cout << "x^" << i << " + ";
        }
        cout << endl;
    }

    Polynomial operator+(const Polynomial &other)
    {
        int maxDegree = max(coeffs.size(), other.coeffs.size());
        Polynomial result(maxDegree - 1);
        for (int i = 0; i < maxDegree; i++)
        {
            int a = (i < coeffs.size()) ? coeffs[i] : 0;
            int b = (i < other.coeffs.size()) ? other.coeffs[i] : 0;
            result.coeffs[i] = a + b;
        }
        return result;
    }

    Polynomial operator-(const Polynomial &other)
    {
        int maxDegree = max(coeffs.size(), other.coeffs.size());
        Polynomial result(maxDegree - 1);
        for (int i = 0; i < maxDegree; i++)
        {
            int a = (i < coeffs.size()) ? coeffs[i] : 0;
            int b = (i < other.coeffs.size()) ? other.coeffs[i] : 0;
            result.coeffs[i] = a - b;
        }
        return result;
    }

    Polynomial operator*(const Polynomial &other)
    {
        int degree = coeffs.size() + other.coeffs.size() - 2;
        Polynomial result(degree);
        for (int i = 0; i < coeffs.size(); i++)
        {
            for (int j = 0; j < other.coeffs.size(); j++)
            {
                result.coeffs[i + j] += coeffs[i] * other.coeffs[j];
            }
        }
        return result;
    }
};

int main()
{
    Polynomial p1, p2;
    cout << "Enter degree and coefficients for P1: ";
    p1.input();
    cout << "Enter degree and coefficients for P2: ";
    p2.input();

    Polynomial sum = p1 + p2;
    Polynomial diff = p1 - p2;
    Polynomial prod = p1 * p2;

    cout << "Sum: ";
    sum.display();
    cout << "Difference: ";
    diff.display();
    cout << "Product: ";
    prod.display();
}
