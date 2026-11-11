#include <iostream>
using namespace std;

struct Parcel
{
    double weight;
};

// Weight in grams
void charge(int grams)
{
    cout << "Integer weight: " << grams << " grams\n";
}

// Weight in kg, with default arguments
void charge(double kg, bool express = false, bool insured = false)
{
    cout << "Weight: " << kg << " kg";

    if (express)
        cout << " Express";

    if (insured)
        cout << " Insured";

    cout << '\n';
}

// Parcel object
void charge(Parcel p)
{
    cout << "Parcel weight: " << p.weight << " kg\n";
}

int main()
{
    Parcel p = {3.5};

    charge(2);
    charge(2.0f);
    charge(2.5);
    charge(500);
    charge(2.0, true);
    charge(p);

    return 0;
}