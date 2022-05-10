#include <bits/stdc++.h>

using namespace std;

class Vehicle
{
public:
    string name;
    int hour, peakHourFee;
    double distance, amount;
    double getEstimate()
    {
        amount = 10 * distance;
        if (hour >= 18 && hour <= 20)
        {
            amount += peakHourFee;
        }
        return amount;
    }
};

class Ola : public Vehicle
{
public:
    Ola(double dist, int h, string pName)
    {
        name = pName;
        distance = dist;
        hour = h;
        peakHourFee = 20;
    }
};
class Uber : public Vehicle
{
public:
    Uber(double dist, int h, string pName)
    {
        name = pName;
        distance = dist;
        hour = h;
        peakHourFee = 15;
    }
};

void compare(Ola ola, Uber uber)
{
    if (ola.getEstimate() > uber.getEstimate())
    {
        cout << "Go with Uber";
    }
    else
    {
        cout << "Go with Ola";
    }
}

int main()
{
    int hr, distance;
    string pName;
    cout << "Enter your name: ";
    cin >> pName;
    cout << "Enter dist: ";
    cin >> distance;
    cout << "Enter hour: ";
    cin >> hr;
    Ola a(distance, hr, pName);
    Uber b(distance, hr, pName);
    compare(a, b);
}
