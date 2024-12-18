#include <bits/stdc++.h>
using namespace std;

int n;
double dp[10'002], arr[10'002];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        dp[i] = arr[i];
    }
    for (int i = 1; i < n; i++)
        dp[i] = max(dp[i], dp[i - 1] * arr[i]);
    double res = 0L;
    for (int i = 0; i < n; i++)
        res = max(res, dp[i]);
    printf("%0.3lf", res);
    return 0;
}
