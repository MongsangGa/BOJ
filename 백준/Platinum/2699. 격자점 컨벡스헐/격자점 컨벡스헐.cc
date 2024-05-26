#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)
#define ll long long
#define pii pair<int,int>
#define x first
#define y second

int t, n;
vector<pii > v, hull;

int CCW(pii a, pii b, pii c) {
    ll ccw = (1LL * a.x * b.y + 1LL * b.x * c.y + 1LL * c.x * a.y) -
             (1LL * b.x * a.y + 1LL * c.x * b.y + 1LL * a.x * c.y);
    if (ccw > 0) return 1;
    if (ccw < 0) return -1;
    return 0;
}

ll Dist(pii a, pii b) {
    return 1LL * (a.x - b.x) * (a.x - b.x) + 1LL * (a.y - b.y) * (a.y - b.y);
}

int main() {
    fastio;
    cin >> t;
    while (t--) {
        cin >> n;
        v.clear(), v.resize(n);
        for (int i = 0; i < n; i++) cin >> v[i].x >> v[i].y;
        // y -> x sort
        sort(v.begin(), v.end(), [&](pii a, pii b) {
            if (a.y == b.y) return a.x < b.x;
            return a.y > b.y;
        });
        // CCW, Dist sort
        sort(v.begin() + 1, v.end(), [&](pii a, pii b) {
            int ccw = CCW(v[0], a, b);
            if (ccw) return ccw < 0;
            return Dist(v[0], a) < Dist(v[0], b);
        });
        hull.clear(), hull.push_back(v[0]), hull.push_back(v[1]);
        for (int i = 2; i < v.size(); i++) {
            while (hull.size() >= 2 && CCW(hull[hull.size() - 2], hull.back(), v[i]) != -1) hull.pop_back();
            hull.push_back(v[i]);
        }
        cout << hull.size() << '\n';
        for (auto h: hull) cout << h.x << ' ' << h.y << '\n';
    }
    return 0;
}
