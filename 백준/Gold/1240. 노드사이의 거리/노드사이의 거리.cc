#include <bits/stdc++.h>

using namespace std;

int n, m, chk[1'001], res;
vector<pair<int, int>> adj[1'001];

void dfs(int st, int en, int c) {
    if (st == en) {
        res = c;
        return;
    }
    for (auto [nxt, cost]: adj[st]) {
        if (chk[nxt]) continue;
        chk[nxt] = 1;
        dfs(nxt, en, c + cost);
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    while (m--) {
        int a, b;
        memset(chk, 0, sizeof(chk));
        cin >> a >> b;
        chk[a] = 1, res = 0;
        dfs(a, b, 0);
        cout << res << '\n';
    }
    return 0;
}
