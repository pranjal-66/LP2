#include <iostream>
using namespace std;

#define N 4   // Change to 8 for 8-Queens

int board[N][N];

// Print Board
void printBoard()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
    cout << "-------------------" << endl;
}

// Check Safe Position
bool isSafe(int row, int col)
{
    int i, j;

    // Check row left side
    for (i = 0; i < col; i++)
        if (board[row][i] == 1)
            return false;

    // Upper diagonal
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1)
            return false;

    // Lower diagonal
    for (i = row, j = col; i < N && j >= 0; i++, j--)
        if (board[i][j] == 1)
            return false;

    return true;
}

// Solve using Backtracking
bool solveNQ(int col)
{
    // All queens placed
    if (col >= N)
        return true;

    for (int i = 0; i < N; i++)
    {
        cout << "Trying Queen at Row " << i << " Column " << col << endl;

        if (isSafe(i, col))
        {
            board[i][col] = 1;

            cout << "Placed Queen at (" << i << "," << col << ")" << endl;
            printBoard();

            if (solveNQ(col + 1))
                return true;

            // Backtrack
            board[i][col] = 0;
            cout << "Backtracking from (" << i << "," << col << ")" << endl;
            printBoard();
        }
        else
        {
            cout << "Position (" << i << "," << col << ") is not safe" << endl;
            cout << "-------------------" << endl;
        }
    }

    return false;
}

int main()
{
    // Initialize board
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = 0;

    if (solveNQ(0))
    {
        cout << "Final Solution for " << N << "-Queens Problem:\n";
        printBoard();
    }
    else
    {
        cout << "Solution does not exist";
    }

    return 0;
}
