#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define x first
#define y second
#define SIZE 10'002
#define INF 1e9

int n, d, dp[SIZE];
vector<pair<int, int>> v[SIZE];

int main() {
    fastio;
    cin >> n >> d;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
    }
    fill(dp, dp + SIZE, INF);
    dp[0] = 0;
    for (int i = 0; i < d; i++) {
        dp[i + 1] = min(dp[i + 1], dp[i] + 1);
        for (auto x: v[i])
            dp[x.first] = min(dp[x.first], dp[i] + x.second);
    }
    cout << dp[d];
    return 0;
}
