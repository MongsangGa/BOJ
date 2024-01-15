#include <bits/stdc++.h>

using namespace std;

#define pii pair<int,int>
#define SIZE 1001
#define INF 1e9 + 1
int n, m, k;
// cost, node
priority_queue<pii, vector<pii >, greater<pii>> pq;
priority_queue<int, vector<int>> dist[SIZE];
vector<pii > adj[SIZE];

void dijkstra() {
    dist[1].push(0);
    pq.push({0, 1});
    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        for (auto nxt: adj[cur.second]) {
            int t = cur.first + nxt.first;
            if (dist[nxt.second].size() < k) {
                dist[nxt.second].push(t);
                pq.push({t, nxt.second});
            } else {
                if (dist[nxt.second].top() > t) {
                    dist[nxt.second].pop();
                    dist[nxt.second].push(t);
                    pq.push({t, nxt.second});
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (dist[i].size() < k) cout << "-1\n";
        else cout << dist[i].top() << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
    }
    dijkstra();
    return 0;
}
