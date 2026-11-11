
#include <iostream>
using namespace std;

class SavingsAccount
{
    int accountNumber;
    double balance;
    double transactions[10];
    int count, front, rear;

public:
    SavingsAccount(int acc, double bal)
    {
        accountNumber = acc;
        balance = bal;
        count = 0;
        front = 0;
        rear = -1;
    }

    void addTransaction(double amount)
    {
        if (count == 10)
        {
            front = (front + 1) % 10;
            count--;
        }

        rear = (rear + 1) % 10;
        transactions[rear] = amount;
        count++;
    }

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

    void miniStatement()
    {
        cout << "Account Number: " << accountNumber << '\n';
        cout << "Balance: " << balance << '\n';
        cout << "Last Transactions:\n";

        for (int i = 0; i < count; i++)
            cout << transactions[(front + i) % 10] << '\n';
    }
};

int main()
{
    SavingsAccount account(101, 5000);

    for (int i = 1; i <= 12; i++)
{
    account.deposit(i * 100);
}

    account.miniStatement();

    return 0;
}
