#include <bits/stdc++.h>
using namespace std;
class base{
    public:
        void print(){
            cout<<"base print\n";
        }
        void show(){
            cout<<"base show"<<endl;
        }
};
class derived: public base{
    public:
        void print(){
            cout<<"derived print";
        }
        void show(){
            cout<<"derived show";
        }
        
};
int main() {
    derived d;
    d.show();
    return 0;
}
