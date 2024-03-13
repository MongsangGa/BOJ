#include <bits/stdc++.h>

using namespace std;
#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)
#define SIZE 1002

int n, m, p[SIZE], res;
vector<tuple<int, int, int>> adj;

int find(int x) {
    if (p[x] == x) return x;
    return p[x] = find(p[x]);
}

void merge(int u, int v) {
    u = find(u), v = find(v);
    p[v] = u;
}

int main() {
    fastio;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int cost, a, b;
        cin >> a >> b >> cost;
        adj.push_back({cost, a, b});
    }
    sort(adj.begin(), adj.end());
    for (int i = 1; i <= n; i++) p[i] = i;
    for (int i = 0; i < m; i++) {
        auto [cost, a, b] = adj[i];
        if (find(a) == find(b)) continue;
        merge(a, b);
        res += cost;
    }
    cout << res;
    return 0;
}
