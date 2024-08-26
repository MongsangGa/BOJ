#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 1002

int n, m, x, y, c, res;
vector<pair<int, int>> adj[SIZE];

void DFS(int now, int parent, int cost) {
    if (now == y) {
        res = cost;
        return;
    }
    for (auto [nxtN, nxtC]: adj[now]) {
        if (parent == nxtN) continue;
        DFS(nxtN, now, cost + nxtC);
    }
}

int main() {
    fastio;
    cin >> n >> m;
    for (int i = 0; i < n - 1; i++) {
        cin >> x >> y >> c;
        adj[x].push_back({y, c});
        adj[y].push_back({x, c});
    }
    while (m--) {
        res = 0;
        cin >> x >> y;
        DFS(x, -1, 0);
        cout << res << '\n';
    }
    return 0;
}

