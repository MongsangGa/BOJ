#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 100'002

int n, m, x, y, res, cycleCnt;
bool vis[SIZE], cycle[SIZE];
vector<int> adj[SIZE];

void DFS(int now, int parent) {
    vis[now] = 1;
    for (int nxt: adj[now]) {
        if (!vis[nxt]) DFS(nxt, now);
        else if (!cycle[nxt] && nxt != parent) ++cycleCnt;
    }
    cycle[now] = 1;
}

int main() {
    fastio;
    cin >> n >> m;
    while (m--) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        DFS(i, -1);
        ++res;
    }
    cout << res + cycleCnt - 1;
    return 0;
}

