#include <bits/stdc++.h>

using namespace std;

#define MAXSIZE 1010
#define INF 1e9
#define pii pair<int,int>
int n, m, x, d[MAXSIZE], res;
vector<pii > adj[MAXSIZE];
priority_queue<pii, vector<pii >, greater<>> q;

int dijsktra(int st, int en) {
    fill(d, d + n + 1, INF);
    d[st] = 0;
    q.push({d[st], st});
    while (!q.empty()) {
        auto [cost, idx] = q.top();
        q.pop();
        if (d[idx] != cost) continue;
        for (auto nxt: adj[idx]) {
            if (d[nxt.second] <= d[idx] + nxt.first) continue;
            d[nxt.second] = d[idx] + nxt.first;
            q.push({d[nxt.second], nxt.second});
        }
    }
    return d[en];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> x;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
    }
    for (int st = 1; st <= n; st++)
        res = max(res, dijsktra(st, x) + dijsktra(x, st));
    cout << res;
    return 0;
}
