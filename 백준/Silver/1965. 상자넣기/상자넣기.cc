#include <bits/stdc++.h>

using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define S 1002

int n, a[S], dp[S], res;

int main() {
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
            if (a[i] > a[j])
                dp[i] = max(dp[i], dp[j] + 1);
    }
    for (int i = 0; i < n; i++) res = max(res, dp[i]);
    cout << res;
    return 0;
}
