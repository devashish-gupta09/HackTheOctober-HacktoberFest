#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define ll long long
#define rep(i, a, b) for (int i = a; i < b; i++)

int Length(char *x, char *y, int m, int n)
{
    if (m == 0 || n == 0)
    {
        return 0;
    }

    if (x[m - 1] == y[n - 1])
    {
        return 1 + Length(x, y, m - 1, n - 1);
    }

    else
    {
        return max(Length(x, y, m - 1, n), Length(x, y, m, n - 1));
    }
}

int main()
{
    char x[] = "BCDE";
    char y[] = "ABCD";

    int m = strlen(x);
    int n = strlen(y);

    cout << "Maximun length is " << Length(x, y, m, n);

    return 0;
}