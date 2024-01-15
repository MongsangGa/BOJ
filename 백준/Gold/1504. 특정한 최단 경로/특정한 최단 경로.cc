#include <bits/stdc++.h>

using namespace std;

#define pii pair<int,int>
#define SIZE 801
#define INF 1e9 + 1
int N, E, v1, v2;
// cost, node
priority_queue<pii, vector<pii >, greater<pii>> pq;
vector<pii > adj[SIZE];

int dijkstra(int st, int en) {
    int d[SIZE];
    fill(d, d + SIZE, INF);
    d[st] = 0;
    pq.push({d[st], st});
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
    return d[en];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> E;
    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }
    cin >> v1 >> v2;
    long long int path1, path2, res;
    path1 = path2 = INF;
    path1 = dijkstra(1, v1) + dijkstra(v1, v2) + dijkstra(v2, N);
    path2 = dijkstra(1, v2) + dijkstra(v2, v1) + dijkstra(v1, N);
    res = min(path1, path2);
    if (res >= INF || res < 0) cout << "-1";
    else cout << res;
    return 0;
}
