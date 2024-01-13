#include <bits/stdc++.h>

using namespace std;

#define SIZE 501
#define INF 1e9+1
int t, n, a, dp[SIZE][SIZE], arr[SIZE];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a;
            arr[i] = arr[i - 1] + a;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n - i; j++) {
                dp[j][i + j] = INF;
                for (int k = j; k < i + j; k++)
                    dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + arr[i + j] - arr[j - 1]);
            }
        }
        cout << dp[1][n] << '\n';
    }
    return 0;
}
