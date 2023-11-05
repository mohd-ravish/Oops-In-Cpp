//Inheritance - A class, called the derived class, can inherit the features of another class, called the base class.

#include <iostream>
using namespace std;

class Employee // employee class
{
protected:
    char name[30]; // employee name
    int number;    // employee number
public:
    Employee() : name(""), number(0) {}
    ~Employee() {}
    virtual void getdata()
    {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter number: ";
        cin >> number;
    }

    virtual void putdata() const
    {
        cout << "\nName: " << name;
        cout << "\nNumber: " << number;
    }
};

class Manager : public Employee // management class
{
private:
    char title[20]; // Title
    double dues;    // golf club dues
public:
    void getdata() // Overriding functions
    {
        Employee::getdata();
        cout << "Enter title: ";
        cin >> title;
        cout << "Enter golf club dues: ";
        cin >> dues;
    }
    void putdata() const
    {
        Employee::putdata();
        cout << "\nTitle: " << title;
        cout << "\nGolf club dues: " << dues;
    }
};

class Scientist : public Employee // scientist class
{
private:
    int pubs; // number of publications
public:
    void getdata() // Overriding functions
    {
        Employee::getdata();
        cout << "Enter number of publications: ";
        cin >> pubs;
    }
    void putdata() const
    {
        Employee::putdata();
        cout << "\nNumber of publications: " << pubs;
    }
};

int main()
{
    Manager m1;
    Scientist s1;
    // Input data for employees
    cout << "\nEnter data for manager\n";
    m1.getdata();
    cout << "\nEnter data for scientist\n";
    s1.getdata();
    // Display data for several employees
    cout << "\nData on manager\n";
    m1.putdata();
    cout << "\nData on scientist\n";
    s1.putdata();
    return 0;
}

// If you don't define any constructors or a destructor in a derived class, and the base class has a default constructor and a default destructor, then the compiler will automatically generate default constructors and a default destructor for the derived class and they will call the default constructor and default destructor of the base class, respectively.