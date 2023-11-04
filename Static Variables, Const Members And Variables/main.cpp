#include "header.h"
int main()
{
    Point p1;
    p1.setCoords(2.3, 4.5);
    p1.printCoords();
    Point p2(-6.7, -8.4);
    p2.printCoords();
    double dist = p1.distFrom(p2);
    cout << "Distance from P1 to P2: " << dist << endl;
    Point p3;
    p3 = p1.midPoint(p2);
    cout << "Midpoint of P1 and P2: ";
    p3.printCoords();
    Point p4(p1);
    p4.printCoords();
    cout << "No. of Objects created: ";
    Point ::showCount();
    Point ::showCoordsCount();
    p1.setCoords(2.3, -4.5);
    cout << "\n";
    Point ::showCoordsCount();
    return 0;
}
