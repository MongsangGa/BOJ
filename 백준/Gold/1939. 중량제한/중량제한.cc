#include <bits/stdc++.h>

using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 10'002

struct info {
    int u, v, c;
};

int n, m, s, e, parent[SIZE];
vector<info> edge;

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void merge(int u, int v) {
    u = find(u), v = find(v);
    parent[v] = u;
}

int chk(int u, int v) {
    u = find(u), v = find(v);
    if (u == v) return 1;
    return 0;
}

int main() {
    fastio;
    cin >> n >> m;
    for (int i = 0, u, v, c; i < m; i++) {
        cin >> u >> v >> c;
        edge.push_back({u, v, c});
    }
    sort(edge.begin(), edge.end(), [&](info a, info b) {
        return a.c > b.c;
    });
    cin >> s >> e;
    for (int i = 1; i <= n; i++)
        parent[i] = i;
    for (int i = 0; i < m; i++) {
        auto now = edge[i];
        if (!chk(s, e))
            merge(now.u, now.v);
        if (chk(s, e)) {
            cout << now.c;
            break;
        }
    }
    return 0;
}
