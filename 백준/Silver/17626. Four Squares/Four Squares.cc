#include <bits/stdc++.h>
using namespace std;
#define MAX 50001
int n;
vector<int> dp(MAX,1e7);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=1;i<=n;i++)
        if((int)sqrt(i)*(int)sqrt(i)==i) dp[i]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sqrt(i);j++)
            dp[i]=min(dp[i],dp[j*j]+dp[i-j*j]);
    }
    cout<<dp[n];
    return 0;
}
