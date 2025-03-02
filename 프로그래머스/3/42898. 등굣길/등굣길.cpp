#include <bits/stdc++.h>
using namespace std;
#define MOD 1'000'000'007

int dp[102][102];

int solution(int m, int n, vector<vector<int>> puddles) {
    for(auto p:puddles) 
        dp[p[1]][p[0]] = -1;
    dp[1][1] = 1;
    for(int i=1;i<=n;i++) 
        for(int j=1;j<=m;j++) {
            if(i == 1 && j == 1) continue;
            if(dp[i][j] == -1) dp[i][j] = 0;
            else if(dp[i][j] != -1) dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
        }
    return dp[n][m];
}