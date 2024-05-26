#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)
#define ll long long
#define pii pair<int,int>
#define ppi pair<pii, int>
#define x first
#define y second

int t, n;
vector<ppi > v;

int CCW(pii a, pii b, pii c) {
    ll ccw = (1LL * a.x * b.y + 1LL * b.x * c.y + 1LL * c.x * a.y) -
             (1LL * b.x * a.y + 1LL * c.x * b.y + 1LL * a.x * c.y);
    if (ccw > 0) return 1;
    if (ccw < 0) return -1;
    return 0;
}

auto dist(pii a, pii b) {
    return 1LL * (a.x - b.x) * (a.x - b.x) + 1LL * (a.y - b.y) * (a.y - b.y);
}

int main() {
    fastio;
    cin >> t;
    while (t--) {
        cin >> n;
        v.clear(), v.resize(n);
        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            v[i] = {{a, b}, i};
        }
        swap(v[0], *min_element(v.begin(), v.end()));
        sort(v.begin() + 1, v.end(), [&](ppi a, ppi b) {
            int ccw = CCW(v[0].x, a.x, b.x);
            if (ccw) return ccw > 0;
            return dist(v[0].x, a.x) < dist(v[0].x, b.x);
        });
        int en = n - 1;
        while (!CCW(v[0].x, v[en].x, v[en - 1].x)) en--;
        reverse(v.begin() + en, v.end());
        for (auto i: v) cout << i.y << ' ';
        cout << '\n';
    }
    return 0;
}
