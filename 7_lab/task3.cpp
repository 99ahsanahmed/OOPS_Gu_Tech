#include <iostream>
using namespace std;

class Product
{
    string name;
    float price;

public:
    Product(string n, float p) : name(n), price(p) {}

    string getName() const
    {
        return name;
    }

    float getPrice() const
    {
        return price;
    }
};

class CartItem
{
    Product *product;
    int quantity;

public:
    CartItem() : product(nullptr), quantity(0){};
    CartItem(Product *p, int q) : product(p), quantity(q)
    {
        cout << "Product added to cart!\n";
    }

    float getTotalPrice() const
    {
        return product->getPrice() * quantity;
    }

    void display() const
    {
        cout << "Name: " << product->getName() << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Total Price: Rs. " << getTotalPrice() << endl;
    }
};

class Cart
{
    CartItem items[10];
    int itemCount;

public:
    Cart() : itemCount(0) {};

    void addItem(Product *p, int qty)
    {
        if (itemCount < 10)
        {
            items[itemCount] = CartItem(p, qty);
            itemCount++;
        }
        else
        {
            cout << "Cart is full. Cannot add more items.\n";
        }
    }

    void showCart() const
    {
        cout << "Cart Contents:\n";
        if (itemCount == 0)
        {
            cout << "Cart is empty.\n";
        }
        else
        {
            for (int i = 0; i < itemCount; i++)
            {
                items[i].display();
            }
        }
    }

    float calculateTotal() const
    {
        float total = 0;
        for (int i = 0; i < itemCount; i++)
        {
            total += items[i].getTotalPrice();
        }
        return total;
    }
};

int main()
{
    Product p1("Laptop", 150000);
    Product p2("Mouse", 2500);
    Product p3("Keyboard", 4000);

    Cart myCart;

    myCart.addItem(&p1, 1);
    myCart.addItem(&p2, 2);
    myCart.addItem(&p3, 1);

    myCart.showCart();

    cout << "Total Cost: Rs. " << myCart.calculateTotal() << endl;

    return 0;
}
