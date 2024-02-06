#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(false);
#define INF -(1'000'000'001)

int n, a, b;
vector<pair<int, int>> v;
vector<int> e, res, ans;

int main() {
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        if (res.empty() || res.back() < v[i].second) {
            e.push_back(res.size());
            res.push_back(v[i].second);
        } else {
            int idx = lower_bound(res.begin(), res.end(), v[i].second) - res.begin();
            res[idx] = v[i].second;
            e.push_back(idx);
        }
    }
    cout << n - res.size() << '\n';
    for (int i = e.size() - 1, cur = res.size() - 1; i >= 0; i--) {
        if (cur == e[i]) cur--;
        else ans.push_back(v[i].first);
    }
    for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i] << '\n';
    return 0;
}
