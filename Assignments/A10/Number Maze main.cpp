#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
using namespace std;

struct node
{
    int x;
    int y;
    int cost;
    node(int x1, int y1, int cost1)
    {
        x = x1;
        y = y1;
        cost = cost1;
    }
    bool operator>(const node &e) const
    {
        return this->cost > e.cost;
    }
};
// Driver program
int main()
{
    int t;
    cin >> t;
    int x, y;
    while (t--)
    {
        int x1;
        cin >> x >> y;
        vector<vector<int>> maze(x, vector<int>(y));
        for (int i = 0; i < x; i++)
            for (int j = 0; j < y; j++)
            {
                cin >> maze[i][j];
            }

        vector<vector<int>> cost(x, vector<int>(y, -1));

        cost[0][0] = maze[0][0];
       
        priority_queue<node, vector<node>, greater<node>> q;

        q.push(node(0, 0, cost[0][0]));
        while (!q.empty())
        {
            node temp = q.top();
            q.pop();
            if (temp.x + 1 < x)
            {
                if (cost[temp.x + 1][temp.y] == -1 || cost[temp.x][temp.y] + maze[temp.x + 1][temp.y] < cost[temp.x + 1][temp.y])
                {
                    //  cout<<"node ("<<temp.x+1<<","<<temp.y<<") added \n";
                    cost[temp.x + 1][temp.y] = cost[temp.x][temp.y] + maze[temp.x + 1][temp.y];
                    q.push(node(temp.x + 1, temp.y, cost[temp.x + 1][temp.y]));
                }
            }
            if (temp.x - 1 >= 0)
            {

                if (cost[temp.x - 1][temp.y] == -1 || (cost[temp.x][temp.y] + maze[temp.x - 1][temp.y] < cost[temp.x - 1][temp.y]))
                {
                    //  cout<<"node ("<<temp.x-1<<","<<temp.y<<") added \n";
                    cost[temp.x - 1][temp.y] = cost[temp.x][temp.y] + maze[temp.x - 1][temp.y];
                    q.push(node(temp.x - 1, temp.y, cost[temp.x - 1][temp.y]));
                }
            }
            if (temp.y + 1 < y)
            {
                if (cost[temp.x][temp.y + 1] == -1 || cost[temp.x][temp.y] + maze[temp.x][temp.y + 1] < cost[temp.x][temp.y + 1])
                {
                    //   cout<<"node ("<<temp.x<<","<<temp.y+1<<") added \n";

                    cost[temp.x][temp.y + 1] = cost[temp.x][temp.y] + maze[temp.x][temp.y + 1];
                    q.push(node(temp.x, temp.y + 1, cost[temp.x][temp.y + 1]));
                }
            }
            if (temp.y - 1 >= 0)
            {
                if (cost[temp.x][temp.y - 1] == -1 || cost[temp.x][temp.y] + maze[temp.x][temp.y - 1] < cost[temp.x][temp.y - 1])
                {
                    // cout<<"node ("<<temp.x<<","<<temp.y-1<<") added \n";
                    cost[temp.x][temp.y - 1] = cost[temp.x][temp.y] + maze[temp.x][temp.y - 1];
                    q.push(node(temp.x, temp.y - 1, cost[temp.x][temp.y - 1]));
                }
            }
        }
        cout << cost[x - 1][y - 1] << endl;
    }

    return 0;
}
