#include <bits/stdc++.h>

using namespace std;

#define SIZE 1'002
#define INF 1e9+1
int V, E, start, en, d[SIZE], pre[SIZE];
vector<pair<int, int>> adj[SIZE]; // 비용, 간선
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> V >> E;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
    }
    cin >> start >> en;
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
            pre[nxt.second] = cur.second;
        }
    }
    vector<int> res;
    cout << d[en] << '\n';
    while (en != start) {
        res.push_back(en);
        en = pre[en];
    }
    res.push_back(en);
    reverse(res.begin(), res.end());
    cout << res.size() << '\n';
    for (auto r: res) cout << r << ' ';
    return 0;
}
