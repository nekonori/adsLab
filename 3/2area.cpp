#include <bits/stdc++.h>

using namespace std;
#define pln(x) cout << x << "\n";

double area(int r)
{
    return 3.14 * r * r;
}

double area(int l, int b)
{
    return l * b;
}

double area(double s)
{
    return 3 * sqrt(3) / 2 * s * s;
}

int main()
{
    pln("Area of circle with radius 10 units: " + to_string(area(10)));
    pln("Area of rect with len 10 units, breadth 15 units: " + to_string(area(10, 15)));
    pln("Area of hexagon with perimeter 12.45 units: " + to_string(area(12.45)));
}