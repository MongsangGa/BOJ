#include <bits/stdc++.h>

using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define INF 1'000'000'002
int n, res = INF, idx[11];
vector<pair<int, int>> v;

int cal(int len) {
    int res1 = 1, res2 = 0;
    for (int i = 0; i < len; i++)
        if (idx[i])
            res1 *= v[i].first, res2 += v[i].second;
    return min(abs(res1 - res2), abs(res2 - res1));
}

void solve(int len, int cnt) {
    if (len > n) return;
    if (cnt > 0) res = min(res, cal(len));
    idx[len] = 1;
    solve(len + 1, cnt + 1);
    idx[len] = 0;
    solve(len + 1, cnt);
}

int main() {
    fastio;
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;
    solve(0, 0);
    cout << res;
    return 0;
}
