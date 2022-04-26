#include <bits/stdc++.h>

using namespace std;

class Wallet
{
    float money;

public:
    Wallet()
    {
        money = 0;
    }
    friend void addMoney(Wallet &);
    friend void withdraw(Wallet &);
    friend void getBalance(Wallet &);
};

void addMoney(Wallet &w)
{
    int amt;
    cout << "Enter amount: ";
    cin >> amt;
    w.money += amt;
    cout << "Done\n";
}

void withdraw(Wallet &w)
{
    int amt;
    cout << "Enter amount: ";
    cin >> amt;
    w.money -= amt;
    cout << "Done\n";
}

void getBalance(Wallet &w)
{
    cout << "Balance: " << w.money << "\n";
}

int main()
{
    Wallet w;
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
            cout << "2 - Withdraw money\n";
            cout << "3 - Check balance\n";
            break;
        }
        case 1:
        {
            addMoney(w);
            break;
        }
        case 2:
        {
            withdraw(w);
            break;
        }
        case 3:
            getBalance(w);
        }
    } while (choice != -1);
}