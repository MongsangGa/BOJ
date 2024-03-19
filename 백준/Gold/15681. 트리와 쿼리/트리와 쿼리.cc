#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)
#define SIZE (int)1e6

int n, r, q, a, b, dp[SIZE];
vector<int> adj[SIZE];

int DFS(int parent, int now) {
    int res = 0;
    for (auto nxt: adj[now]) {
        if (nxt == parent) continue;
        res += DFS(now, nxt);
    }
    return dp[now] = res + 1;
}

int main() {
    fastio;
    cin >> n >> r >> q;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    DFS(0, r);
    for (int i = 0; i < q; i++) {
        cin >> a;
        cout << dp[a] << '\n';
    }
    return 0;
}
