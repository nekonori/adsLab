#include <bits/stdc++.h>

using namespace std;

#define deb(x) cout << #x << " " << x
#define pln(x) cout << x << "\n";

class Student
{
    int roll;
    double cgpa;
    double marks;

public:
    Student(){}
    Student(int roll, double marks):roll(roll),marks(marks){}
    double calcCgpa(){
        cgpa = marks / 10;
        return cgpa;
    }
    void get(){
        printf("Enter student mark: ");
        cin>>marks;
    }
};

int main()
{
    Student s1 = Student(3, 99);
    Student s2 = Student();
    s2.get();
    printf("Student 1 cgpa: ");
    pln(s1.calcCgpa());
    printf("Student 2 cgpa: ");
    pln(s2.calcCgpa());
    return 0;
}