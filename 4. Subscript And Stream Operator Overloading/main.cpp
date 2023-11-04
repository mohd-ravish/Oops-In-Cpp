#include <bits/stdc++.h>
using namespace std;

class Point
{
    double _x;
    double _y;

public:
    // Member Functions
    void setCoords(double x, double y);
    void printCoords();
    double Norm() const;
    // Constructors
    Point();                   // Default Constructor
    Point(double x, double y); // Parameterized Constructor
    Point(Point &p);           // Copy Constructor
    ~Point();                  // Default Destructor
    // Operator Overloading
    bool operator>(Point &p) const;
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
         << "(" << _x << ", " << _y << ")" << endl
         << endl;
}

double Point::Norm() const
{
    double dist = 0.0;
    dist = (_x * _x) + (_y * _y);
    return dist;
}

Point::Point(void) : _x(0), _y(0)
{
    cout << "Default constructor Invoked" << endl;
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

Point::~Point(void)
{
    cout << "Default destructor Invoked" << endl;
}

bool Point::operator>(Point &p) const
{
    double n1, n2;
    n1 = _x * _x + _y * _y;
    n2 = p._x * p._x + p._y * p._y;
    return (n1 > n2);
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
    os << ", Norm = " << p.Norm() << endl
       << endl;
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
    Point p1;
    p1.setCoords(2.6, 5.4);
    p1.printCoords();

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