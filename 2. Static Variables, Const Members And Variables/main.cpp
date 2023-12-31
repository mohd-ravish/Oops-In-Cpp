#include <iostream>
#include <math.h>

using namespace std;

class Point
{
    double _x;
    double _y;
    static int count; // Static Variable

public:
    void setCoords(double x, double y); // Member Function
    void printCoords();                 // Member Function
    static void showCount();
    double distFrom(const Point &p) const; // Const Member Function
    Point midPoint(Point &p);
    Point();                   // Default Constructor
    Point(double x, double y); // Parametrized Constructor
    Point(Point &p);           // Copy Constructor
    ~Point();                  // Destructor
};

int Point ::count = 0;

void Point ::showCount()
{
    cout << count << endl;
}

void Point ::setCoords(double x, double y)
{
    _x = x;
    _y = y;
}

void Point ::printCoords()
{
    cout << "(X: " << _x << ", Y: " << _y << ")" << endl;
}

double Point ::distFrom(const Point &p) const
{
    double dist = 0.0;
    dist = sqrt((this->_x - p._x) * (this->_x - p._x) + (this->_y - p._y) * (this->_y - p._y));
    return dist;
}

Point Point ::midPoint(Point &p)
{
    Point p1;
    double _x = 0.0;
    double _y = 0.0;
    p1._x = (this->_x + p._x) / 2;
    p1._y = (this->_y + p._y) / 2;
    return p1;
}

Point ::Point() : _x(0), _y(0)
{
    count++;
    cout << "Default Constructor Invoked" << endl;
}

Point ::Point(double x, double y)
{
    cout << "Parameterized Constructor Invoked" << endl;
    count++;
    _x = x;
    _y = y;
}

Point ::Point(Point &p)
{
    cout << "Copy Constructor Invoked" << endl;
    count++;
    _x = p._x;
    _y = p._y;
}

Point ::~Point()
{
    count--;
    cout << "Default Destructor Invoked" << endl;
}

int main()
{
    Point p1;
    p1.setCoords(2.3, 4.5);
    p1.printCoords();
    Point p2(-6.7, -8.4);
    p2.printCoords();
    double dist = p1.distFrom(p2);
    cout << "Distance from P1 to P2: " << dist << endl;
    Point p3;
    p3 = p1.midPoint(p2);
    cout << "Midpoint of P1 and P2: ";
    p3.printCoords();
    Point p4(p1);
    p4.printCoords();
    cout << "No. of Objects created: ";
    Point ::showCount();
    return 0;
}
