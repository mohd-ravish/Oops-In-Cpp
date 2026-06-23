#include <iostream>
using namespace std;

/*
Pure Virtual Functions and Abstract Classes -->
1. A Pure Virtual Function is a virtual function with no implementation in the base
   class (declared with '= 0'). Any class containing at least one pure virtual
   function becomes an Abstract Class.
2. An Abstract Class cannot be instantiated directly — you cannot create objects of it.
   It serves as a contract, defining WHAT a derived class must implement.
3. Any class that inherits an abstract class MUST provide implementations for all
   pure virtual functions, or it also becomes abstract.
4. A pointer of the abstract base class type can point to objects of any concrete
   derived class — this enables Runtime (Dynamic) Polymorphism.

Real world analogy: 'Shape' is like a job posting that says "must know how to get
dimensions and compute area". Square and Circle are actual candidates who fulfill
that contract in their own specific way.
*/

class Shape // Abstract Class — defines the interface for all shapes
{
public:
    virtual void getData() = 0; // Pure virtual function — derived class MUST implement
    virtual void putData() = 0; // Pure virtual function — derived class MUST implement
};

/*
Concrete class that fulfills the Shape contract.
Provides its own implementation of getData() and putData() for a rectangle.
*/
class Square : public Shape
{
private:
    float l, b;

public:
    void getData() {
        cout << "Enter length: ";
        cin >> l;
        cout << "Enter Breadth: ";
        cin >> b;
    }
    void putData() { cout << "Area of Square: " << l * b << endl; }
};

/*
Concrete class that fulfills the Shape contract.
Provides its own implementation of getData() and putData() for a circle.
*/
class Circle : public Shape
{
private:
    float r;

public:
    void getData() {
        cout << "Enter radius: ";
        cin >> r;
    }
    void putData() { cout << "Area of Circle: " << 3.14 * r * r << endl; }
};

int main() {
    Shape* ptr[10]; // Holds the references of objects
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0)
            ptr[i] = new Square;
        else
            ptr[i] = new Circle;
    }
    // Runtime polymorphism
    for (int i = 0; i < 10; i++) {
        ptr[i]->getData();
        ptr[i]->putData();
    }
}