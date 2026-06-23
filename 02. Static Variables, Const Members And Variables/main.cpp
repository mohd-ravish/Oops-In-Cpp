#include <iostream>
#include <math.h>

using namespace std;

/*
Pure Functions vs Impure Functions -->
A Pure Function:
- Output depends ONLY on its input parameters.
- Has NO side effects (does not modify external state, no I/O, no globals).
- Given the same inputs, always returns the same output. Deterministic.
- Example below: distFrom() and midPoint() are pure — they take inputs, compute,
  and return a value. Nothing outside them changes.

An Impure Function:
- Output may depend on external state (object variables, globals, I/O).
- Has side effects — modifies state, prints to console, reads input, etc.
- May return different results for the same inputs. Non-deterministic.
- Example below: printCoords() is impure (has cout side effect), setCoords() is
  impure (modifies _x and _y), constructors/destructor are impure (modify state).

Note: C++ 'const' member functions are related but not the same — they only
promise not to modify the object's own members, but can still do I/O (impure).
*/

/*
Static Variables, Const Member Functions, and Static Methods -->
1. A static variable declared inside a class is shared across ALL objects of
   that class — it does not belong to any single instance. Here 'count' tracks
   how many Point objects currently exist in memory.
2. A const member function (e.g. distFrom, midPoint return type) promises not to
   modify any member variables. This allows it to be called on const objects and
   signals read-only intent to the compiler and the reader.
3. A static method (e.g. showCount) belongs to the class itself, not to any
   particular object. It can only access static members because there is no 'this'
   pointer in a static method.

Real world analogy: Think of each Point as a person entering a building.
'count' is the shared visitor counter at the entrance — every person arriving
(constructor) increments it, and every person leaving (destructor) decrements it.
No single person owns the counter; the building (class) does.
*/

class Point {
    double _x;
    double _y;
    static int count; // Static Variable - A variable that retains its value throughout the program and is shared across all objects (if declared in a class).

public:
    void setCoords(double x, double y);    // IMPURE — modifies object state (_x, _y)
    void printCoords();                    // IMPURE — side effect (cout)
    static void showCount();               // IMPURE — side effect (cout)
    double distFrom(const Point& p) const; // PURE   — depends only on inputs, no side effects
    Point midPoint(Point& p);              // PURE   — depends only on inputs, returns new Point
    Point();                   // IMPURE — modifies state (count++, cout)
    Point(double x, double y); // IMPURE — modifies state (count++, cout)
    Point(Point& p);           // IMPURE — modifies state (count++, cout)
    ~Point();                  // IMPURE — modifies state (count--, cout)
};

int Point ::count = 0;

void Point ::showCount() { cout << count << endl; }

void Point ::setCoords(double x, double y) {
    _x = x;
    _y = y;
}

void Point ::printCoords() {
    cout << "(X: " << _x << ", Y: " << _y << ")" << endl;
}

double Point ::distFrom(const Point& p) const {
    double dist = 0.0;
    dist = sqrt((this->_x - p._x) * (this->_x - p._x) +
                (this->_y - p._y) * (this->_y - p._y));
    return dist;
}

Point Point ::midPoint(Point& p) {
    Point p1;
    double _x = 0.0;
    double _y = 0.0;
    p1._x = (this->_x + p._x) / 2;
    p1._y = (this->_y + p._y) / 2;
    return p1;
}

Point ::Point() : _x(0), _y(0) {
    count++;
    cout << "Default Constructor Invoked" << endl;
}

Point ::Point(double x, double y) {
    cout << "Parameterized Constructor Invoked" << endl;
    count++;
    _x = x;
    _y = y;
}

Point ::Point(Point& p) {
    cout << "Copy Constructor Invoked" << endl;
    count++;
    _x = p._x;
    _y = p._y;
}

Point ::~Point() {
    count--;
    cout << "Default Destructor Invoked" << endl;
}

int main() {
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