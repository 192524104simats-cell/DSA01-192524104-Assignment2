
#include <iostream>
using namespace std;

class Time
{
    int h, m;

public:
    Time(int hh, int mm) : h(hh), m(mm) {}

    friend int minutesBetween(const Time& a, const Time& b);
    friend bool earlier(const Time& a, const Time& b);
};

inline int minutesBetween(const Time& a, const Time& b)
{
    int time1 = a.h * 60 + a.m;
    int time2 = b.h * 60 + b.m;

    int diff = time1 - time2;

    if (diff < 0)
        diff = -diff;

    return diff;
}

inline bool earlier(const Time& a, const Time& b)
{
    if (a.h < b.h)
        return true;

    if (a.h == b.h && a.m < b.m)
        return true;

    return false;
}

int main()
{
    Time departure(9, 45), arrival(13, 10);

    cout << minutesBetween(departure, arrival) << ' '
         << boolalpha << earlier(arrival, departure) << '\n';

    Time t1(11, 30), t2(12, 15);
    cout << minutesBetween(t1, t2) << ' '
         << earlier(t1, t2) << '\n';

    Time t3(10, 30), t4(10, 30);
    cout << minutesBetween(t3, t4) << ' '
         << earlier(t3, t4) << '\n';

    return 0;
}
