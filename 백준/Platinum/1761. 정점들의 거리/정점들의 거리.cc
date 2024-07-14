#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
const int SIZE = 40'004;
const int max_depth = floor(log2(SIZE));

int n, m, d[SIZE], parent[SIZE][17], len[SIZE];
vector<pair<int, int>> adj[SIZE];
bool vis[SIZE];

void DFS(int now, int depth) {
    vis[now] = 1;
    d[now] = depth;
    for (auto [nxt, cost]: adj[now]) {
        if (vis[nxt]) continue;
        parent[nxt][0] = now;
        len[nxt] = len[now] + cost;
        DFS(nxt, depth + 1);
    }
}

void f() {
    for (int i = 1; i <= max_depth; i++)
        for (int j = 1; j <= n; j++)
            parent[j][i] = parent[parent[j][i - 1]][i - 1];
}

int LCA(int x, int y) {
    if (d[x] > d[y]) swap(x, y);
    for (int i = max_depth; i >= 0; i--)
        if (d[y] - d[x] >= (1 << i))
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
        int x, y, c;
        cin >> x >> y >> c;
        adj[x].push_back({y, c});
        adj[y].push_back({x, c});
    }
    DFS(1, 0);
    f();
    cin >> m;
    while (m--) {
        int x, y, z;
        cin >> x >> y;
        z = LCA(x, y);
        cout << len[x] + len[y] - 2 * len[z] << '\n';
    }
    return 0;
}
