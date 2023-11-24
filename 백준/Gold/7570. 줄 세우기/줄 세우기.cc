#include<bits/stdc++.h>

using namespace std;

int n, a, dp[1'000'002], res;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    // 가장 긴 '연속 & 증가' 되는 수열
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        dp[a] = dp[a - 1] + 1;
        res = max(res, dp[a]);
    }
    cout << n - res;
    return 0;
}
