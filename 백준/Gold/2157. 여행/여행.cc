#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)
#define INF 987654321
int n, m, k, dp[303][303], vis[303][303];

int solve(int idx, int cnt) {
    if (cnt == m && idx != n) return -INF;
    if (idx == n) return 0;
    int &now = dp[idx][cnt];
    if (now != -1) return now;
    now = -INF;
    for (int nxt = idx + 1; nxt <= n; nxt++)
        if (vis[idx][nxt])
            now = max(now, solve(nxt, cnt + 1) + vis[idx][nxt]);
    return now;
}

int main() {
    fastio;
    cin >> n >> m >> k;
    while (k--) {
        int a, b, c;
        cin >> a >> b >> c;
        vis[a][b] = max(vis[a][b], c);
    }
    fill(dp[0], dp[302], -1);
    int res = solve(1, 1);
    cout << res;
    return 0;
}
