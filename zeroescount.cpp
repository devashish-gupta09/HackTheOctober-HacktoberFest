#include <bits/stdc++.h>
using namespace std;


int zeroes(int n)
{
    int zero = 0;
    for (int i = 1; i <= n; i++)
    {
        if ((i % 5 == 0 && i % 10 != 0) || i % 10 == 0)
            zero++;
    }
    return zero;
}

int main()
{
    int n;
    cout << "\nenter: ";
    cin >> n;

    cout << zeroes(n);
    return 0;
}
