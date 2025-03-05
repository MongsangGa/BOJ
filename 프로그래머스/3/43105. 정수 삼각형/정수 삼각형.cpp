#include <bits/stdc++.h>
using namespace std;

int dp[505][505];

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    dp[0][0] = triangle[0][0];
    for(int i=1;i<triangle.size();i++) {
        for(int j=0;j<=i;j++) {
            if(j-1 >= 0) dp[i][j] = max(dp[i][j], dp[i-1][j-1] + triangle[i][j]);
            if(j <= i-1) dp[i][j] = max(dp[i][j], dp[i-1][j] + triangle[i][j]);
        }
    }
    for(int j=0;j<triangle.size();j++)
        answer = max(answer, dp[triangle.size()-1][j]);
    return answer;
}