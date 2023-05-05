#include <bits/stdc++.h>
using namespace std;
int n,arr[3001][3001],res[3];
bool is_able(int x, int y, int term){
    int now=arr[x][y];
    for(int i=x;i<x+term;i++)
        for(int j=y;j<y+term;j++)
            if(now!=arr[i][j])
                return false;
    return true;
}
void solve(int x, int y, int term) {
    if (is_able(x, y, term))
        res[arr[x][y]+1]++;
    else{
        int temp=term/3;
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                solve(x+(i*temp),y+(j*temp),temp);
    }
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&arr[i][j]);
    solve(0,0,n);
    for(int i=0;i<3;i++) printf("%d\n",res[i]);
    return 0;
}