#include <bits/stdc++.h>
using namespace std;
class Student
{
public:
    string name;
    string roll;
    int marks;
    Student()
    {
        try
        {

            cout << "Enter student name: ";
            cin >> name;
            cout << "Enter student rollnumber: ";
            cin >> roll;
            if (roll.length() != 10)
            {
                throw 0;
            }
            cout << "Enter student marks: ";
            cin >> marks;
            if (marks < 0 || marks > 100)
            {
                throw 0;
            }
        }
        catch (int x)
        {
            cout << "Invalid roll number" << endl;
            exit(0);
        }
        catch (char y)
        {
            cout << "Invalid marks" << endl;
            exit(0);
        }
    }
    void displayDetails()
    {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << roll << endl;
        cout << "Marks: " << marks << endl;
    }
};
int main()
{
    vector<Student> s;
    int choice;
    while (true)
    {
        cout << ">>";
        cin >> choice;
        if (choice == -1)
        {
            break;
        }
        else
        {
            if (choice == 1)
            {
                Student x;
                s.push_back(x);
            }
            else if (choice == 2)
            {
                for (int i = 0; i < s.size(); i++)
                {
                    s[i].displayDetails();
                }
            }
        }
    }

    return 0;
}
