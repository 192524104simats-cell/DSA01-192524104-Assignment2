
#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

class Time
{
    int h, m;

public:
    Time(int hh, int mm) : h(hh), m(mm) {}

    friend int minutesBetweenInline(const Time&, const Time&);
    friend int minutesBetweenNoInline(const Time&, const Time&);
};

inline int minutesBetweenInline(const Time& a, const Time& b)
{
    int x = a.h * 60 + a.m;
    int y = b.h * 60 + b.m;
    return (x > y) ? x - y : y - x;
}

__attribute__((noinline))
int minutesBetweenNoInline(const Time& a, const Time& b)
{
    int x = a.h * 60 + a.m;
    int y = b.h * 60 + b.m;
    return (x > y) ? x - y : y - x;
}

int main()
{
    volatile int input = 0;
    long long result1 = 0, result2 = 0;

    auto start1 = high_resolution_clock::now();

    for (int i = 0; i < 10000000; i++)
    {
        input = i % 60;
        int x = input;
        Time a(9, x), b(13, (x + 10) % 60);
        result1 += minutesBetweenInline(a, b);
    }

    auto stop1 = high_resolution_clock::now();

    auto start2 = high_resolution_clock::now();

    for (int i = 0; i < 10000000; i++)
    {
        input = i % 60;
        int x = input;
        Time a(9, x), b(13, (x + 10) % 60);
        result2 += minutesBetweenNoInline(a, b);
    }

    auto stop2 = high_resolution_clock::now();

    cout << "Inline result: " << result1 << '\n';
    cout << "Inline time: "
         << duration_cast<microseconds>(stop1 - start1).count()
         << " microseconds\n";

    cout << "Non-inline result: " << result2 << '\n';
    cout << "Non-inline time: "
         << duration_cast<microseconds>(stop2 - start2).count()
         << " microseconds\n";

    return 0;
}
