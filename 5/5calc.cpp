#include <bits/stdc++.h>
#define deb(x) cout<<#x<<"="<<x<<" ";
using namespace std;

template <typename T> T calc(T x, T y, char op)
{
    if(op=='+') return x+y;
    if(op=='-') return x-y;
    if(op=='*') return x*y;
    return x/y;
}

int main()
{
	int choice, a, b;
	do{
	    cout<<"0 for help >>";
	    cin>>choice;
	    if(choice==-1) return 0;
	    if(choice == 0){
            cout<<"1 -> calculate"<<endl;
            cout<<"-1 -> exit"<<endl;
        } else {
            cout<<"Num 1: "; cin>>a;
            cout<<"Num 2: "; cin>>b;
            cout<<a<<" + "<<b<<" = "<<calc(a,b,'+')<<endl;
            cout<<a<<" - "<<b<<" = "<<calc(a,b,'-')<<endl;
            cout<<a<<" * "<<b<<" = "<<calc(a,b,'*')<<endl;
            cout<<a<<" / "<<b<<" = "<<calc(a,b,'/')<<endl;
        }
	} while(choice != -1);
	return 0;
}
