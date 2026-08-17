/*
3 - Polymorphism
Create a class hierarchy:
- Parent class: Shape with a virtual function area().
- Child classes: Rectangle, Circle that override area().

Specifications:
- Rectangle stores length and width.
- Circle stores the radius.
- Create a Shape* pointer.
- Assign it to both Rectangle and Circle objects.
- Call the area() method through the Shape* pointer.
*/

#include <iostream>
using namespace std;
class Shape
{
public:
    virtual double area()
    {
        return 0;
    }
};

class Rectangle : public Shape
{
private:
    double length;
    double width;

public:
    Rectangle(double l, double w)
        : length(l), width(w)
    {
    }

    double area() override
    {
        return length * width;
    }
};

class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double r) : radius(r)
    {
    }

    double area() override
    {
        return 3.141592 * radius * radius;
    }
};
int main_6()
{
    Rectangle rectangle(10, 5);
    Circle circle(5);

    Shape *ptr;

    ptr = &rectangle;
    cout << "Area of Rectangle: " << ptr->area() << endl;

    ptr = &circle;
    cout << "Area of Circle: " << ptr->area() << endl;

    return 0;
}
