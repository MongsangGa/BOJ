#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)
#define int long long
int w, h, n, rx, ry, res = LLONG_MAX;
vector<int> x, y;
vector<pair<int, int>> p;

void calc(int tx, int ty) {
    int ans = 0, MAX = 0;
    for (int i = 0; i < n; i++) {
        int dis = abs(p[i].first - tx) + abs(p[i].second - ty);
        ans += dis;
        MAX = max(MAX, dis);
    }
    ans *= 2;
    ans -= MAX;
    if (res > ans)
        res = ans, rx = tx, ry = ty;
}

int32_t main() {
    fastio;
    cin >> w >> h >> n;
    x.resize(n), y.resize(n), p.resize(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        x[i] = a, y[i] = b, p[i] = {a, b};
    }
    sort(x.begin(), x.end()), sort(y.begin(), y.end());
    if (n & 1) calc(x[n / 2], y[n / 2]);
    else {
        calc(x[n / 2 - 1], y[n / 2 - 1]);
        calc(x[n / 2 - 1], y[n / 2]);
        calc(x[n / 2], y[n / 2 - 1]);
        calc(x[n / 2], y[n / 2]);
    }
    cout << res << '\n' << rx << ' ' << ry;
    return 0;
}
