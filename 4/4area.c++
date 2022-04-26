#include <bits/stdc++.h>

using namespace std;

class Shape{
    protected:
        int length;
    public:
        Shape(int l):length(l){}
};

class Circle:public Shape{
    public:
        Circle(int radius):Shape(radius){};
        void area(){cout<<"Area: "<<3.14*length*length<<endl;}
        void perimeter(){cout<<"Perimeter: "<<2*3.14*length<<endl;}
};

class Sphere:public Circle{
    public:
        void surfaceArea(){cout<<"Surface area: "<<4*3.14*length*length<<endl;}
        Sphere(int radius):Circle(radius){};
};

int main(){
    Circle c(4);
    c.area();
    c.perimeter();
    Sphere s(19);
    s.surfaceArea();

    return 0;
}