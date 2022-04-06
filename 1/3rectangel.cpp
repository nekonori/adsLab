#include <bits/stdc++.h>

using namespace std;

#define deb(x) cout << #x << " " << x
#define pln(x) cout << x << "\n";

class Rectangle{
    double width, height;
    public:
    double area(){
        return width*height;
    }
    void get(){
        cin>>width>>height;
    }
};

int main(){
    Rectangle r = Rectangle();
    printf("Enter width, height: ");
    r.get();
    pln("Area of rectange: " + to_string(r.area()));
    return 0;
}