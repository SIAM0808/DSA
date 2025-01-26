#include <bits/stdc++.h>
using namespace std;

void floydWarshell(vector<vector<int>> &v, int n) {
    vector<vector<int>> dis = v;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                // if(v[j][i]!=999 && v[i][k]!=999)
                dis[j][k] = min(dis[j][k], dis[j][i] + dis[i][k]);
            }
        }
    }

    for (int i = 0; i <= n; i++) {
        if (v[i][i] < 0) {
            cout << "Negative cycle detected!" << endl;
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dis[i][j] == 999) 
                cout << "INF ";
            else 
                cout << dis[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n, e;
    cin >> n >> e;
    vector<vector<int>> v(n+1, vector<int>(n+1));

    // for (int i = 0; i <= n; i++) {
    //     v[i][i] = 0;  // Self-loop to zero
    // }

    for (int i = 0; i < n; i++) {
        for(int j=0; j<n; j++){
            cin >> v[i][j];
        }
    }

    floydWarshell(v, n);

    return 0;
}
