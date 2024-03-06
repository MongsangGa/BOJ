#include <bits/stdc++.h>

using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 10'002

int n, m, cnt, vis[SIZE];
vector<int> adj[SIZE];
bool res[SIZE];

int dfs(int X, bool is_parent) {
    vis[X] = ++cnt;
    int now = vis[X], child = 0;
    for (auto nxt: adj[X]) {
        if (!vis[nxt]) {
            child++;
            int low = dfs(nxt, false);
            if (!is_parent && low >= vis[X])
                res[X] = true;
            now = min(now, low);
        } else now = min(now, vis[nxt]);
    }
    if (is_parent) res[X] = (child >= 2);
    return now;
}

int main() {
    fastio;
    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            dfs(i, true);
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (res[i])
            ans++;
    cout << ans << '\n';
    for (int i = 1; i <= n; i++)
        if (res[i])
            cout << i << ' ';
    return 0;
}
