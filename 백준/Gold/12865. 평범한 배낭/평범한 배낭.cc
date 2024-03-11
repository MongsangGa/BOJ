#include<stdio.h>
#include<algorithm>
using namespace std;
int k[101],v[101],dp[101][100001];
int main(){
    int n,maxk;
    scanf("%d %d",&n,&maxk);
    for(int i=0;i<n;i++)
        scanf("%d %d",&k[i+1],&v[i+1]);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=maxk;j++){
            if(j<k[i]) dp[i][j]=dp[i-1][j];
            else dp[i][j]=max(dp[i-1][j],v[i]+dp[i-1][j-k[i]]);
        }
    }  
    printf("%d ",dp[n][maxk]);
    return 0;
}