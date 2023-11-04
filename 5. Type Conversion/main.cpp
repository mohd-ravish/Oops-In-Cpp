#include <iostream>
using namespace std;

class TempC
{
private:
    double cel;

public:
    TempC() : cel(0){};
    TempC(double val) : cel(val){};
    ~TempC(){};
    void display()
    {
        cout << "Celsius : " << cel << endl;
    }
};

class TempF
{
private:
    double fah;

public:
    TempF() : fah(0){};
    TempF(double val) : fah(val){};
    ~TempF(){};
    void display()
    {
        cout << "Fahrenheit : " << fah << endl;
    }
    operator TempC() const // Conversion Operator
    {
        return TempC((fah - 32.0) * 5.0 / 9.0);
    }
};

int main()
{
    TempF f1(100.0);
    TempC c1 = f1; // Object to object conversion
    c1.display();
}