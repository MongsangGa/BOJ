#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(false);
#define INF -(1e9+1)
#define SIZE 51

long long int d[SIZE], n, st, en, m, c[SIZE], v[SIZE];
vector<tuple<int, int, int>> adj;

bool BFS(int s, int e) {
    queue<int> q;
    fill(v, v + SIZE, 0);
    q.push(s);
    v[s] = 1;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        if (cur == e) return true;
        for (int i = 0; i < m; i++) {
            auto [cost, a, b] = adj[i];
            if (cur == a && !v[b]) {
                v[b] = 1;
                q.push(b);
            }
        }
    }
    return false;
}

int main() {
    fastio;
    cin >> n >> st >> en >> m;
    for (int i = 0; i < m; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;
        adj.push_back({cost, a, b});
    }
    fill(d, d + SIZE, INF);
    for (int i = 0; i < n; i++) cin >> c[i];
    d[st] = c[st];
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < m; j++) {
            auto [cost, a, b] = adj[j];
            if (d[a] == INF) continue;
            d[b] = max(d[b], d[a] - cost + c[b]);
        }
    }
    if (d[en] == INF) {
        cout << "gg";
        return 0;
    }
    // 사이클이 존재하면 돈을 무한히 벌 수 있음
    for (int j = 0; j < m; j++) {
        auto [cost, a, b] = adj[j];
        if (d[a] == INF) continue;
        if (d[b] < d[a] - cost + c[b]) {
            // 사이클이 생기는 노드에서 en 노드를 갈 수 있는지 체크
            if (BFS(b, en)) {
                cout << "Gee";
                return 0;
            }
        }
    }
    cout << d[en];
    return 0;
}
