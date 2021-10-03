
#include <iostream>
using namespace std;
int m, n, k;
int count = 0;
void makeBoard(char **board)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            board[i][j] = '_';
        }
    }
}

void displayBoard(char **board)
{
    cout << endl
         << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << " " << board[i][j] << " ";
        }
        cout << endl;
    }
}

void attack(int i, int j, char a,
            char **board)
{

    if ((i + 2) < m && (j - 1) >= 0)
    {
        board[i + 2][j - 1] = a;
    }
    if ((i - 2) >= 0 && (j - 1) >= 0)
    {
        board[i - 2][j - 1] = a;
    }
    if ((i + 2) < m && (j + 1) < n)
    {
        board[i + 2][j + 1] = a;
    }
    if ((i - 2) >= 0 && (j + 1) < n)
    {
        board[i - 2][j + 1] = a;
    }
    if ((i + 1) < m && (j + 2) < n)
    {
        board[i + 1][j + 2] = a;
    }
    if ((i - 1) >= 0 && (j + 2) < n)
    {
        board[i - 1][j + 2] = a;
    }
    if ((i + 1) < m && (j - 2) >= 0)
    {
        board[i + 1][j - 2] = a;
    }
    if ((i - 1) >= 0 && (j - 2) >= 0)
    {
        board[i - 1][j - 2] = a;
    }
}

bool canPlace(int i, int j, char **board)
{
    if (board[i][j] == '_')
        return true;
    else
        return false;
}

void place(int i, int j, char k, char a,
           char **board, char **new_board)
{
    for (int y = 0; y < m; y++)
    {
        for (int z = 0; z < n; z++)
        {
            new_board[y][z] = board[y][z];
        }
    }
    new_board[i][j] = k;
    attack(i, j, a, new_board);
}

void kkn(int k, int sti, int stj, char **board)
{
    if (k == 0)
    {
        displayBoard(board);
        count++;
    }
    else
    {
        for (int i = sti; i < m; i++)
        {
            for (int j = stj; j < n; j++)
            {

                if (canPlace(i, j, board))
                {

                    char **new_board = new char *[m];
                    for (int x = 0; x < m; x++)
                    {
                        new_board[x] = new char[n];
                    }
                    place(i, j, 'K', 'A', board, new_board);

                    kkn(k - 1, i, j, new_board);

                    for (int x = 0; x < m; x++)
                    {
                        delete[] new_board[x];
                    }
                    delete[] new_board;
                }
            }
            stj = 0;
        }
    }
}

int main()
{
    m = 4, n = 3, k = 6;

    char **board = new char *[m];
    for (int i = 0; i < m; i++)
    {
        board[i] = new char[n];
    }

    makeBoard(board);

    kkn(k, 0, 0, board);

    cout << endl
         << "Total number of solutions : "
         << count;
    return 0;
}
