#include<bits/stdc++.h>

using namespace std;
#define SIZE 202
int n, arr[SIZE], dp[SIZE], res;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1; i <= n; i++) {
        dp[i] = 1;
        for (int j = 1; j < i; j++)
            if (arr[i] > arr[j]) dp[i] = max(dp[i], dp[j] + 1);
    }
    for (int i = 1; i <= n; i++) res = max(res, dp[i]);
    cout << n - res;
    return 0;
}
