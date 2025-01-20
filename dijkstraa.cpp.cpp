#include <bits/stdc++.h>
using namespace std;

void dijkstra(vector<vector<pair<int, int>>> &v, char &src, vector<int> &dis) {
    dis[src - 'A'] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src - 'A'});

    while (!pq.empty()) {
        auto [w, d] = pq.top();
        pq.pop();

        if (w > dis[d]) continue;

        for (auto &i : v[d]) {
            if (dis[i.second] > w + i.first) {
                dis[i.second] = w + i.first;
                pq.push({dis[i.second], i.second});
            }
        }
    }

    for (int i = 0; i < dis.size(); i++) {
        cout << char(i + 'A') << " " << dis[i] << endl;
    }
}

int main() {
    int n, e;
    cin >> n >> e;
    vector<vector<pair<int, int>>> v(n);
    vector<int> dist(n, INT_MAX);

    for (int i = 0; i < e; i++) {
        char x, y;
        int w;
        cin >> x >> y >> w;
        v[x - 'A'].push_back({w, y - 'A'});
    }

    char src;
    cin >> src;
    dijkstra(v, src, dist);

    return 0;
}
