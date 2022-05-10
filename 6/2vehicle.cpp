#include <bits/stdc++.h>

using namespace std;

class Vehicle
{
public:
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
    Ola(double dist, int h)
    {
        distance = dist;
        hour = h;
        peakHourFee = 20;
    }
};
class Uber : public Vehicle
{
public:
    Uber(double dist, int h)
    {
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
    cout << "Enter dist: ";
    cin >> distance;
    cout << "Enter hour: ";
    cin >> hr;
    Ola a(distance, hr);
    Uber b(distance, hr);
    compare(a, b);
}
