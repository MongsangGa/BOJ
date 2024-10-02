#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)

#define SIZE 102

int n, m, dis[SIZE][SIZE], ri, rj, res = INT_MAX;
vector<int> adj[SIZE];
queue<int> q;
bool vis[SIZE];

int solve(int x, int y) {
    int sum = 0;
    for (int i = 1; i <= n; i++)
        sum += min(dis[x][i], dis[y][i]);
    return sum;
}

int main() {
    fastio;
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        fill(vis, vis + SIZE, 0);
        q.push(i), vis[i] = 1;
        while (!q.empty()) {
            int now = q.front();
            q.pop();
            for (int nxt: adj[now]) {
                if (vis[nxt]) continue;
                dis[i][nxt] = dis[i][now] + 1;
                q.push(nxt);
                vis[nxt] = 1;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int temp = solve(i, j);
            if (temp < res)
                res = temp, ri = i, rj = j;
        }
    }
    cout << ri << ' ' << rj << ' ' << res * 2;
    return 0;
}
