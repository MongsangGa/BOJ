#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)
#define ll long long
#define pii pair<ll,ll>
#define x first
#define y second

int n;
vector<pii > v, res;

int CCW(pii a, pii b, pii c) {
    ll ccw = (1LL * a.x * b.y + b.x * c.y + c.x * a.y) - (1LL * b.x * a.y + c.x * b.y + a.x * c.y);
    if (ccw > 0) return 1;
    if (ccw < 0) return -1;
    return 0;
}

bool comp(pii &a, pii &b) {
    ll ccw = CCW(v[0], a, b);
    if (!ccw) {
        if (a.x == b.x) return a.y > b.y;
        else {
            if (a.y == b.y) return a.x < b.x;
            return a.y > b.y;
        }
    }
    return ccw > 0;
}

int main() {
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        char order;
        cin >> a >> b >> order;
        if (order == 'N') continue;
        v.push_back({a, b});
    }
    n = v.size();
    sort(v.begin(), v.end());
    sort(v.begin() + 1, v.end(), comp);
    res.push_back(v[0]), res.push_back(v[1]);
    for (int i = 2; i < n; i++) {
        while (res.size() >= 2 && CCW(res[res.size() - 2], res.back(), v[i]) < 0) res.pop_back();
        res.push_back(v[i]);
    }
    cout << res.size() << '\n';
    for (auto r: res) cout << r.x << ' ' << r.y << '\n';
    return 0;
}