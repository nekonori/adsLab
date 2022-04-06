#include <bits/stdc++.h>

using namespace std;

#define deb(x) cout << #x << " " << x
#define pln(x) cout<<x<<"\n";

class TwoNums
{
    int a, b;

public:
    TwoNums() {}
    TwoNums(int a, int b) : a(a), b(b) {}
    pair<int, int> get()
    {
        return {a,b};
    }
    void set(){
        printf("Enter a b: ");
        cin>>a>>b;
    }
    int add(){
        cout<<a<<"+"<<b<<"="<<a + b<<"\n";
        return a + b;
    }
    int sub(){
        cout<<a<<"-"<<b<<"="<<a - b<<"\n";
        return a - b;
    }
};

int main()
{
    TwoNums n1 = TwoNums();
    TwoNums n2 = TwoNums(2, 3);
    n1.set();
    n1.add();
    n2.sub();
    return 0;
}