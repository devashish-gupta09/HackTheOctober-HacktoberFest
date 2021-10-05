#include <bits/stdc++.h>
using namespace std;

int maxof3(int a, int b, int c)
{
    int max_;
    if (a > b && a > c)
        max_ = a;
    else if (b > c)
        max_ = b;
    else
        max_ = c;
}

int max_pieces(int n, int a, int b, int c)
{
    if (n == 0)
        return 0;
    if (n < 0)
        return -1;

    int res = maxof3(max_pieces(n - a, a, b, c), max_pieces(n - b, a, b, c), max_pieces(n - c, a, b, c));

    if (res == -1)
        return -1;
    return res + 1;
}

int main()
{
    int n, a, b, c;
    cin >> n >> a >> b >> c;

    cout << max_pieces(n, a, b, c);

    return 0;
}