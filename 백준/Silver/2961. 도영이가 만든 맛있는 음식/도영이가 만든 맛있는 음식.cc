#include <bits/stdc++.h>

using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define INF 1'000'000'002

int n, res = INF;

int main() {
    fastio;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;
    for (int i = 1; i < (1 << n); i++) {
        int res1 = 1, res2 = 0;
        for (int j = 0; j < n; j++)
            if (i & (1 << j))
                res1 *= v[j].first, res2 += v[j].second;
        res = min(res, abs(res1 - res2));
    }
    cout << res;
    return 0;
}
