//An abstract class is a class that cannot be instantiated on its own. 
//It serves as a blueprint for other classes, and it contains pure virtual functins

#include <iostream>
using namespace std;

class Shape // person class (Abstract Class)
{
public:
    virtual void getData() = 0; // pure virtual func
    virtual void putData() = 0; // pure virtual func
};

class Square : public Shape // Square class
{
private:
    float l, b;

public:
    void getData() // get student data from user
    {
        cout << "Enter length: ";
        cin >> l;
        cout << "Enter Breadth: ";
        cin >> b;
    }
    void putData()
    {
        cout << "Area of Square: " << l * b << endl;
    }
};

class Circle : public Shape // professor class
{
private:
    float r;

public:
    void getData() // get professor data from user
    {
        cout << "Enter radius: ";
        cin >> r;
    }
    void putData()
    {
        cout << "Area of Circle: " << 3.14 * r * r << endl;
    }
};

int main()
{
    Shape* ptr[10]; // Holds the references of objects
    for(int i = 0; i < 10; i++)
    {
        if(i%2==0)
            ptr[i] = new Square;
        else
            ptr[i] = new Circle;
    }
    for(int i = 0; i < 10; i++)
    {
        ptr[i]->getData();
        ptr[i]->putData();
    }
}