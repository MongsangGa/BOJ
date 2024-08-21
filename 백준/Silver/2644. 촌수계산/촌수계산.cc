#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 102

int n, m, tx, ty, vis[SIZE];
vector<int> adj[SIZE];

void DFS(int now) {
    for (auto nxt: adj[now]) {
        if (vis[nxt] != -1) continue;
        vis[nxt] = vis[now] + 1;
        DFS(nxt);
    }
    return;
}

int main() {
    fastio;
    cin >> n >> tx >> ty >> m;
    fill(vis, vis + SIZE, -1);
    while (m--) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vis[tx] = 0;
    DFS(tx);
    cout << vis[ty];
    return 0;
}

