#include <iostream>
using namespace std;
class Shape
{
float x, y; //Origin
public:
Shape(float x, float y)
{
this->x = x;
this->y = y;
}
virtual void draw()
{

cout << "Drawing a shape\n";

}
};
class Square : public Shape
{
float sideLength;
public:
Square(float sideLength) : Shape(0, 0)
{
this->sideLength = sideLength;
}
Square(float x, float y, float sideLength) : Shape(x, y)
{
this->sideLength = sideLength;
}
void draw()
{

cout << "Drawing a square\n";

}
};
class Circle : public Shape
{
float radius;
public:
Circle(float x = 0, float y = 0, float radius = 0) : Shape(x, y)
{
this->radius = radius;
}
void draw()
{

cout << "Drawing a cirlce\n";

}
};
int main()
{
Shape* a = new Shape(5, 5);
Shape* b = new Square(10);
Shape* c = new Circle();
a->draw(); //Drawing a shape
b->draw(); //Drawing a square
c->draw(); //Drawing a cirlce
delete a;
a = NULL;
delete b;
b = NULL;
delete c;
c = NULL;
return 0;
}