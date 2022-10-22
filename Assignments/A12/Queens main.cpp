#include <iostream>
#include <cmath>
#include <string>
using namespace std;
int queen[8], po[8];
bool isSafe(int n, int r)
{
    for (int i = 0; i < n; i++)
    {
        if (r == po[i]) // check if the queens can attack each other horizontally
            return false;
        if (abs(n - i) == abs(r - po[i])) // check if the queens can attack each other orthogonally
            return false;                 // we did it by taking the difference between the columns and the rows
    }
    return true;
}
int findMinimumMoves(int col)
{
    if (col >= 8)
    {
        return 0;
    }
    int minimum = 999999;
    for (int i = 0; i < 8; i++)
    {
        if (isSafe(col, i))
        {
            po[col] = i;
            if (i == queen[col])
                minimum = min(minimum, findMinimumMoves(col + 1)); // if the place is = place of the queen then we don't have to make any move
            else
                minimum = min(minimum, 1 + findMinimumMoves(col + 1));
        }
    }
    return minimum;
}

int main()
{

    int counter = 0;

    while (1)
    {

        for (int i = 0; i < 8; i++)
        {
            if (cin >> queen[i])
                ;
            else
                return 0;
            po[i] = --queen[i];
        }

        cout << "Case " << ++counter << ": " << findMinimumMoves(0) << endl;
    }
    cout << endl;
    return 0;
}
