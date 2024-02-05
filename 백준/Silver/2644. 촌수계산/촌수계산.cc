#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(false);
#define X first
#define Y second
#define SIZE 101

int n, m, x, y, vis[SIZE];
vector<int> adj[SIZE];
queue<int> q;

int main() {
    fastio;
    cin >> n >> x >> y >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vis[x] = 1;
    q.push(x);
    while (!q.empty()) {
        auto now = q.front();
        q.pop();
        for (auto nxt: adj[now]) {
            if (vis[nxt]) continue;
            vis[nxt] = vis[now] + 1;
            q.push(nxt);
        }
    }
    if (!vis[y]) cout << -1;
    else cout << vis[y] - 1;
    return 0;
}

