#include <bits/stdc++.h>

using namespace std;

class Bank{
    double i = 0.08;
    public:
        double interest(){
            return i;
        }
};

class SBI:public Bank{
    double i = 0.07;
    public:
    double interest(){
        return i;
    }
    double calcInterest(double fd){
        return i * fd;
    }
};

class ICICI:public Bank{
    double i = 0.075;
    public:
    double interest(){
        return i;
    }
    double calcInterest(double fd){
        return i * fd;
    }
};


int main()
{
    SBI* s = new SBI;
    ICICI* i = new ICICI;
    cout<<"SBI interest: "<<s->interest()*100<<"%"<<endl;
    cout<<"ICICI interest: "<<i->interest()*100<<"%"<<endl;
    double fd; cout<<"Enter fixed deposit amount: ";
    cin>>fd;
    cout<<"interest for FD at SBI: "<<s->calcInterest(fd)<<endl;
    cout<<"interest for FD at ICICI: "<<i->calcInterest(fd);
    return 0;
}
