#include <bits/stdc++.h>

using namespace std;

class Date
{
    int day, month, year;

public:
    Date(int day, int month, int year) : day(day), month(month), year(year) {}
    Date operator++()
    {
        day++;        
        if (day > 31)
        {
            day = 1;
            month++;
            if (month > 12)
            {
                month = 1;
                year++;
            }
        }
    }
    Date operator--(int)
    {
        day--;
        if (day < 1)
        {
            day = 31;
            month--;
            if (month < 1)
            {
                month = 12;
                year--;
            }
        }
    }
    void print()
    {
        cout << day << "-" << month << "-" << year << "\n";
    }
};

int main()
{
    Date some = Date(31, 12, 2021);
    printf("Initial Date: ");
    some.print();
    ++some;
    printf("After incrementing: ");
    some.print();
    some--;
    printf("After decrementing: ");
    some.print();
    some--;
    printf("After decrementing once again: ");
    some.print();
}