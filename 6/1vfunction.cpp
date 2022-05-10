#include <bits/stdc++.h>

using namespace std;

class Bank
{
protected:
    int balance;
    virtual int getBalance() = 0;
    virtual void deposit(int amt) = 0;

public:
    Bank()
    {
        balance = 0;
    }
};

class ICICI : protected Bank
{
public:
    int getBalance()
    {
        return balance;
    }
    void deposit(int amt)
    {
        balance += amt;
    }
};

class IOB : protected Bank
{
public:
    int getBalance()
    {
        return balance;
    }
    void deposit(int amt)
    {
        balance += amt;
    }
};

class SBI : protected Bank
{
public:
    int getBalance()
    {
        return balance;
    }
    void deposit(int amt)
    {
        balance += amt;
    }
};

int main()
{
    SBI sbi;
    ICICI icici;
    IOB iob;
    sbi.deposit(10000);
    icici.deposit(15000);
    iob.deposit(20000);
    cout << "Deposited 10k in SBI, 15k in ICICI, 20k in IOB\n";
    cout << "Updated balance:\n";
    cout << "SBI: " << sbi.getBalance() << endl;
    cout << "ICICI: " << icici.getBalance() << endl;
    cout << "IOB: " << iob.getBalance() << endl;
    return 0;
}