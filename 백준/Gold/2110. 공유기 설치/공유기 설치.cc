#include <bits/stdc++.h>

using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define MAX (int)1e9
int n, m, res;
vector<int> v;

bool possible(int len) {
    int cnt = 1, now = v[0];
    for (int i = 1; i < n; i++)
        if (v[i] - now >= len)
            cnt++, now = v[i];
    if (cnt >= m) return true;
    return false;
}

int main() {
    fastio;
    cin >> n >> m;
    v.resize(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    int st = 1, en = MAX;
    sort(v.begin(), v.end());
    while (st <= en) {
        int mid = (st + en) / 2;
        if (possible(mid)) {
            res = max(res, mid);
            st = mid + 1;
        } else en = mid - 1;
    }
    cout << res;
    return 0;
}
