#include<bits/stdc++.h>

using namespace std;

int n, l, x1, x2, cur = 1e9 + 2, len, cnt, res;
vector<pair<int, int>> v;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> l;
    for (int i = 0; i < n; i++) {
        cin >> x1 >> x2;
        v.push_back({x2, x1});
    }
    sort(v.begin(), v.end(), greater<pair<int, int>>());
    for (int i = 0; i < n; i++) {
        cur = min(cur, v[i].first);
        if (cur <= v[i].second) continue;
        len = cur - v[i].second;
        cnt = (len / l) + (len % l ? 1 : 0);
        cur -= cnt * l;
        res += cnt;
    }
    cout << res << ' ';
    return 0;
}
