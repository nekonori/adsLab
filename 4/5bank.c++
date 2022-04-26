#include <bits/stdc++.h>

using namespace std;

class Bank
{
    int id;
};

class Account : public Bank
{
    int accountId;
    int balance;

public:
    Account(int accountId)
    {
        this->accountId = accountId;
        balance = 0;
    }
    void deposit()
    {
        int amt;
        cout << "Enter amount: ";
        cin >> amt;
        balance += amt;
    }
    void calcInterest()
    {
        cout << "Interest is " << 0.05 * balance << "\n";
    }
};

int main()
{
    Account act(1);
    int choice;
    do
    {
        printf("0 for help >>");
        cin >> choice;
        switch (choice)
        {
        case 0:
        {
            cout << "1 - Add money\n";
            cout << "2 - Calculate interest\n";
            break;
        }
        case 1:
        {
            act.deposit();
            break;
        }
        case 2:
        {
            act.calcInterest();
            break;
        }
        }
    } while (choice != -1);
}