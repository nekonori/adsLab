#include <bits/stdc++.h>

using namespace std;

class Animal{
    int legs;
    public:
    static int count;
    // Animal (int legs):legs(legs){}
    Animal(int legsi){
        count++;
        legs = legsi;
    }
};

int Animal::count = 0;

int main(){
    Animal dog = Animal(4);
    Animal lion = Animal(4);
    Animal snake = Animal(0);
    cout<<Animal::count<<"\n";
    return 0;
}