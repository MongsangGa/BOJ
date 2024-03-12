#include <bits/stdc++.h>

using namespace std;
#define SIZE 52
int n, m, s, arr[SIZE], dp[SIZE][1002];

int main() {
    cin >> n >> s >> m;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    dp[0][s] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 1000; j++) {
            if (!dp[i - 1][j]) continue;
            if (j + arr[i] <= m) dp[i][j + arr[i]] = 1;
            if (j - arr[i] >= 0) dp[i][j - arr[i]] = 1;
        }
    }
    for (int i = 1000; i >= 0; i--) {
        if (dp[n][i]) {
            cout << i;
            return 0;
        }
    }
    cout << -1;
    return 0;
}
