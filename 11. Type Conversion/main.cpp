#include <iostream>
using namespace std;

/*
Type Conversion via Conversion Operator -->
1. A Conversion Operator allows an object of one class to be implicitly converted
   into an object of a different class, just like how C++ converts int to double.
2. It is defined inside the source class using: operator TargetType() const
   No return type is written — the return type IS the operator name itself.
3. Here, 'operator TempC()' inside TempF defines how a Fahrenheit value is converted
   to Celsius using the formula: C = (F - 32) * 5 / 9.
4. Once defined, the compiler calls the conversion operator automatically when a
   TempF is assigned to a TempC variable: TempC c1 = f1;

Real world analogy: Like a currency exchange — you hand over dollars (TempF) and
automatically receive rupees (TempC) after the conversion formula is applied.
*/

/*
Represents a temperature in Celsius.
Constructed directly with a Celsius value or via conversion from TempF.
*/
class TempC {
private:
    double cel;

public:
    TempC() : cel(0) {};
    TempC(double val) : cel(val) {};
    ~TempC() {};
    void display() { cout << "Celsius : " << cel << endl; }
};

/*
Represents a temperature in Fahrenheit.
Defines a conversion operator so it can be implicitly converted to TempC.
*/
class TempF {
private:
    double fah;

public:
    TempF() : fah(0) {};
    TempF(double val) : fah(val) {};
    ~TempF() {};
    void display() { cout << "Fahrenheit : " << fah << endl; }
    operator TempC() const // Conversion operator: TempF -> TempC using F = (C*9/5)+32 inverse
    {
        return TempC((fah - 32.0) * 5.0 / 9.0);
    }
};

int main() {
    TempF f1(100.0);
    TempC c1 = f1; // Object to object conversion
    c1.display();
}