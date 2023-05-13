#include <bits/stdc++.h>
using namespace std;
#define MAX 50001
int n;
string arr[65];
void solve(int now, int x, int y){
    int check=0;
    for(int i=x;i<x+now;i++)
        for(int j=y;j<y+now;j++)
            check+=arr[i][j]-'0';
    if(!check){
        cout<<"0";
        return;
    }
    else if(check==now*now){
        cout<<"1";
        return;
    }
    int next=now/2;
    cout<<"(";
    solve(next, x, y);
    solve(next, x, y+next);
    solve(next, x+next, y);
    solve(next, x+next, y+next);
    cout<<")";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    solve(n,0,0);
    return 0;
}
