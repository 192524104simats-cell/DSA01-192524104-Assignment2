
#include <iostream>
using namespace std;

class SavingsAccount
{
private:
    int accountNumber;
    double balance;
    double transactions[10];
    int count;

public:
    SavingsAccount(int acc, double bal)
    {
        accountNumber = acc;
        balance = bal;
        count = 0;
    }

    void addTransaction(double amount);

    void deposit(double amount)
    {
        balance += amount;
        addTransaction(amount);
    }

    void withdraw(double amount)
    {
        if (amount <= balance)
        {
            balance -= amount;
            addTransaction(-amount);
        }
        else
        {
            cout << "Insufficient balance\n";
        }
    }

    void miniStatement();
};

void SavingsAccount::addTransaction(double amount)
{
    if (count == 10)
    {
        for (int i = 0; i < 9; i++)
            transactions[i] = transactions[i + 1];

        count = 9;
    }

    transactions[count] = amount;
    count++;
}

void SavingsAccount::miniStatement()
{
    cout << "Account Number: " << accountNumber << '\n';
    cout << "Balance: " << balance << '\n';
    cout << "Last Transactions:\n";

    for (int i = 0; i < count; i++)
        cout << transactions[i] << '\n';
}

int main()
{
    SavingsAccount account(101, 5000);

    account.deposit(1000);
    account.withdraw(500);
    account.deposit(200);

    account.miniStatement();

    return 0;
}
