#include <bits/stdc++.h>
#define deb(x) cout << #x << " " << x <<"\n"

using namespace std;

class Account
{
    int number;
    string name;
    float balance;
public:
    Account(){
        number = rand() % 1000;
        printf("Enter account holder's name: ");
        getchar();
        getline(cin, name);
        balance = 0;
    }
    void printDetails(){
        deb(number);
        deb(name);
        deb(balance);
    }
    int getNumber(){
        return number;
    }
    void deposit(){
        float amt;
        printf("Deposit amount: ");
        cin>>amt;
        balance += amt;
    }
    void withdraw(){
        float amt;
        printf("Withdraw amount: ");
        cin>>amt;
        balance -= amt;
    }
};

vector<Account> accounts;

void printHelp(){
    vector<string> helpMenuItems{
        "Print this help menu",
        "Create a new account",
        "View account details",
        "Deposit money",
        "Withdraw money",
    };
    for (int i = 0; i < helpMenuItems.size(); i++)
    {
        cout<<i<<" -> "<<helpMenuItems[i]<<"\n";
    }
    cout<<"-1 -> exit\n";
}

void createAccount(){
    Account newAct = Account();
    accounts.push_back(newAct);
    printf("Account created successfully\nYour account no: %d\n", newAct.getNumber());
}

int searchAct(){
    int tempId;
    printf("Enter your account no: ");
    cin>>tempId;
    for (int i = 0; i < accounts.size(); i++)
    {
        if(accounts[i].getNumber() == tempId) return i;
    }
    printf("Could not find your account :/\n");
    return -1;
}

void getAccountDetails(){
    int index = searchAct();
    if(index!=-1) accounts[index].printDetails();
}

void depositMoney(){
    int index = searchAct();
    if(index!=-1) accounts[index].deposit();
}

void withdrawMoney(){
    int index = searchAct();
    if(index!=-1) accounts[index].withdraw();
}

int main(){
    int choice = 0;
    do{
        cout<<"0 for help >>";
        cin>>choice;
        // deb(choice);
        switch (choice)
        {
        case 0:
            printHelp(); 
            break;
        case 1:
            createAccount();
            break;
        case 2:
            getAccountDetails();
            break;
        case 3:
            depositMoney();
            break;
        case 4:
            withdrawMoney();
            break;
        default:
            break;
        }
    } while (choice != -1);
    return 0;
}