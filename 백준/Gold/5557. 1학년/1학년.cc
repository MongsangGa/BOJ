#include<bits/stdc++.h>

using namespace std;
#define ll long long int
#define SIZE 101
ll n, arr[SIZE], dp[SIZE][21];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    dp[0][arr[0]] = 1;
    for (int i = 1; i < n - 1; i++) {
        for (int j = 0; j <= 20; j++) {
            if (0 <= j + arr[i] && j + arr[i] <= 20)
                dp[i][j] += dp[i - 1][j + arr[i]];
            if (0 <= j - arr[i] && j - arr[i] <= 20)
                dp[i][j] += dp[i - 1][j - arr[i]];
        }
    }
    cout << dp[n - 2][arr[n - 1]];
    return 0;
}
