#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(false);
#define SIZE 501

int n, m, a, b, vis[SIZE], res;
vector<int> adj[SIZE];

void BFS(int st) {
    queue<pair<int, int>> q;
    vis[st] = 1;
    q.push({st, 0});
    while (!q.empty()) {
        auto [cur, len] = q.front();
        q.pop();
        for (auto i: adj[cur])
            if (!vis[i] && len + 1 <= 2)
                vis[i] = 1, q.push({i, len + 1});
    }
}

int main() {
    fastio
    cin >> n >> m;
    while (m--) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    BFS(1);
    for (int i = 1; i <= n; i++)
        if (vis[i])
            res++;
    cout << res - 1;
    return 0;
}
