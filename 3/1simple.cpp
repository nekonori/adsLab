#include <bits/stdc++.h>
#define pln(x) cout<<x<<"\n";
using namespace std;

void print(char c){
    pln(c);
}
void print(int c){
    pln(c);
}
void print(float c){
    pln(c);
}
void calc(int a){
    pln(a+1);
}
void calc(int a=10, int b=20){
    pln(a+b);
}
void incre(int &a){
    a++;
}
void incre(int a){
    a++;
}
int main(){
    print('c');
    print(1);
    // ambiguity err
    // print(2.1);
    print(2.1f);
    // ambiguity err
    // calc(10);
    calc(1,3);
    // ambiguity err
    // int s = 10;
    // incre(s);
}