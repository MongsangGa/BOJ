#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)
#define int long long
int w, h, n, rx, ry, res = LLONG_MAX;
vector<pair<int, int>> p, px, py;

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
    p.resize(n);
    for (int i = 0; i < n; i++)
        cin >> p[i].first >> p[i].second;
    px = p, py = p;
    sort(px.begin(), px.end());
    sort(py.begin(), py.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    });
    if (n & 1) calc(px[n / 2].first, py[n / 2].second);
    else {
        calc(px[n / 2 - 1].first, py[n / 2 - 1].second);
        calc(px[n / 2 - 1].first, py[n / 2].second);
        calc(px[n / 2].first, py[n / 2 - 1].second);
        calc(px[n / 2].first, py[n / 2].second);
    }
    cout << res << '\n' << rx << ' ' << ry;
    return 0;
}
