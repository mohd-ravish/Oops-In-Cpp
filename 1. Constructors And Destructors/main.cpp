#include <iostream>;
using namespace std;

class Line
{
private:                          // Data Modifiers
      double length;              // Attributes or Data

public:
      void setLength(double len); // Behavior or Methods
      double getLength();
      Line();                     // Constructor
      ~Line();                    // Destructor
};

Line::Line()
{
      cout << "Default Constructor Invoked" << endl;
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
      Line line;  // Object or Instance of class
      line.setLength(4.5);
      cout << "Length of the line : " << line.getLength() << endl;
      return 0;
}
