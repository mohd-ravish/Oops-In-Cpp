#include <iostream>
using namespace std;

/*
Constructors and Destructors -->
1. A Constructor is a special member function automatically called when an object
   is created. Its job is to initialize the object's data members.
2. A Destructor is a special member function automatically called when an object
   goes out of scope or is deleted. Its job is to clean up.
3. A class can have multiple constructors (overloading), but only one destructor.

Types of Constructors:
- Default Constructor      : Takes no arguments. Sets fields to default values.
- Parameterized Constructor: Takes arguments. Lets you set fields at creation time.
- Copy Constructor         : Takes a reference to an existing object of the same
                             class and copies its data into the new object.

Real world analogy: Think of a Line drawn on a whiteboard. The constructor is the
act of drawing it (setting its length). The destructor is erasing it when you're done.
*/

class Line {
private:           // Data Modifiers
    double length; // Attributes or Data

public:
    void setLength(double len); // Behavior or Methods
    double getLength();
    Line();         // Default Constructor
    Line(double l); // Parameterized Constructor
    Line(Line& l);  // Copy Constructor
    ~Line();        // Destructor
};

Line::Line() : length(0) { cout << "Default Constructor Invoked" << endl; }

Line::Line(double l) : length(l) {
    cout << "Parameterized Constructor Invoked" << endl;
}

Line::Line(Line& l) {
    cout << "Copy Constructor Invoked" << endl;
    length = l.length;
}

Line::~Line() { cout << "Default Destructor Invoked" << endl; }

void Line::setLength(double l) { length = l; }

double Line ::getLength() { return length; }

int main() {
    Line l1; // Object or Instance of class (Using Default Constructor)
    l1.setLength(4.5);
    cout << "Length of the line 1: " << l1.getLength() << endl;
    Line l2(3.4); // Using Parameterized Constructor
    cout << "Length of the line 2: " << l2.getLength() << endl;
    Line l3(l2); // Using Copy Constructor
    cout << "Length of the line 3: " << l3.getLength() << endl;
    return 0;
}