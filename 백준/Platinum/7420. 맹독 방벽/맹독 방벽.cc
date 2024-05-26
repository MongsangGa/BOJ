#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)
#define ll long long
#define pii pair<int,int>
#define x first
#define y second

int n, l;
double res = 0;
vector<pii > v, hull;

int CCW(pii a, pii b, pii c) {
    ll ccw = (1LL * a.x * b.y + 1LL * b.x * c.y + 1LL * c.x * a.y) -
             (1LL * b.x * a.y + 1LL * c.x * b.y + 1LL * a.x * c.y);
    if (ccw > 0) return 1;
    if (ccw < 0) return -1;
    return 0;
}

double DIST(pii a, pii b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main() {
    fastio;
    cin >> n >> l;
    v.resize(n);
    for (int i = 0; i < n; i++) cin >> v[i].x >> v[i].y;
    swap(v[0], *min_element(v.begin(), v.end()));
    sort(v.begin() + 1, v.end(), [&](pii a, pii b) {
        int ccw = CCW(v[0], a, b);
        if (ccw) return ccw > 0;
        return DIST(v[0], a) < DIST(v[0], b);
    });
    hull.push_back(v[0]), hull.push_back(v[1]);
    for (int i = 2; i < n; i++) {
        while (hull.size() >= 2 && CCW(hull[hull.size() - 2], hull.back(), v[i]) <= 0) hull.pop_back();
        hull.push_back(v[i]);
    }
    hull.push_back(v[0]);
    for (int i = 0; i < hull.size() - 1; i++)
        res += DIST(hull[i], hull[i + 1]);
    printf("%.0lf", res + 2 * M_PI * l);
    return 0;
}
