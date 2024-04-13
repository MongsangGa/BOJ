#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)
#define SIZE 20'002

vector<int> adj[SIZE];
int t, v, e, vis[SIZE];
bool check = false;

void DFS(int now, int color) {
    if (vis[now]) return;
    vis[now] = (color % 2) + 1;
    for (auto nxt: adj[now]) {
        if (vis[nxt] == vis[now]) {
            check = true;
            return;
        }
        DFS(nxt, vis[now]);
    }
}

int main() {
    fastio;
    cin >> t;
    while (t--) {
        for (auto &i: adj) i.clear();
        memset(vis, 0, sizeof vis);
        cin >> v >> e;
        for (int i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        check = false;
        for (int i = 1; i <= v; i++)
            if (!vis[i])
                DFS(i, 1);
        if (check) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}
