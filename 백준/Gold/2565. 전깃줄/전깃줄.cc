#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(false);
#define SIZE 501

int n, a, b, dp[SIZE], res;
vector<pair<int, int>> v;

int main() {
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (v[i].first > v[j].first && v[i].second > v[j].second)
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    for (int i = 0; i < n; i++)
        res = max(res, dp[i]);
    cout << n - res;
    return 0;
}
