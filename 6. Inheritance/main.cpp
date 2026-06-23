#include <iostream>
using namespace std;

/*
Inheritance -->
1. Inheritance allows a derived (child) class to acquire properties and behaviours
   of a base (parent) class, enabling code reuse and hierarchical relationships.
2. The derived class can reuse (inherit), extend, or override the base class members.
3. 'protected' access means members are accessible inside the base class AND all
   derived classes, but NOT from outside the class hierarchy.
4. Marking base class methods as 'virtual' enables Dynamic Polymorphism — the correct
   overridden version is called at runtime via a base class pointer or reference.

Real world analogy: Employee is the general blueprint for any worker in a company.
Manager and Scientist are specialised roles — they inherit everything an Employee has
(name, number, getdata/putdata) and add their own unique attributes on top.
*/

/*
Base class — holds data and behaviour common to ALL types of employees.
Derived classes (Manager, Scientist) inherit these and extend them.
*/
class Employee
{
protected:
    char name[30]; // employee name
    int number;    // employee number
public:
    Employee() : name(""), number(0) {}
    ~Employee() {}
    virtual void getdata() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter number: ";
        cin >> number;
    }

    virtual void putdata() const {
        cout << "\nName: " << name;
        cout << "\nNumber: " << number;
    }
};

/*
Derived class — inherits from Employee and extends it with Manager-specific fields.
Overrides getdata()/putdata() to also handle title and golf club dues.
*/
class Manager : public Employee
{
private:
    char title[20]; // Title
    double dues;    // golf club dues
public:
    void getdata() // Overrides Employee::getdata — Dynamic Polymorphism
    {
        Employee::getdata();
        cout << "Enter title: ";
        cin >> title;
        cout << "Enter golf club dues: ";
        cin >> dues;
    }
    void putdata() const {
        Employee::putdata();
        cout << "\nTitle: " << title;
        cout << "\nGolf club dues: " << dues;
    }
};

/*
Derived class — inherits from Employee and extends it with Scientist-specific fields.
Overrides getdata()/putdata() to also handle the number of publications.
*/
class Scientist : public Employee
{
private:
    int pubs; // number of publications
public:
    void getdata() // Overrides Employee::getdata — Dynamic Polymorphism
    {
        Employee::getdata();
        cout << "Enter number of publications: ";
        cin >> pubs;
    }
    void putdata() const {
        Employee::putdata();
        cout << "\nNumber of publications: " << pubs;
    }
};

int main() {
    Manager m1;
    Scientist s1;
    // Input data for employees
    cout << "\nEnter data for manager\n";
    m1.getdata();
    cout << "\nEnter data for scientist\n";
    s1.getdata();
    // Display data for employees
    cout << "\nData on manager\n";
    m1.putdata();
    cout << "\nData on scientist\n";
    s1.putdata();
    return 0;
}

// If you don't define any constructors or a destructor in a derived class, and
// the base class has a default constructor and a default destructor, then the
// compiler will automatically generate default constructors and a default
// destructor for the derived class and they will call the default constructor
// and default destructor of the base class, respectively.