#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)
#define SIZE 10'002

int n, arr[SIZE], dp[2][SIZE];
bool vis[SIZE];
vector<int> adj[SIZE], res;

void DFS(int now) {
    vis[now] = 1;
    dp[1][now] = arr[now];
    for (auto nxt: adj[now]) {
        if (vis[nxt]) continue;
        DFS(nxt);
        dp[0][now] += max(dp[1][nxt], dp[0][nxt]);
        dp[1][now] += dp[0][nxt];
    }
}

void tracking(int prev, int now) {
    if (dp[1][now] > dp[0][now] && !vis[prev]) {
        vis[now] = 1;
        res.push_back(now);
    }
    for (auto nxt: adj[now]) {
        if (nxt == prev) continue;
        tracking(now, nxt);
    }
}

int main() {
    fastio;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    DFS(1);
    fill(vis, vis + SIZE, 0);
    tracking(0, 1);
    cout << max(dp[0][1], dp[1][1]) << '\n';
    sort(res.begin(), res.end());
    for (auto i: res) cout << i << ' ';
    return 0;
}
