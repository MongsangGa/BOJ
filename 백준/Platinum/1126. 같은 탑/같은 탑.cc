#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)

int n, arr[52], dp[52][500'002];

int solve(int idx, int diff) {
    int &now = dp[idx][diff];
    if (now) return now;
    if (idx == n + 1) {
        if (diff) return -1e9;
        return 0;
    }
    return now = max({solve(idx + 1, diff + arr[idx]) + arr[idx], solve(idx + 1, diff),
                      solve(idx + 1, abs(diff - arr[idx])) + (diff - arr[idx] < 0 ? arr[idx] - diff : 0)});
}

int main() {
    fastio;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    int res = solve(1, 0);
    cout << (res ? res : -1);
    return 0;
}
