#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v[22];
int n,a,chk[22],res;
int solve(int X){
    if(X>=n*2) return 0;
    int cnt=0;
    for(int i=0;i<v[X].size();i++){
        int a,b; tie(a,b)=v[X][i];
        if(!chk[a-b+n]){
            chk[a-b+n]=1;
            cnt=max(cnt,solve(X+2)+1);
            chk[a-b+n]=0;
        }
    }
    cnt=max(cnt,solve(X+2));
    return cnt;
    // i+j, i-j로 대각선 판별가능
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&a);
            if(a==1)
                v[i+j].push_back({i,j});
        }
    }
    printf("%d",solve(0)+solve(1));
    return 0;
}
