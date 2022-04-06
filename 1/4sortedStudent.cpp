#include <bits/stdc++.h>

using namespace std;

#define deb(x) cout << #x << " " << x
#define pln(x) cout << x << "\n";

class Student
{
    int roll;
    string name;

public:
    void set(){
        cin>>roll>>name;
    }
    void get(){
        cout<<"\nRoll: "<<roll<<" Name: "<<name<<"\n";
    }
    string getName(){
        return name;
    }
};

void bubbleSort(vector<Student> &arr){
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr.size()-1;j++){
            if(arr[j].getName().compare((arr[j+1]).getName())>0){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}


int main(){
    int count = 5;
    vector<Student> arr(count, Student());
    cout<<"Enter roll, name "<<count<<" times\n";
    for (int i = 0; i < count; i++) arr[i].set();
    printf("Sorted order of students: ");
    bubbleSort(arr);
    for(auto st: arr) st.get();
    return 0;
}