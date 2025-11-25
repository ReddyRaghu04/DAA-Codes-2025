#include <iostream>
using namespace std;
bool isvalid(int board[9][9], int r, int c, int n)
{
    // row validate
    for (int j = 0; j < 9; j++)
    {
        if (board[r][j] == n)
        {
            return false;
        }
    }
    // column validate
    for (int i = 0; i < 9; i++)
    {
        if (board[i][c] == n)
        {
            return false;
        }
    }

    int sr = r - r % 3;
    int sc = c - c % 3;
    for (int i = sr; i < sr + 3; i++)
    {
        for (int j = sc; j < sc + 3; j++)
        {
            if (board[i][j] == n)
            {
                return false;
            }
        }
    }
    return true;
}
bool solveboard(int board[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == 0)
            {
                for (int num = 1; num < 10; num++)
                {
                    if (isvalid(board, i, j, num))
                    {
                        board[i][j] = num;
                        if (solveboard(board))
                        {
                            return true;
                        }
                        board[i][j] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}
void printboard(int board[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << board[i][j] << " ";
            if ((j + 1) % 3 == 0)
                cout << "| ";
        }
        if ((i + 1) % 3 == 0)
        {
            cout << endl
                 << "-------------------------" << endl;
        }
        else
        {
            cout << endl;
        }
    }
}
int main()
{
    int board[9][9] = {
        {3, 0, 0, 1, 0, 0, 0, 8, 0},
        {0, 0, 0, 0, 6, 0, 0, 0, 4},
        {5, 6, 0, 2, 0, 0, 0, 0, 0},
        {0, 3, 0, 0, 0, 8, 1, 0, 2},
        {6, 0, 0, 0, 0, 0, 0, 7, 0},
        {0, 0, 0, 0, 0, 4, 5, 0, 0},
        {0, 0, 1, 0, 0, 9, 7, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 9, 0},
        {0, 2, 0, 0, 8, 0, 0, 0, 0},
    };
    printboard(board);
    if (solveboard(board))
    {
        cout << endl
             << "Solved" << endl;
        printboard(board);
    }
    else
    {
        cout << endl
             << "No suitable solution found" << endl;
    }
    return 0;
}