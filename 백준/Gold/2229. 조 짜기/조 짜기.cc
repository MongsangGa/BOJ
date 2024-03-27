#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)
#define SIZE 10'001
int n, arr[SIZE], dp[SIZE];

int cal(int s, int e) {
    int MAX = -1, MIN = 987654321;
    for (int i = s; i <= e; i++)
        MAX = max(arr[i], MAX), MIN = min(arr[i], MIN);
    return MAX - MIN;
}

int main() {
    fastio;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            dp[i] = max(dp[i], dp[j - 1] + cal(j, i));
    cout << dp[n];
    return 0;
}
