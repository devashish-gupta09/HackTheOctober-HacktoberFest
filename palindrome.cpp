#include <iostream>
using namespace std;

bool check(int n)
{
    int rev = 0, lastdigit;
    int temp = n;
    while (temp != 0)
    {
        lastdigit = temp % 10;
        rev = rev * 10 + lastdigit;
        temp = temp / 10;
    }
    return (rev == n);
}

int main()
{
    int n;
    cout << "Enter number to check palindrome" << endl;
    cin >> n;
    if (check(n))
    {
        cout << "is a palindrome";
    }
    else
    {
        cout << "is not a palondrome";
    }

    return 0;
}