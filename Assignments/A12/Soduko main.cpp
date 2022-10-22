
#include <bits/stdc++.h>
using namespace std;
bool findNextStar(char m[4][4], int &row, int &col)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
            if (m[i][j] == '*')
            {
                row = i;
                col = j;
                return true;
            }
    }
    return false;
}

bool isSafe(char m[4][4], int row, int col, char num)
{
    // check the row
    for (int i = 0; i < 4; i++)
    {
        if (m[row][i] == num)
            return false;
    }

    // check the column
    for (int i = 0; i < 4; i++)
    {
        if (m[i][col] == num)
            return false;
    }
    col = col - col % 2;
    row = row - row % 2;
	
	// check the 2x2 box
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (m[i+row][j+col]==num)
            {
                return false;
            }
        }
    }
    return true;
}
bool solve(char m[4][4])
{
    int row, col;
    if (!findNextStar(m, row, col))
    {
        return true;
    }

    for (int i = 1; i <= 4; i++)
    {
        if (isSafe(m,row,col,char('0'+i)))
        {
            m[row][col]=i+'0';

            if( solve(m) )
            return true;

            m[row][col]='*';

        }
    }
    return false;
}
int main()
{
    
    int T;
     cin >> T;
    char map[4][4];
    int c = 1;
    while (T--)
    {
        int counter = 0;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                cin >> map[i][j];
                if (map[i][j] == '*')
                    counter++;
            }
        }
        solve(map);

        cout << "Case #" << c++ << ":\n";
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                cout<<map[i][j];
            }
            cout << endl;
        }
     }

    return 0;
}
