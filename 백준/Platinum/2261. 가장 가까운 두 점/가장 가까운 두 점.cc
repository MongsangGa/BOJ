#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define INF (int)(1e4 + 1)
#define pii pair<int,int>
#define x first
#define y second

int n, res;
set<pii > S;
vector<pii > v;

inline int dist(pii a, pii b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int main() {
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    sort(v.begin(), v.end());
    S.insert({v[0].y, v[0].x}), S.insert({v[1].y, v[1].x});
    res = dist(v[0], v[1]);
    int idx = 0;
    for (int i = 2; i < n; i++) {
        while (idx < i) {
            if ((v[i].x - v[idx].x) * (v[i].x - v[idx].x) <= res) break;
            S.erase({v[idx].y, v[idx].x});
            idx++;
        }
        auto l = S.lower_bound({v[i].y - int(sqrt(res)), -INF});
        auto r = S.lower_bound({v[i].y + int(sqrt(res)), INF});
        for (auto it = l; it != r; it++)
            res = min(res, dist({it->y, it->x}, v[i]));
        S.insert({v[i].y, v[i].x});
    }
    cout << res;
    return 0;
}
