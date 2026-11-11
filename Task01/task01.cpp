
#include <iostream>
using namespace std;

// Call by value
void applyByValue(long long fee, int percent)
{
    fee = fee - fee * percent / 100;
}

// Call by reference
void applyByReference(long long& fee, int percent)
{
    fee = fee - fee * percent / 100;
}

// Call by pointer
void applyByPointer(long long* fee, int percent)
{
    *fee = *fee - *fee * percent / 100;
}

// Return the new fee
long long applyAndReturn(long long fee, int percent)
{
    return fee - fee * percent / 100;
}

// Given prediction program
void change(int a, int& b, int* c)
{
    a += 10;
    b += 10;
    *c += 10;
}

int& bigger(int& p, int& q)
{
    return p > q ? p : q;
}

void show(int x, int y = 5, int z = 10)
{
    cout << x + y + z << ' ';
}

int main()
{
    int a = 1, b = 2, c = 3;

    change(a, b, &c);
    cout << a << ' ' << b << ' ' << c << '\n';

    bigger(a, c) = 100;
    cout << a << ' ' << c << '\n';

    show(1);
    show(1, 2);
    show(1, 2, 3);
    cout << '\n';

    long long fee1 = 45000;
    long long fee2 = 45000;
    long long fee3 = 45000;
    long long fee4 = 45000;

    applyByValue(fee1, 10);
    applyByReference(fee2, 10);
    applyByPointer(&fee3, 10);
    fee4 = applyAndReturn(fee4, 10);

    cout << "Call by value: " << fee1 << '\n';
    cout << "Call by reference: " << fee2 << '\n';
    cout << "Call by pointer: " << fee3 << '\n';
    cout << "Return new fee: " << fee4 << '\n';

    return 0;
}
