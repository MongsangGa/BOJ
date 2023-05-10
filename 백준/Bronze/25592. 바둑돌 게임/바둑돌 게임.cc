#include <bits/stdc++.h>
using namespace std;
int n,cnt=1;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    while(n>=cnt){
        n-=cnt;
        cnt++;
    }
    if(cnt&1) cout<<cnt-n;
    else cout<<"0";
    return 0;
}