#include <bits/stdc++.h>

using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
const int SIZE = 100'001;

int v, e, p[SIZE], res, cnt;
tuple<int, int, int> adj[SIZE];

int find(int x) {
    if (p[x] == x) return x;
    return p[x] = find(p[x]);
}

void merge(int u, int v) {
    u = find(u);
    v = find(v);
    p[v] = u;
}

int main() {
    fastio;
    cin >> v >> e;
    for (int i = 0; i < e; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;
        adj[i] = {cost, a, b};
    }
    sort(adj, adj + e);
    for (int i = 1; i <= v; i++)
        p[i] = i;
    for (int i = 0; i < e; i++) {
        auto [cost, a, b] = adj[i];
        if (find(a) == find(b)) continue;
        merge(a, b);
        res += cost, cnt++;
        if (cnt == v) break;
    }
    cout << res;
    return 0;
}
