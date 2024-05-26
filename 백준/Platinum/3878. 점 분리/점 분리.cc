#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)
#define ll long long
#define pii pair<int,int>
#define x first
#define y second

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

vector<pii > get_hull(vector<pii > &v) {
    swap(v[0], *min_element(v.begin(), v.end()));
    sort(v.begin() + 1, v.end(), [&](pii a, pii b) {
        int ccw = CCW(v[0], a, b);
        if (ccw) return ccw > 0;
        return Dist(v[0], a) < Dist(v[0], b);
    });
    vector<pii > hull;
    for (auto i: v) {
        while (hull.size() >= 2 && CCW(hull[hull.size() - 2], hull.back(), i) <= 0) hull.pop_back();
        hull.push_back(i);
    }
    return hull;
}

bool inner_chk(vector<pii > &hull, pii &p) {
    int l = CCW(hull[0], hull[1], p);
    for (int i = 1; i < hull.size(); i++)
        if (l * CCW(hull[i], hull[(i + 1) % hull.size()], p) <= 0)
            return false;
    return true;
}


bool cross_chk(pii a, pii b, pii c, pii d) {
    int abc = CCW(a, b, c), abd = CCW(a, b, d), cda = CCW(c, d, a), cdb = CCW(c, d, b);
    if (abc * abd == 0 && cda * cdb == 0) {
        if (a > b) swap(a, b);
        if (c > d) swap(c, d);
        return a <= d && c <= b;
    }
    return abc * abd <= 0 && cda * cdb <= 0;
}

int t, n, m;

int main() {
    fastio;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<pii > b(n), w(m), b_hull, w_hull;
        for (int i = 0; i < n; i++) cin >> b[i].x >> b[i].y;
        for (int i = 0; i < m; i++) cin >> w[i].x >> w[i].y;
        // Black, White Convex Hull
        b_hull = get_hull(b), w_hull = get_hull(w);

        // Convex Hull inner check
        bool res = true;
        if (b_hull.size() > 2)
            for (auto p: w_hull)
                if (inner_chk(b_hull, p))
                    res = false;
        if (w_hull.size() > 2)
            for (auto p: b_hull)
                if (inner_chk(w_hull, p))
                    res = false;
        // Convex Hull line cross check
        for (int i = 0; i < b_hull.size(); i++)
            for (int j = 0; j < w_hull.size(); j++)
                if (cross_chk(b_hull[i], b_hull[(i + 1) % b_hull.size()], w_hull[j], w_hull[(j + 1) % w_hull.size()]))
                    res = false;
        if (res) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
