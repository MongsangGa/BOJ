#include <bits/stdc++.h>

using namespace std;

#define SIZE 1001
#define INF 1e9+1
#define pi pair<int,int>
int n, m, st, en, d[SIZE];
vector<pi > adj[SIZE]; // cost, idx
priority_queue<pi, vector<pi >, greater<pi>> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
    }
    cin >> st >> en;
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
    cout << d[en];
    return 0;
}
