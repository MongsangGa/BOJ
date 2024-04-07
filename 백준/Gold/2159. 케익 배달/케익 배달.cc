#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)
#define ll long long
int n, dx[] = {0, -1, 0, 1, 0}, dy[] = {0, 0, -1, 0, 1};
ll dp[100'002][5];
vector<pair<int, int>> v;

ll getDis(ll x1, ll y1, ll x2, ll y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

ll solve(int idx, int r, int x, int y) {
    if (idx == n) return 0;
    ll &now = dp[idx][r];
    if (now != -1) return now;
    now = LLONG_MAX;
    for (int i = 0; i < 5; i++) {
        ll nx = v[idx + 1].first + dx[i], ny = v[idx + 1].second + dy[i];
        now = min(now, solve(idx + 1, i, nx, ny) + getDis(x, y, nx, ny));
    }
    return now;
}

int main() {
    fastio;
    cin >> n;
    v.resize(n + 1);
    for (int i = 0; i <= n; i++)
        cin >> v[i].first >> v[i].second;
    memset(dp, -1, sizeof dp);
    cout << solve(0, 0, v[0].first, v[0].second);
    return 0;
}
