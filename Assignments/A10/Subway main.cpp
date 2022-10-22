#include <iostream>
#include <queue>
#include <cmath>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
const double WalkSpeed = (10.0 / 60.0 * 1000.0);
const double TrainSpeed = (40.0 / 60.0 * 1000.0);
double GetCost(pair<int, int> x, pair<int, int> y)
{
    int xDiff = x.first - y.first;
    int yDiff = x.second - y.second;
    return sqrt(xDiff * xDiff + yDiff * yDiff);
}
const double Eps = 1e-7;

 bool LessThan(double lhs, double rhs)
{
    return lhs < rhs - Eps;
}
struct node
{
    int num;
    double cost;
    node(int n, double c)
    {
        num = n;
        cost = c;
    }
    bool operator<(const node &other) const
    {
        return LessThan(other.cost, cost);
    }
};

struct edge
{
    int x, y, n;
};
// Driver program
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        vector<vector<edge>> v;
        pair<int, int> src, dist;
        string h;
        int countNodes = 0;
        cin >> src.first >> src.second >> dist.first >> dist.second;
        getline(cin, h);

        vector<node> city[207];
        city[0].push_back(node(1, GetCost(src, dist) / WalkSpeed));

        city[1].push_back(node(0, GetCost(src, dist) / WalkSpeed));

        bool f = true;

        countNodes += 2;
        int count = 0;
        while (1)
        {
            string str;
            int current = 2;
            getline(cin, str);

            if (str == "")
                break;

            vector<edge> ve;

            edge e;
            int start = 0;
            while (3)
            {
                int space = str.find(' ');
                string temp = str.substr(0, space);

                int tmp = stoi(temp);
                str = str.substr(space + 1);
                if (tmp == -1)
                    break;
                else
                {
                    if (f)
                    {
                        e.x = tmp;
                        f = false;
                        count++;
                    }
                    else
                    {
                        e.y = tmp;
                        f = true;
                        count++;
                    }
                }
                if (count % 2 == 0)
                {
                    current++;
                    city[0].push_back(node(countNodes, GetCost(src, {e.x, e.y}) / WalkSpeed));
                    city[countNodes].push_back(node(0, GetCost(src, {e.x, e.y}) / WalkSpeed));
                    city[1].push_back(node(countNodes, GetCost(dist, {e.x, e.y}) / WalkSpeed));
                    city[countNodes].push_back(node(1, GetCost(dist, {e.x, e.y}) / WalkSpeed));

                    e.n = countNodes++;
                    ve.push_back(e);
                }
            }
            countNodes -= ve.size();
            for (int i = 0; i < ve.size() - 1; i++)
            {
                city[countNodes].push_back(node(countNodes + 1, GetCost({ve[i].x, ve[i].y}, {ve[i + 1].x, ve[i + 1].y}) / TrainSpeed));
                city[countNodes + 1].push_back(node(countNodes, GetCost({ve[i].x, ve[i].y}, {ve[i + 1].x, ve[i + 1].y}) / TrainSpeed));
                countNodes++;
            }
            countNodes++;
            v.push_back(ve);
        }
        int c = 2;
        for (int i = 0; i < v.size(); i++)
        {
            for (int j = 0; j < v[i].size(); j++)
            {
               
                for (int x = 0; x < v.size(); x++)
                {
                    for (int y = 0; y < v[x].size(); y++)
                    {
                        if (v[i][j].n != v[x][y].n)
                        {
                            city[v[i][j].n].push_back(node(v[x][y].n, GetCost({v[i][j].x, v[i][j].y}, {v[x][y].x, v[x][y].y}) / WalkSpeed));
                        }
                    }
                }
            }
        }

        vector<double> costs(countNodes, 999999999999);
        priority_queue<node> q;
        q.push(node{0, 0});
        costs[0] = 0;
        double cc;
        while (true)
        {
            node next = q.top();
            q.pop();

            if (next.num == 1)
            {
                cc = next.cost;
                break;
            }
            if (LessThan(costs[next.num], next.cost))
                continue;

            for (node connected : city[next.num])
            {
                if (LessThan(next.cost + connected.cost, costs[connected.num]))
                {
                    costs[connected.num] = next.cost + connected.cost;
                    q.push(node{connected.num, next.cost + connected.cost});
                }
            }
        }
        if(t==0)
        cout << fixed << setprecision(0) << cc ;
        else
       cout << fixed << setprecision(0) << cc<<endl<<endl; ;
        
    }
    cout<<endl;
    return 0;
}
