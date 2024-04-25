#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)
#define pii pair<int,int>
#define SIZE 2002
#define INF 1e9
int d1[SIZE], d2[SIZE], arr[SIZE];
vector<pii > adj[SIZE];
priority_queue<pii, vector<pii >, greater<>> pq;

void Dijkstra(int st, int *d) {
    fill(d, d + SIZE, INF);
    d[st] = 0;
    pq.push({d[st], st});
    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        if (cur.first != d[cur.second]) continue;
        for (auto nxt: adj[cur.second]) {
            if (d[nxt.second] <= d[cur.second] + nxt.first) continue;
            d[nxt.second] = d[cur.second] + nxt.first;
            pq.push({d[nxt.second], nxt.second});
        }
    }
}

int main() {
    fastio;
    // s 에서 시작해서 g h 도로를 반드시 지나야함
    int T;
    cin >> T;
    while (T--) {
        for (int i = 0; i < SIZE; i++) adj[i].clear();
        int n, m, t, s, g, h;
        cin >> n >> m >> t;
        cin >> s >> g >> h;
        for (int i = 0; i < m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            adj[a].push_back({c, b});
            adj[b].push_back({c, a});
        }
        Dijkstra(s, d1);
        int newS = d1[g] < d1[h] ? h : g;
        Dijkstra(newS, d2);
        fill(arr, arr + SIZE, 0);
        for (int i = 0; i < t; i++) {
            int x;
            cin >> x;
            arr[x] = 1;
        }
        for (int i = 1; i <= n; i++) {
            if (!arr[i] || (d1[i] == INF || d2[i] == INF)) continue;
            if (d1[i] == d1[newS] + d2[i]) cout << i << ' ';
        }
        cout << '\n';
    }
    return 0;
}
