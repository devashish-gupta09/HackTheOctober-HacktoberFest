#include <bits/stdc++.h>
using namespace std;

bool palindrome(int n)
{
    int rev = 0, org = n;
    while (n != 0)
    {
        rev = rev * 10 + (n % 10);
        n /= 10;
    }
    return (rev == org);
}

int main()
{
    int n;
    cout << "\nenter: ";
    cin >> n;

    if (palindrome(n) == 1)
        cout << "palindrome";

    else
        cout << "not palindrome";
    return 0;
}
