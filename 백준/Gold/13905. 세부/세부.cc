#include<bits/stdc++.h>

using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define S 100'002

int n, m, sx, ex, res;
bool vis[S];
vector<pair<int, int>> adj[S];

bool BFS(int k) {
    queue<int> q;
    fill(vis, vis + S, 0);
    q.push(sx), vis[sx] = 1;
    while (!q.empty()) {
        auto now = q.front();
        q.pop();
        for (auto nxt: adj[now]) {
            if (vis[nxt.first] || nxt.second < k) continue;
            if (nxt.first == ex) return 1;
            q.push(nxt.first), vis[nxt.first] = 1;
        }
    }
    return 0;
}

int main() {
    fastio;
    cin >> n >> m >> sx >> ex;
    while (m--) {
        int x, y, c;
        cin >> x >> y >> c;
        adj[x].push_back({y, c});
        adj[y].push_back({x, c});
    }
    int s = 0, e = 2e6;
    while (s <= e) {
        int mid = (s + e) / 2;
        if (BFS(mid)) s = mid + 1, res = max(res, mid);
        else e = mid - 1;
    }
    cout << res;
    return 0;
}
