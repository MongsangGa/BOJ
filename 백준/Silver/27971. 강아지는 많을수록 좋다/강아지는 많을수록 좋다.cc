#include <bits/stdc++.h>
using namespace std;
int n,m,a,b,x,y,l=100001,r=1,dp[100001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    scanf("%d%d%d%d",&n,&m,&a,&b);
    fill(dp,dp+100001,100002);
    while(m--){
        scanf("%d%d",&x,&y);
        for(int i=x;i<=y;i++)
            dp[i]=-1;
    }
    dp[0]=0;
    for(int i=0;i<n;i++){
        if(dp[i]==-1) continue;
        if(i+a<=n && dp[i+a]!=-1)
            dp[i+a]=min(dp[i+a],dp[i]+1);
        if(i+b<=n && dp[i+b]!=-1)
            dp[i+b]=min(dp[i+b],dp[i]+1);
    }
    if(dp[n]==100002) printf("-1");
    else printf("%d",dp[n]);
    return 0;
}