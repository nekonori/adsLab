#include <bits/stdc++.h>

using namespace std;

class Book{
    string name,author;
    int id, daysBorrowed, fine;
    public:
    friend istream & operator >> (istream &in, Book &b);
    friend ostream & operator << (ostream &out, Book &b);
};

istream & operator >> (istream &in, Book &b){
    cout<<"Book id: ";
    cin>>b.id;
    cout<<"Book title: ";
    cin>>b.name;
    cout<<"Book author: ";
    cin>>b.author;
    b.daysBorrowed = 0;
    b.fine = 0;
}

ostream & operator << (ostream &out, Book &b){
    cout<<"Id: "<<b.id<<"\n";
    cout<<"Title: "<<b.name<<"\n";
    cout<<"Author: "<<b.author;
}

void printHelpMenu(){
    vector<pair<int, string>> helpMenuItems{
       {1, "menu1"},
       {2, "menu2"}
    };
    for(auto x: helpMenuItems){
        cout<<x.first<<" -> "<<x.second<<"\n";
    }
}

int main(){
    int choice;
    do
    {
        printf("0 for help >>");
        cin>>choice;
        switch (choice)
        {
        case 0:
            printHelpMenu();
            break;
        }
    } while (choice!=-1);
}