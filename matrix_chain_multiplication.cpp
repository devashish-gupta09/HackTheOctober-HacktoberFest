#include <iostream>
#include <climits>
using namespace std;
int n;
int *p, **m, **s;
void matrixChainOrder(int p[], int n)
{
    for (int i = 1; i <= n; i++)
        m[i][i] = 0;
    for (int l = 2; l <= n; l++)
    {
        for (int i = 1; i <= n - l + 1; i++)
        {
            int j = i + l - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++)
            {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}

void printOptParens(int i, int j)
{
    if (i == j)
        cout << "A" << i;
    else
    {
        cout << "(";
        printOptParens(i, s[i][j]);
        printOptParens(s[i][j] + 1, j);
        cout << ")";
    }
}

// Driver code
int main()
{
    cout << "Enter the no. of matrices to be entered: ";
    cin >> n;
    p = new int[n];
    cout << "Enter the dimensions of matrices:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "A" << i + 1 << ":" << endl;
        cout << "Row dimension: ";
        cin >> p[i];
        cout << "Column dimension: ";
        cin >> p[i + 1];
    }
    cout << "Inputted matrices are :\n";
    for (int i = 0; i < n; i++)
        cout << "A" << i + 1 << " : " << p[i] << " x " << p[i + 1] << endl;
    cout << endl;
    m = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 0; i < n + 1; i++)
        m[i] = (int *)malloc((n + 1) * sizeof(int));
    s = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 0; i < n + 1; i++)
        s[i] = (int *)malloc((n + 1) * sizeof(int));
    matrixChainOrder(p, n);
    printOptParens(1, n);
    cout << endl;
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (i < j)
                cout << m[i][j] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }

    cout << endl;
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (i < j)
                cout << s[i][j] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
    cout << m[1][n] << endl;

    return 0;
}