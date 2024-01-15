#include <bits/stdc++.h>

using namespace std;

#define SIZE 20'002
#define INF 1e9+1
int V, E, start, d[SIZE];
vector<pair<int, int>> adj[SIZE]; // 비용, 간선
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> V >> E >> start;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
    }
    fill(d, d + SIZE, INF);
    d[start] = 0;
    pq.push({d[start], start});
    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        if (d[cur.second] != cur.first) continue;
        for (auto nxt: adj[cur.second]) {
            if (d[nxt.second] <= d[cur.second] + nxt.first) continue;
            d[nxt.second] = d[cur.second] + nxt.first;
            pq.push({d[nxt.second], nxt.second});
        }
    }
    for (int i = 1; i <= V; i++) {
        if (d[i] == INF) cout << "INF\n";
        else cout << d[i] << '\n';
    }
    return 0;
}
