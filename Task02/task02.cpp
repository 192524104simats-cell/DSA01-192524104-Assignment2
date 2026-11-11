#include <iostream>
#include <vector>
using namespace std;

// Return reference to highest mark
int& highestMark(int marks[], int n)
{
    int maxIndex = 0;

    for (int i = 1; i < n; i++)
    {
        if (marks[i] > marks[maxIndex])
            maxIndex = i;
    }

    return marks[maxIndex];
}

// Return a const reference
const int& highestMarkConst(int marks[], int n)
{
    int maxIndex = 0;

    for (int i = 1; i < n; i++)
    {
        if (marks[i] > marks[maxIndex])
            maxIndex = i;
    }

    return marks[maxIndex];
}

// Return a copy
int highestMarkCopy(int marks[], int n)
{
    int maxIndex = 0;

    for (int i = 1; i < n; i++)
    {
        if (marks[i] > marks[maxIndex])
            maxIndex = i;
    }

    return marks[maxIndex];
}

// Dangerous: returning reference to a local variable
int& dangerousFunction()
{
    int x = 50;
    return x;
}

int main()
{
    int marks[5] = {70, 85, 90, 65, 80};

    cout << "Original highest mark: "
         << highestMark(marks, 5) << '\n';

    highestMark(marks, 5) += 2;

    cout << "After moderation: "
         << highestMark(marks, 5) << '\n';

    cout << "Highest mark as copy: "
         << highestMarkCopy(marks, 5) << '\n';

    cout << "Highest mark using const reference: "
         << highestMarkConst(marks, 5) << '\n';

    return 0;
}