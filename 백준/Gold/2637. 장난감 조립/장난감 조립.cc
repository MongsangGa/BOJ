#include <bits/stdc++.h>

using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 102

int n, m, ind[SIZE], res[SIZE][SIZE];
vector<pair<int, int>> adj[SIZE]; // nxt, cost
vector<int> basic;
queue<int> q;

int main() {
    fastio;
    cin >> n >> m;
    while (m--) {
        int x, y, k;
        cin >> x >> y >> k;
        adj[y].push_back({x, k});
        ++ind[x];
    }
    for (int i = 1; i <= n; i++)
        if (!ind[i])
            q.push(i), basic.push_back(i), res[i][i] = 1;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (auto nxt: adj[now]) {
            for (auto i: basic)
                res[nxt.first][i] += res[now][i] * nxt.second;
            --ind[nxt.first];
            if (!ind[nxt.first])
                q.push(nxt.first);
        }
    }
    for (auto i: basic)
        cout << i << ' ' << res[n][i] << '\n';
    return 0;
}
