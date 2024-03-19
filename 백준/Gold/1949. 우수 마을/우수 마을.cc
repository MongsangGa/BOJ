#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)
#define SIZE 10'002

int n, arr[SIZE], dp[SIZE][2];
bool vis[SIZE];
vector<int> adj[SIZE];

void DFS(int now) {
    vis[now] = 1;
    dp[now][1] = arr[now];
    for (auto nxt: adj[now]) {
        if (vis[nxt]) continue;
        DFS(nxt);
        dp[now][0] += max(dp[nxt][0], dp[nxt][1]);
        dp[now][1] += dp[nxt][0];
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
    cout << max(dp[1][0], dp[1][1]);
    return 0;
}
