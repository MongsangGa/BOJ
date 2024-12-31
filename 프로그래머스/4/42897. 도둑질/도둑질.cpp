#include <bits/stdc++.h>
using namespace std;
#define S 1'000'002

int n, dp[S];

int solution(vector<int> money) {
    int res = 0;
    n = money.size();
    dp[0] = money[0];
    dp[1] = max(money[0], money[1]);
    for(int i=2;i<n;i++)
        dp[i] = max(dp[i-1], dp[i-2] + money[i]);
    res = dp[n-2];
    
    fill(dp, dp+S, 0);
    dp[1] = money[1];
    for(int i=2;i<n;i++)
        dp[i] = max(dp[i-1], dp[i-2] + money[i]);
    res = max(res, dp[n-1]);
    return res;
}