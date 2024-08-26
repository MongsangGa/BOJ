#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 1'000'002

int n, x, y, dp[2][SIZE]; // dp[0][now] : 얼리어답터, dp[1][now] : 일반인
bool vis[SIZE];
vector<int> adj[SIZE];

void DFS(int now) {
    vis[now] = 1;
    dp[0][now] = 1;
    for (int nxt: adj[now]) {
        if (vis[nxt]) continue;
        DFS(nxt);
        dp[0][now] += min(dp[0][nxt], dp[1][nxt]);
        dp[1][now] += dp[0][nxt];
    }
}

int main() {
    fastio;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    DFS(1);
    cout << min(dp[0][1], dp[1][1]);
    return 0;
}

