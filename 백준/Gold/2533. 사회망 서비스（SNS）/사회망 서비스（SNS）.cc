#include <bits/stdc++.h>

using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define S 1'000'002

int n, vis[S], dp[2][S];
vector<int> adj[S];

void DFS(int now) {
    vis[now] = 1, dp[1][now] = 1;
    for (int nxt: adj[now]) {
        if (vis[nxt]) continue;
        DFS(nxt);
        dp[1][now] += min(dp[0][nxt], dp[1][nxt]);
        dp[0][now] += dp[1][nxt];
    }
}

int main() {
    fastio;
    cin >> n;
    for (int i = 0, u, v; i < n - 1; i++) {
        cin >> u >> v;
        adj[u].push_back(v), adj[v].push_back(u);
    }
    DFS(1);
    cout << min(dp[0][1], dp[1][1]);
    return 0;
}
