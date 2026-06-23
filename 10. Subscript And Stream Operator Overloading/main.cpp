#include <bits/stdc++.h>
using namespace std;

/*
Subscript Operator [] and Stream Operator << Overloading -->
1. The Subscript Operator [] lets you access an object's members using array-style
   indexing. Here, p[0] maps to _x and p[1] maps to _y.
   It returns 'double&' (a reference) so the caller can both READ and WRITE:
       double val = p[0];  // read
       p[0] = 3.1;         // write
2. The Stream Operator << must be a 'friend' function (not a member) because the
   left operand is 'ostream', not Point. A friend function gets access to private
   members without being a member itself.
3. Overloading these operators makes Point feel like a built-in type — you can write
   'cout << p' or 'p[0] = 3.1' naturally in client code.
4. 'Norm()' returns the squared distance from the origin (_x^2 + _y^2), used as
   a sorting key in insertionSort.
*/

class Point {
    double _x;
    double _y;

public:
    // Member Functions
    void setCoords(double x, double y);
    void printCoords();
    double Norm() const;           // Returns squared distance from origin (_x^2 + _y^2)
    // Constructors
    Point();                       // Default Constructor
    Point(double x, double y);     // Parameterized Constructor
    Point(Point& p);               // Copy Constructor
    ~Point();                      // Destructor
    // Operator Overloading
    bool operator>(Point& p) const;       // Compares norms (distance from origin)
    double& operator[](const int i);      // p[0] -> _x, p[1] -> _y (returns reference)
    friend ostream& operator<<(ostream& os, Point& p); // Prints Point and its Norm
};

void Point::setCoords(double x, double y) {
    _x = x;
    _y = y;
}

void Point::printCoords() {
    cout << "\n(x, y) = "
         << "(" << _x << ", " << _y << ")" << endl
         << endl;
}

double Point::Norm() const {
    double dist = 0.0;
    dist = (_x * _x) + (_y * _y);
    return dist;
}

Point::Point(void) : _x(0), _y(0) {
    cout << "Default constructor Invoked" << endl;
}

Point::Point(double x, double y) {
    cout << "Paramaterised constructor Invoked" << endl;
    _x = x;
    _y = y;
}

Point::Point(Point& p) {
    cout << "Copy constructor Invoked" << endl;
    _x = p._x;
    _y = p._y;
}

Point::~Point(void) { cout << "Default destructor Invoked" << endl; }

bool Point::operator>(Point& p) const {
    double n1, n2;
    n1 = _x * _x + _y * _y;
    n2 = p._x * p._x + p._y * p._y;
    return (n1 > n2);
}

double& Point::operator[](const int i) {
    double retVal = 0;
    if (i > 1 || i < 0) {
        cout << "Out Of Bounds" << endl;
    }
    if (i == 0) {
        return _x;
    } else if (i == 1) {
        return _y;
    }
}

ostream& operator<<(ostream& os, Point& p) {
    os << "\nPoint : (" << p[0] << ", " << p[1] << ")";
    os << ", Norm = " << p.Norm() << endl << endl;
    return os;
}

void insertionSort(Point arr[], int n) {
    for (int i = 1; i < n; i++) {
        Point temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = temp;
    }
}

int main() {
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

    for (int i = 0; i < 3; i++) {
        cout << points[i];
    }

    insertionSort(points, 3);
    for (int i = 0; i < 3; i++) {
        cout << points[i];
    }
}