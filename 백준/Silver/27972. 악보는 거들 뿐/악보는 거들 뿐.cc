#include <bits/stdc++.h>
using namespace std;
#define MAX 500001
int n,m[MAX],plusminus,cnt=1,res=1; // plusminus => plus=0, minus=1
int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    // 연속되는 증가 또는 감소의 최대치
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&m[i]);
    for(int i=1;i<n;i++){
        if(m[i-1]<m[i]){
            if(!plusminus) cnt++;
            else plusminus=0, cnt=2;
        }
        else if(m[i-1]>m[i]){
            if(plusminus) cnt++;
            else plusminus=1, cnt=2;
        }
        res=max(res,cnt);
    }
    printf("%d",res);
    return 0;
}