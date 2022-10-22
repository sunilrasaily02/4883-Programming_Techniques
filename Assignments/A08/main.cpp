#include <iostream>
#include <vector>
using namespace std;

bool attack(char atk, char def)
{
    if (atk == 'R')
        return def == 'S' ? true : false;
    else if (atk == 'P')
        return def == 'R' ? true : false;
    else if (atk == 'S')
        return def == 'P' ? true : false;
}

// Driver program
int main()
{
    int test;
    int row, col, days;
    cin >> test;

    char temp;
    for (int i = 0; i < test; i++)
    {
        if (i > 0 && i <= test - 1)
            cout << endl;
        vector<string> grid;
        cin >> row >> col >> days;
        for (int x = 0; x < row; x++)
        {
            string str;
            cin >> str;
            grid.push_back(str);
        }

        vector<string> v(grid);
        for (int d = 0; d < days; d++)
        {

            for (int x = 0; x < row; x++)
            {
                for (int y = 0; y < col; y++)
                {
                    if (x - 1 >= 0)
                    {
                        if (attack(grid[x][y], grid[x - 1][y]))
                            v[x - 1][y] = grid[x][y];
                    }
                    if (x + 1 < row)
                    {
                        if (attack(grid[x][y], grid[x + 1][y]))
                            v[x + 1][y] = grid[x][y];
                    }
                    if (y - 1 >= 0)
                    {
                        if (attack(grid[x][y], grid[x][y - 1]))
                            v[x][y - 1] = grid[x][y];
                    }
                    if (y + 1 < col)
                    {
                        if (attack(grid[x][y], grid[x][y + 1]))
                            v[x][y + 1] = grid[x][y];
                    }
                }
            }
            grid = v;
        }
        for (int x = 0; x < row; x++)
            cout << grid[x] << endl;
    }

    return 0;
}
