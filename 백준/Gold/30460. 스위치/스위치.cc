#include<bits/stdc++.h>

using namespace std;

#define SIZE 200'009
int n, arr[SIZE], dp[SIZE];

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        dp[i] = dp[i - 1] + arr[i];
    }
    for (int i = 3; i <= n + 2; i++)
        dp[i] = max(dp[i - 1] + arr[i], dp[i - 3] + 2 * (arr[i] + arr[i - 1] + arr[i - 2]));
    cout << dp[n + 2];
    return 0;
}
