#include <bits/stdc++.h>

using namespace std;

#define deb(x) cout << #x << " " << x
#define pln(x) cout << x << "\n";

class Rectangle{
    double width, height;
    public:
    Rectangle(){}
    Rectangle(double width, double height):width(width),height(height){}
    double area(){
        return width*height;
    }
    void get(){
        cin>>width>>height;
    }
};

int main(){
    Rectangle r = Rectangle();
    printf("Enter width, height of rect1: ");
    r.get();
    double w, h;
    printf("Enter width, height of rect2: ");
    cin>>w>>h;
    Rectangle r1 = Rectangle(w, h);
    pln("Area of rectange 1: " + to_string(r.area()));
    pln("Area of rectange 2: " + to_string(r1.area()));
    return 0;
}