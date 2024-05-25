#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)
#define ll long long
#define pii pair<ll,ll>
#define x first
#define y second

int t, n;
vector<pii > hull, v;

int CCW(pii a, pii b, pii c) {
    ll ccw = (a.x * b.y + b.x * c.y + c.x * a.y) - (b.x * a.y + c.x * b.y + a.x * c.y);
    if (ccw > 0) return 1;
    if (ccw < 0) return -1;
    return 0;
}

ll dist(pii a, pii b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

bool rotate_calipers(pii ss, pii se, pii es, pii ee) {
    pii l1 = {se.x - ss.x, se.y - ss.y};
    pii l2 = {ee.x - es.x, ee.y - es.y};
    return CCW({0, 0}, l1, l2) >= 0;
}

int main() {
    fastio;
    cin >> t;
    while (t--) {
        v.clear(), hull.clear();
        cin >> n;
        v.resize(n);
        for (int i = 0; i < n; i++) cin >> v[i].x >> v[i].y;
        swap(v[0], *min_element(v.begin(), v.end()));
        sort(v.begin() + 1, v.end(), [&](pii &a, pii &b) {
            int ccw = CCW(v[0], a, b);
            if (ccw) return ccw > 0;
            return dist(v[0], a) < dist(v[0], b);
        });
        for (auto cur: v) {
            while (hull.size() >= 2 && CCW(hull[hull.size() - 2], hull.back(), cur) <= 0) hull.pop_back();
            hull.push_back(cur);
        }
        int nxt = 0;
        ll res = 0;
        pii l1, l2;
        for (int cur = 0; cur < hull.size(); cur++) {
            ll d = 0;
            while (nxt + 1 < hull.size() && rotate_calipers(hull[cur], hull[cur + 1], hull[nxt], hull[nxt + 1])) {
                d = dist(hull[cur], hull[nxt]);
                if (res < d) res = d, l1 = hull[cur], l2 = hull[nxt];
                nxt++;
            }
            d = dist(hull[cur], hull[nxt]);
            if (res < d) res = d, l1 = hull[cur], l2 = hull[nxt];
        }
        cout << l1.x << ' ' << l1.y << ' ' << l2.x << ' ' << l2.y << '\n';
    }
    return 0;
}

