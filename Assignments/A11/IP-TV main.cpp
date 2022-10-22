#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n_city, n;
        cin >> n_city >> n;
        string c1, c2;
        int cost;

        vector<vector<pair<int, int>>> graph(n_city, vector<pair<int, int>>());
        map<string, int> m;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> c1 >> c2 >> cost;
            if (m.find(c1) == m.end())
            {
                m.insert({c1, count++});
            }
            if (m.find(c2) == m.end())
            {
                m.insert({c2, count++});
            }

            graph[m[c1]].push_back({m[c2], cost});
            graph[m[c2]].push_back({m[c1], cost});
        }
        vector<bool> visited(n_city, false);
        priority_queue<pair<int, int>> q;
        q.push({0, 0});
        int c = 0, ans = 0;
        while (c < n_city)
        {
            int u = q.top().second;
            int w = -q.top().first;
            q.pop();
            if (!visited[u])
            {
                visited[u] = true;
                ++c;
                ans += w;
                for (int i = 0; i < graph[u].size(); ++i)
                {
                    q.push({-graph[u][i].second, graph[u][i].first});
                }
            }
        }
        cout << ans << endl ;
        if(t!=0)
        cout<<endl;
    }

    return 0;
}
