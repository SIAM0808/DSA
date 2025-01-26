#include <bits/stdc++.h>
using namespace std;

void bellmanFord(vector<vector<pair<int, int>>> &v, vector<int> &dis, int n, int src)
{
    dis[src] = 0;

    for (int i = 0; i < n - 1; i++)
    { // loop for relaxation
        for (int j = 0; j < n; j++)
        {
            for (auto p : v[j])
            {
                int des = p.second;
                int weight = p.first;
                if (dis[j] != INT_MAX && dis[j] + weight < dis[p.second])
                {
                    dis[p.second] = dis[j] + weight;
                }
            }
        }
    }

    for (int j = 0; j < n; j++)
    {
        for (auto p : v[j])
        {
            int des = p.second;
            int weight = p.first;
            if (dis[j] != INT_MAX && dis[j] + weight < dis[p.second])
            {
                cout << "Graph has negative weight cycle";
                return;
            }
        }
    }

    // Print the shortest distances
    for (int i = 0; i < n; i++)
    {
        if (dis[i] == INT_MAX)
            cout << i << " : INFINITY\n";
        else
            cout << i << " : " << dis[i] << " \n";
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    // Graph represented as adjacency list
    vector<vector<pair<int, int>>> v(n);
    vector<int> dis(n, INT_MAX);

    // Input edges
    for (int i = 0; i < e; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        v[x].push_back({w, y});
    }

    // Print the adjacency list for debugging
    for (int i = 0; i < n; i++)
    {
        for (auto j : v[i])
        {
            cout << i << "->" << j.second << " : " << j.first << endl;
        }
    }

    // Input source vertex
    int src;
    cin >> src;

    // Call Bellman-Ford algorithm
    bellmanFord(v, dis, n, src);
}