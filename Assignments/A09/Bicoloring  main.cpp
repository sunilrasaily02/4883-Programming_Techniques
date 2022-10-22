#include <iostream>
#include <queue>
using namespace std;

// Driver program
int main()
{
    while (true)
    {
        int n, e;
        cin >> n;
        if (n == 0)
            break;
        int **graph = new int *[n];
        for (int i = 0; i < n; i++)
        {
            graph[i] = new int[n];
            for (int x = 0; x < n; x++)
                graph[i][x] = 0;
        }
        cin >> e;
        int x, y;
        for (int i = 0; i < e; i++)
        {
            cin >> x >> y;
            graph[x][y] = 1;
            graph[y][x] = 1;
        }
        int *nodes = new int[n];
        for (int i = 0; i < n; i++)
            nodes[i] = -1;

        bool flag = true;
        int nextnode = -1;
        queue<int> q;
        q.push(0);
        nodes[0] = 1;
        for (; !q.empty() && flag;)
        {
            nextnode = q.front();
            q.pop();

            for (int j = 0; j < n; j++)
            {
                if (graph[nextnode][j] == 1)
                {

                    if (nodes[nextnode] == nodes[j])
                    {
                        flag = false;
                        break;
                    }
                    else if (nodes[j] == -1)
                    {
                        nodes[j] = !nodes[nextnode];
                        q.push(j);
                    }
                }
            }
        }

        if (flag)
            cout << "BICOLORABLE.\n";
        else
            cout << "NOT BICOLORABLE.\n";
    }
    return 0;
}
