#include<iostream>
using namespace std;
class Point{
private:
int *x;
int *y;

public:
Point(int xVal,int yVal ){
    x = new int(xVal);
    y = new int(yVal);
}

void display(){
    cout << *x << " and " << *y << endl;
}

~Point(){
    delete x,
    delete y;
    cout<<"deleted!";
}
};

int main()
{
    Point p1(3,5);
    Point p2=p1;
    p1.display();
    p2.display();
    return 0;
}