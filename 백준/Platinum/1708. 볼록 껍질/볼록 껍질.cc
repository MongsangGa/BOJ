#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)
#define pii pair<int,int>
#define ll long long
#define x first
#define y second

int n;
vector<pii > v, res;

int CCW(pii a, pii b, pii c) {
    ll cw = (ll) (b.x - a.x) * (c.y - b.y) - (ll) (b.y - a.y) * (c.x - b.x);
    if (!cw) return 0;
    if (cw < 0) return -1;
    if (cw > 0) return 1;
}

bool compare(pii &a, pii &b) {
    int cw = CCW(v[0], a, b);
    if (cw) return cw == 1;
    return (a.y < b.y || (a.y == b.y && a.x < b.x));
}

int main() {
    fastio;
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].x >> v[i].y;
        if (v[0].y > v[i].y || (v[0].y == v[i].y && v[0].x > v[i].x))
            swap(v[0], v[i]);
    }
    sort(v.begin() + 1, v.end(), compare);
    res.push_back(v[0]), res.push_back(v[1]);
    for (int i = 2; i < n; i++) {
        while (res.size() >= 2 && CCW(res[res.size() - 2], res.back(), v[i]) != 1) res.pop_back();
        res.push_back(v[i]);
    }
    cout << res.size();
    return 0;
}
