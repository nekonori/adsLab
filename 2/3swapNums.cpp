#include <bits/stdc++.h>
#define deb(x) cout << #x << " " << x <<"\n"

using namespace std;

void swapVal(int a,int b){
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

void swapRef(int &a, int &b){
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

void swapPointer(int* pa, int *pb){
    *pa = *pa ^ *pb;
    *pb = *pa ^ *pb;
    *pa = *pa ^ *pb;
}

int main(){
    int a = 3, b = 7;
    int *pa = &a, *pb = &b;
    cout<<"Original values\n";
    deb(a); deb(b);
    swapVal(a,b);
    cout<<"Values after swapping by value\n";
    deb(a); deb(b);
    swapRef(a,b);
    cout<<"Values after swapping by reference\n";
    deb(a); deb(b);
    swapPointer(pa, pb);
    cout<<"Values after swapping with pointers\n";
    deb(a); deb(b);
    return 0;
}