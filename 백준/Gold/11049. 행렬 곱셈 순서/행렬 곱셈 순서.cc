#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define INF 1e9
#define SIZE 502

int n, dp[SIZE][SIZE];
pair<int, int> arr[SIZE];

int f(int s, int e) {
    if (dp[s][e] != INF) return dp[s][e];
    if (s == e) return dp[s][e] = 0;
    for (int i = s; i < e; i++)
        dp[s][e] = min(dp[s][e], f(s, i) + f(i + 1, e) + arr[s].first * arr[i].second * arr[e].second);
    return dp[s][e];
}

int main() {
    fastio;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i].first >> arr[i].second;
    fill(dp[0], dp[SIZE - 1], INF);
    cout << f(1, n);
    return 0;
}
