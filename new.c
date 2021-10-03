#include <stdio.h>
#include <math.h>

#define MAX 10

int x[MAX];

int Place(int k, int i)
{
    for (int j = 1; j <= k - 1; j++)
    {
        if (x[j] == i || (abs(x[j] - i) == abs(j - k)))
        {
            return 0;
        }
    }
    return 1;
}

void display(int n)
{
    printf("Arrangement\n");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (x[i] != j)
            {
                printf(".");
            }
            else
            {
                printf("Q");
            }
        }
        printf("\n");
    }
}

void nqueens(int k, int n)
{

    for (int i = 1; i <= n; i++)
    {
        if (Place(k, i))
        {
            x[k] = i;
            if (k == n)
            {
                display(n);
            }
            else
            {
                nqueens(k + 1, n);
            }
        }
    }
}

int main()
{
    int n = 0;
    printf("Enter the size of board\n");
    scanf("%d", &n);
    nqueens(1, n);
    return 0;
}