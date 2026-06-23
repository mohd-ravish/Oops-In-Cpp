#include <iostream>
#include <math.h>

using namespace std;

/*
Operator Overloading (a form of Static / Compile-time Polymorphism) -->
1. Operator Overloading lets us redefine how built-in operators (+, *, <, >, ==)
   behave for our custom types. The correct overloaded function is resolved at
   compile-time based on the operand types — hence it is static polymorphism.
2. Inside a member operator function, 'this' is the left-hand operand; the
   parameter 'p' is the right-hand operand.
3. Arithmetic operators (+, *) return a new Point by value — they do not modify
   the operands, so they are marked const.
4. Comparison operators (<, >, ==) compare points by their squared distance from
   the origin (_x*_x + _y*_y), rather than coordinate-by-coordinate.

'e' is a static threshold used by operator== to decide near-equality.
*/

class Point {
    double _x;
    double _y;
    static double e; // Threshold for equality comparison, shared across all Point objects

public:
    void setCoords(double x, double y);
    void printCoords();
    Point();                               // Default constructor
    Point(double x, double y);             // Parameterized constructor
    Point(Point& p);                       // Copy constructor
    ~Point();                              // Destructor
    Point operator+(const Point& p) const; // Returns a new Point = this + p
    Point operator*(double s) const;       // Returns a new Point scaled by s
    bool operator<(const Point& p) const;  // True if this is closer to origin than p
    bool operator>(const Point& p) const;  // True if this is farther from origin than p
    bool operator==(const Point& p) const; // True if norms differ by less than threshold e
};

double Point ::e = -29.55;

void Point ::setCoords(double x, double y) {
    _x = x;
    _y = y;
}

void Point ::printCoords() {
    cout << "(X: " << _x << ", Y: " << _y << ")" << endl;
}

Point ::Point() : _x(0), _y(0) {
    cout << "Default Constructor Invoked" << endl;
}

Point ::Point(double x, double y) {
    cout << "Parameterized Constructor Invoked" << endl;
    _x = x;
    _y = y;
}

Point ::Point(Point& p) {
    cout << "Copy Constructor Invoked" << endl;
    _x = p._x;
    _y = p._y;
}

Point ::~Point() { cout << "Default Destructor Invoked" << endl; }

Point Point ::operator+(const Point& p) const {
    Point q;
    q._x = _x + p._x;
    q._y = _y + p._y;
    return q;
}

Point Point::operator*(const double s) const {
    Point temp;
    temp._x = _x * s;
    temp._y = _y * s;
    return temp;
}

bool Point ::operator<(const Point& p) const {
    double a, b;
    a = _x * _x + _y * _y;
    b = p._x * p._x + p._y * p._y;
    return a < b;
}

bool Point ::operator>(const Point& p) const {
    double a, b;
    a = _x * _x + _y * _y;
    b = p._x * p._x + p._y * p._y;
    return a > b;
}

bool Point ::operator==(const Point& p) const {
    double a, b;
    a = _x * _x + _y * _y;
    b = p._x * p._x + p._y * p._y;
    return (a - b) < e;
}

int main() {
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