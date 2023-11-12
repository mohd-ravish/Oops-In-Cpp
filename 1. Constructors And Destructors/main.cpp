#include <iostream>
using namespace std;

class Line
{
private:             // Data Modifiers
      double length; // Attributes or Data

public:
      void setLength(double len); // Behavior or Methods
      double getLength();
      Line();         // Default Constructor
      Line(double l); // Parameterized Constructor
      Line(Line &l);  // Copy Constructor
      ~Line();        // Destructor
};

Line::Line() : length(0)
{
      cout << "Default Constructor Invoked" << endl;
}

Line::Line(double l) : length(l)
{
      cout << "Parameterized Constructor Invoked" << endl;
}

Line::Line(Line &l)
{
      cout << "Copy Constructor Invoked" << endl;
      length = l.length;
}

Line::~Line()
{
      cout << "Default Destructor Invoked" << endl;
}

void Line::setLength(double l)
{
      length = l;
}

double Line ::getLength()
{
      return length;
}

int main()
{
      Line l1; // Object or Instance of class (Using Default Constructor)
      l1.setLength(4.5);
      cout << "Length of the line 1: " << l1.getLength() << endl;
      Line l2(3.4); // Using Parameterized Constructor
      cout << "Length of the line 2: " << l2.getLength() << endl;
      Line l3(l2); // Using Copy Constructor
      cout << "Length of the line 3: " << l3.getLength() << endl;
      return 0;
}
