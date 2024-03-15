#include <bits/stdc++.h>

using namespace std;
#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)
#define SIZE 503
#define INF 987654321

int t, n, m, w, d[SIZE];
vector<tuple<int, int, int>> adj;

int solve(int s, int e) {
    fill(d, d + SIZE, INF);
    d[s] = 0;
    for (int i = 1; i <= e; i++) {
        bool chk = false;
        for (auto [c, a, b]: adj) {
            if (d[b] > d[a] + c) {
                chk = true;
                d[b] = d[a] + c;
            }
        }
        if (!chk) return 0;
    }
    return 1;
}

int main() {
    fastio;
    cin >> t;
    while (t--) {
        adj.clear();
        cin >> n >> m >> w;
        int c, a, b;
        for (int i = 0; i < m; i++)
            cin >> a >> b >> c, adj.push_back({c, a, b}), adj.push_back({c, b, a});
        for (int i = 0; i < w; i++)
            cin >> a >> b >> c, adj.push_back({-c, a, b});
        if (solve(1, n)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
