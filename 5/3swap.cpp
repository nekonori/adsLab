#include <iostream>
using namespace std;

#define deb(x) cout<<#x<<"="<<x<<"\n";

template <typename T> void swapNums(T &x, T &y)
{
    T temp = x;
    x = y;
    y = temp;
}

int main()
{
    int a = 10, b = 20;
    float c = 1.2, d = 3.4;
    cout<<"Initially: ";
    deb(a); deb(b); deb(c); deb(d);
    swapNums(a, b); swapNums(c,d);
    cout<<"After swap: ";
    deb(a); deb(b); deb(c); deb(d);
	return 0;
}
