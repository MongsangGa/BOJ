#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE (int)(1e5 + 5)

int n, r, q, x, y, dp[SIZE];
vector<int> adj[SIZE];

int DFS(int now, int parent) {
    int res = 0;
    for (int nxt: adj[now]) {
        if (nxt == parent) continue;
        res += DFS(nxt, now);
    }
    return dp[now] = res + 1;
}

int main() {
    fastio;
    cin >> n >> r >> q;
    for (int i = 0; i < n - 1; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    DFS(r, -1);
    while (q--) {
        cin >> x;
        cout << dp[x] << '\n';
    }
    return 0;
}

