#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)
#define pii pair<int,int>
#define ll long long
#define x first
#define y second

int n;
double ans;
vector<pii > v, res;

int CCW(pii a, pii b, pii c) {
    ll ccw = (1LL * a.x * b.y + b.x * c.y + c.x * a.y) - (1LL * b.x * a.y + c.x * b.y + a.x * c.y);
    if (ccw > 0) return 1;
    if (ccw < 0) return -1;
    return 0;
}

bool comp(pii &a, pii &b) {
    int ccw = CCW(v[0], a, b);
    if (ccw) return ccw == 1;
    return (a.y < b.y || (a.y == b.y && a.x < b.x));
}

double dist(pii a, pii b) {
    double d = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
    return sqrt(d);
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
    sort(v.begin() + 1, v.end(), comp);
    res.push_back(v[0]), res.push_back(v[1]);
    for (int i = 2; i < n; i++) {
        while (res.size() >= 2 && CCW(res[res.size() - 2], res.back(), v[i]) != 1) res.pop_back();
        res.push_back(v[i]);
    }
    for (int i = 0; i < res.size(); i++)
        for (int j = i + 1; j < res.size(); j++)
            ans = max(ans, dist(res[i], res[j]));
    printf("%.10f", ans);
    return 0;
}
