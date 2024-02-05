#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(false);
#define INF 1e9
#define nSIZE 1'001
#define mSIZE 30'001

int n, m, k, st, en, d[mSIZE][nSIZE], res = INF; // adj, node
vector<tuple<int, int, int>> adj;

int main() {
    fastio;
    cin >> n >> m >> k;
    cin >> st >> en;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj.push_back({c, a, b});
    }
    fill(d[0], d[mSIZE - 1], INF);
    d[0][st] = 0;
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < m; j++) {
            auto [cost, a, b] = adj[j];
            d[i][a] = min(d[i][a], d[i - 1][b] + cost);
            d[i][b] = min(d[i][b], d[i - 1][a] + cost);
        }
    }
    for (int i = 1; i <= n - 1; i++) res = min(res, d[i][en]);
    cout << res << '\n';
    while (k--) {
        int u;
        cin >> u;
        res = INF;
        for (int i = 1; i <= n - 1; i++)
            res = min(res, d[i][en] += u * i);
        cout << res << '\n';
    }
    return 0;
}

