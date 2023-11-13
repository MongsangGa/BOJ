#include <bits/stdc++.h>

using namespace std;

#define SIZE 1001
int n, a, dp[SIZE], res, MAX;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        dp[a]++;
    }
    for (int i = 1; i < SIZE; i++)
        if (dp[i])
            --dp[i], res++, MAX = max(MAX, i);
    for (int i = MAX; i >= 1; i--)
        if (dp[i])
            res++;
    cout << res;
    return 0;
}
