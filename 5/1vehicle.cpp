#include <bits/stdc++.h>

using namespace std;

class Vehicle{
    public:
        void message(){
            cout<<"This is a vehicle\n";
        }
        virtual void fare(){}
};

class Car:public Vehicle{
    public:
    void message(){
            cout<<"This is a car. ";
    }
    void fare(){
        cout<<"Fare for car: ₹100\n";
    }
};

class Bus:public Vehicle{
    public:
    void message(){
            cout<<"This is a bus. ";
    }
    void fare(){
        cout<<"Fare for bus: ₹50\n";
    }
};

class Boat:public Vehicle{
    public:
    void message(){
            cout<<"This is a boat. ";
    }
    void fare(){
        cout<<"Fare for boat: ₹250\n";
    }
};

int main()
{
    Vehicle v; Car c; Boat b; Bus bus;
    v.message();
    c.message(); c.fare();
    b.message(); b.fare();
    bus.message(); bus.fare();
    return 0;
}
