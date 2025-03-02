#include <bits/stdc++.h>
using namespace std;
#define MOD 1'000'000'007
int dp[100'002];

int solution(int n, vector<int> money) {
    dp[0] = 1;
    for(int m:money) 
        for(int i=m;i<=n;i++)
            dp[i] += dp[i-m] % MOD;
    return dp[n];
}