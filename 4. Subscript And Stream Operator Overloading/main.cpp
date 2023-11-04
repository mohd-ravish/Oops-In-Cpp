#include <iostream>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;

class Point
{
    double _x;
    double _y;

public:
    // Member Functions
    void setCoords(double x, double y);
    void printCoords();
    double distFrom(const Point &p) const;
    double Norm() const;
    Point midPoint(Point &p);
    // Constructors
    Point();                   // Default Constructor
    Point(double x, double y); // Parameterized Constructor
    Point(Point &p);           // Copy Constructor
    ~Point();                  // Default Destructor
    // Operator Overloading
    Point operator+(const Point &p) const;
    bool operator<(Point &p) const;
    bool operator>(Point &p) const;
    Point operator*(double s) const;
    bool operator==(Point &p) const;
    // Subscript Operator
    double &operator[](const int i);
    // Stream operator
    friend ostream &operator<<(ostream &os, Point &p);
};

void Point::setCoords(double x, double y)
{
    _x = x;
    _y = y;
}

void Point::printCoords()
{
    cout << "\n(x, y) = "
         << "(" << _x << ", " << _y << ")" << endl << endl;
}

double Point::distFrom(const Point &p) const
{
    double dist = 0.0;
    dist = sqrt((_x - p._x) * (_x - p._x) + (_y - p._y) * (_y - p._y));
    return dist;
}

double Point::Norm() const
{
    double dist = 0.0;
    dist = (_x * _x) + (_y * _y);
    return dist;
}

Point Point::midPoint(Point &p)
{
    Point temp;
    temp._x = (this->_x + p._x) / 2;
    temp._y = (this->_y + p._y) / 2;
    return temp;
}

Point::Point(void)
{
    cout << "Default constructor Invoked" << endl;
}

Point::~Point(void)
{
    cout << "Obeject has been Destroyed" << endl;
}

Point::Point(double x, double y)
{
    cout << "Paramaterised constructor Invoked" << endl;
    _x = x;
    _y = y;
}

Point::Point(Point &p)
{
    cout << "Copy constructor Invoked" << endl;
    _x = p._x;
    _y = p._y;
}

Point Point::operator+(const Point &p) const
{
    Point temp;
    temp._x = _x + p._x;
    temp._y = _y + p._y;
    return temp;
}

bool Point::operator<(Point &p) const
{
    double n1, n2;
    n1 = _x * _x + _y * _y;
    n2 = p._x * p._x + p._y * p._y;
    return (n1 < n2);
}

bool Point::operator>(Point &p) const
{
    double n1, n2;
    n1 = _x * _x + _y * _y;
    n2 = p._x * p._x + p._y * p._y;
    return (n1 > n2);
}

bool Point::operator==(Point &p) const
{
    double tol = 0.02;
    double n1, n2;
    n1 = (_x * _x + _y * _y);
    n2 = (p._x * p._x + p._y * p._y);
    return fabs(n1 - n2) < tol;
}

Point Point::operator*(const double s) const
{
    Point temp;
    temp._x = _x * s;
    temp._y = _y * s;
    return temp;
}

double &Point::operator[](const int i)
{
    double retVal = 0;
    if (i > 1 || i < 0)
    {
        cout << "Out Of Bounds" << endl;
    }
    if (i == 0)
    {
        return _x;
    }
    else if (i == 1)
    {
        return _y;
    }
}

ostream &operator<<(ostream &os, Point &p)
{
    os << "\nPoint : (" << p[0] << ", " << p[1] << ")";
    os << ", Norm = " << p.Norm() << endl << endl;
    return os;
}

void insertionSort(Point arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        Point temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = temp;
    }
}

int main()
{
    Point p1, p4;            // Object Instantiated
    Point p2(3.4, 5.2);
    Point p3(p1);            // Data of P1 will be copied to p3
    p1.setCoords(2.6, 5.4);
    p1.printCoords();
    p2.printCoords();
    cout <<"Distance from P1 to P2 : " << p1.distFrom(p2) << endl << endl;
    p4 = p1.midPoint(p2);
    cout << "\nMid Point of P1 and P2 : ";
    p4.printCoords();
    double val = p1[0];
    cout << "\nReturn value using subscript operator : " << val << endl;
    p1[0] = 3.1;
    p1[1] = 1.3;
    cout << "Values after changing using subscript operator : ";
    p1.printCoords();
    cout << "Distance of P1 from Origin : " << p1.Norm() << endl;
    cout << p1;
    // Array of Objects
    Point points[3];
    points[0] = Point(5, 1);
    points[1] = Point(4, 1);
    points[2] = Point(3, 1);

    for (int i = 0; i < 3; i++)
    {
        cout << points[i];
    }
    
    insertionSort(points, 3);
    for (int i = 0; i < 3; i++)
    {
        cout << points[i];
    }
}