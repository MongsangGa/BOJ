#include <bits/stdc++.h>

using namespace std;

#define cost first
#define node second
#define pii pair<int,int>
#define SIZE 501
#define INF 1e9 + 1
int N, E, st, en, chk[SIZE][SIZE];
// cost, node
vector<vector<int>> pre;
vector<vector<pii >> adj;

int dijkstra(int st, int en) {
    priority_queue<pii, vector<pii >, greater<pii>> pq;
    pre = vector<vector<int>>(N + 1);
    int d[SIZE];
    fill(d, d + SIZE, INF);
    pq.push({0, st});
    d[st] = 0;
    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        if (d[cur.node] != cur.cost) continue;
        for (auto nxt: adj[cur.node]) {
            if (chk[cur.node][nxt.node]) continue;
            int nCost = d[cur.node] + nxt.cost;
            if (nCost == d[nxt.node]) pre[nxt.node].push_back(cur.node);
            if (nCost < d[nxt.node]) {
                pre[nxt.node].clear();
                pre[nxt.node].push_back(cur.node);
                d[nxt.node] = nCost;
                pq.push({d[nxt.node], nxt.node});
            }
        }
    }
    return d[en] == INF ? -1 : d[en];
}

void erase(int cur) {
    for (auto s: pre[cur]) {
        for (int i = 0; i < adj[s].size(); i++) {
            if (adj[s][i].node == cur && !chk[s][cur]) {
                chk[s][cur] = 1;
                erase(s);
                break;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (1) {
        cin >> N >> E;
        if (!N || !E) break;
        adj = vector<vector<pii>>(N + 1);
        pre.clear();
        cin >> st >> en;
        memset(chk, 0, sizeof(chk));
        for (int i = 0; i < E; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            adj[a].push_back({c, b});
        }
        dijkstra(st, en);
        erase(en);
        cout << dijkstra(st, en) << '\n';
    }
    return 0;
}
