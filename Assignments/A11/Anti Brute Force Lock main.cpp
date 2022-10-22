#include <bits/stdc++.h>

using namespace std;
int countDiff(string x, string y)
{
    int counter = 0;
    for (int i = 0; i < 4; i++)
    {
        int j = x[i] - '0';
        int k = y[i] - '0';
        counter += min(abs(k - j), min(k, j) - max(k, j) + 10);
    }

    return counter;
}
int main()
{
    int t;
    cin >> t;
    int n;
    string zero = "0000";
    while (t--)
    { 
        cin >> n;
        int x1 = 99999;
        vector<vector<pair<int, int>>> adj(n);
        vector<string> nodes(n);

        for (int i = 0; i < n; i++)
        {
            cin >> nodes[i];
            x1 = min(x1, countDiff(zero, nodes[i]));
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int x = countDiff(nodes[i], nodes[j]);

                adj[i].push_back({j, x});
                adj[j].push_back({i, x});
            }
        }

        vector<bool> visited(n, false);
        priority_queue<pair<int, int>> q;
        q.push({0, 0});
        int c = 0, ans = 0;
        while (c < n)
        {
            int u = q.top().second;
            int w = -q.top().first;
            q.pop();

            if (!visited[u])
            {
                visited[u] = true;
                ++c;
                ans += w;
                for (int i = 0; i < adj[u].size(); ++i)
                {
                    q.push({-adj[u][i].second, adj[u][i].first});
                }
            }
        }
        cout << x1 + ans << endl;
    }
     return 0;
}
