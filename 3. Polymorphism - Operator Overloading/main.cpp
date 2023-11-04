#include <iostream>
#include <math.h>
using namespace std;

class Point
{
    static int count;
    static double e;
    double _x;
    double _y;

public:
    void setCoords(double x, double y);
    void printCoords();
    double distFrom(Point &p);
    Point midPoint(Point &p);
    Point();                               // DEFAULT constructor
    Point(double x, double y);             // PARAMETERIZED constructor
    Point(Point &p);                       // COPY constructor
    ~Point();                              // DEFAULT Destructor
    Point operator+(const Point &p) const; // Operator Overloading
    bool operator<(const Point &p) const;
    bool operator>(const Point &p) const;
    bool operator==(const Point &p) const;
    static int getCount();
};

int Point ::count = 0;
double Point ::e = -29.55;

void Point ::setCoords(double x, double y)
{
    _x = x;
    _y = y;
}

void Point ::printCoords()
{
    cout << "(X: " << _x << ", Y: " << _y << ")" << endl;
}

double Point ::distFrom(Point &p)
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

Point ::Point()
{
    cout << "Default Constructor Invoked" << endl;
}

Point ::Point(double x, double y)
{
    cout << "Parameterized Constructor Invoked" << endl;
    _x = x;
    _y = y;
}

Point ::Point(Point &p)
{
    cout << "Copy Constructor Invoked" << endl;
    _x = p._x;
    _y = p._y;
}

Point ::~Point()
{
    cout << "Default Destructor Invoked" << endl;
}

int Point ::getCount()
{
    return count;
}

Point Point ::operator+(const Point &p) const
{
    Point q;
    q._x = _x + p._x;
    q._y = _y + p._y;
    return q;
}

bool Point ::operator<(const Point &p) const
{
    double a, b;
    a = _x * _x + _y * _y;
    b = p._x * p._x + p._y * p._y;
    return a < b;
}

bool Point ::operator>(const Point &p) const
{
    double a, b;
    a = _x * _x + _y * _y;
    b = p._x * p._x + p._y * p._y;
    return a > b;
}

bool Point ::operator==(const Point &p) const
{
    double a, b;
    a = _x * _x + _y * _y;
    b = p._x * p._x + p._y * p._y;
    return (a - b) < e;
}

int main()
{
    Point p1, p2, p3;
    p1.setCoords(2.3, -4.5);
    p2.setCoords(1.8, 7.2);
    p3 = p1 + p2;
    p3.printCoords();
    bool lessThan = p1 < p2;
    cout << lessThan << endl;
    bool greaterThan = p1 > p2;
    cout << greaterThan << endl;
    bool equlanece = p1 == p2;
    cout << equlanece << endl;
    return 0;
}