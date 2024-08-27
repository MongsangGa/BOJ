#include<bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(0), cin.tie(0)
const int SIZE = 50'005;
const int max_depth = floor(log2(SIZE));

int n, m, a, b, depth[SIZE], parent[SIZE][21];
bool vis[SIZE];
vector<int> adj[SIZE];

void DFS(int now, int d) {
    vis[now] = true;
    depth[now] = d;
    for (auto nxt: adj[now]) {
        if (vis[nxt]) continue;
        parent[nxt][0] = now;
        DFS(nxt, d + 1);
    }
}

void f() {
    for (int i = 1; i <= max_depth; i++)
        for (int j = 1; j <= n; j++)
            parent[j][i] = parent[parent[j][i - 1]][i - 1];
}

int LCA(int x, int y) {
    if (depth[x] > depth[y]) swap(x, y);
    for (int i = max_depth; i >= 0; i--)
        if (depth[y] - depth[x] >= (1 << i))
            y = parent[y][i];
    if (x == y) return x;
    for (int i = max_depth; i >= 0; i--)
        if (parent[x][i] != parent[y][i])
            x = parent[x][i], y = parent[y][i];
    return parent[x][0];
}

int main() {
    fastio;
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    DFS(1, 0);
    f();
    cin >> m;
    while (m--) {
        cin >> a >> b;
        cout << LCA(a, b) << '\n';
    }
    return 0;
}
