#include <iostream>
#include <string>

using namespace std;

/*
Dynamic Polymorphism in real life says that 2 Objects coming from same
family will respond to same stimulus differently. Like in real world Manual
car and Electric car will respond to accelerate() differently.

To represent this in programming, we create a parent class that defines all
characters and behaviours that are generic to all child classes and are also
same in all child classes but make those methods abstract(virtual) that are
generic to all child classes but all child class will behave differently. Then
those child class will provide implementation details of these abstract methods
the way they want.
*/

/*
Pure Virtual Function vs Impure Virtual Function -->

Pure Virtual Function:
- Declared with '= 0' in the base class. Has NO implementation in the base class.
- Forces every derived class to provide its own implementation.
- Making a class contain even one pure virtual function turns it into an Abstract Class
  (you cannot create objects of it directly).
- Example below: accelerate() and brake() in Car are pure virtual.
  ManualCar and ElectricCar MUST override them — the compiler enforces this.

Impure Virtual Function (regular virtual):
- Declared with 'virtual' but WITHOUT '= 0'. HAS an implementation in the base class.
- Derived classes MAY override it, but they don't have to.
  If they don't, the base class version is used.
- The class is NOT abstract and CAN be instantiated directly.
- Example below: startEngine() and stopEngine() in Car are regular (non-virtual) here,
  but if they were marked 'virtual' (without = 0), they would be impure virtual —
  derived classes could optionally override them with their own version.

In summary:
  virtual void foo() = 0;  --> Pure Virtual   : MUST override, class becomes abstract
  virtual void foo() { }   --> Impure Virtual  : MAY override, class stays concrete
*/

class Car {
protected:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;

public:
    Car(string brand, string model) {
        this->brand = brand;
        this->model = model;
        this->isEngineOn = false;
        this->currentSpeed = 0;
    }
    
    // Common methods for All cars.
    void startEngine() {           // Regular function — same for all cars, not overridable
        isEngineOn = true;
        cout << brand << " " << model << " : Engine started." << endl;
    }

    void stopEngine() {            // Regular function — same for all cars, not overridable
        isEngineOn = false;
        currentSpeed = 0;
        cout << brand << " " << model << " : Engine turned off." << endl;
    }

    virtual void accelerate() = 0; // Abstract method for Dynamic Polymorphism also a Pure Virtual — no body, derived class MUST override
    virtual void brake() = 0;      // Abstract method for Dynamic Polymorphism also a Pure Virtual — no body, derived class MUST override
    virtual ~Car() {}              // Virtual destructor also an Impure Virtual — has a body, derived class MAY override
};

class ManualCar : public Car {
private:
    int currentGear;

public:
    ManualCar(string brand, string model) : Car(brand, model) {
        this->currentGear = 0;
    }

    // Specialized method for Manual Car
    void shiftGear(int gear) {
        currentGear = gear;
        cout << brand << " " << model << " : Shifted to gear " << currentGear << endl;
    }

    // Overriding accelerate - Dynamic Polymorphism
    void accelerate() {
        if (!isEngineOn) {
            cout << brand << " " << model << " : Cannot accelerate! Engine is off." << endl;
            return;
        }
        currentSpeed += 20;
        cout << brand << " " << model << " : Accelerating to " << currentSpeed << " km/h" << endl;
    }

    // Overriding brake - Dynamic Polymorphism
    void brake() {
        currentSpeed -= 20;
        if (currentSpeed < 0) currentSpeed = 0;
        cout << brand << " " << model << " : Braking! Speed is now " << currentSpeed << " km/h" << endl;
    }
};

class ElectricCar : public Car {
private:
    int batteryLevel;

public:
    ElectricCar(string brand, string model) : Car(brand, model) {
        this->batteryLevel = 100;
    }

    // Specialized method for Electric Car
    void chargeBattery() {
        batteryLevel = 100;
        cout << brand << " " << model << " : Battery fully charged!" << endl;
    }

    // Overriding accelerate - Dynamic Polymorphism
    void accelerate() {
        if (!isEngineOn) {
            cout << brand << " " << model << " : Cannot accelerate! Engine is off." << endl;
            return;
        }
        if (batteryLevel <= 0) {
            cout << brand << " " << model << " : Battery dead! Cannot accelerate." << endl;
            return;
        }
        batteryLevel -= 10;
        currentSpeed += 15;
        cout << brand << " " << model << " : Accelerating to " << currentSpeed << " km/h. Battery at " << batteryLevel << "%." << endl;
    }

    // Overriding brake - Dynamic Polymorphism
    void brake() {
        currentSpeed -= 15;
        if (currentSpeed < 0) currentSpeed = 0;
        cout << brand << " " << model << " : Regenerative braking! Speed is now " << currentSpeed << " km/h. Battery at " << batteryLevel << "%." << endl;
    }
};

int main() {
    Car* myManualCar = new ManualCar("Suzuki", "WagonR");
    myManualCar->startEngine();
    myManualCar->accelerate();
    myManualCar->accelerate();
    myManualCar->brake();
    myManualCar->stopEngine();

    cout << "----------------------" << endl;

    Car* myElectricCar = new ElectricCar("Tesla", "Model S");
    myElectricCar->startEngine();
    myElectricCar->accelerate();
    myElectricCar->accelerate();
    myElectricCar->brake();
    myElectricCar->stopEngine();

    // Cleanup
    delete myManualCar;
    delete myElectricCar;

    return 0;
}