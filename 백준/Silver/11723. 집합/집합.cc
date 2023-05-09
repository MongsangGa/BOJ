#include <bits/stdc++.h>
using namespace std;
int t,n;
bool chk[21];
string str;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    while(t--){
        cin>>str;
        if(str!="all" && str!="empty") cin>>n;
        if(str=="add") chk[n]=1;
        else if(str=="remove") chk[n]=0;
        else if(str=="check"){
            if(chk[n]==1) cout<<"1\n";
            else cout<<"0\n";
        }
        else if(str=="toggle"){
            if(chk[n]==1) chk[n]=0;
            else chk[n]=1;
        }
        else if(str=="all") memset(chk,1,21);
        else if(str=="empty") memset(chk,0,21);
    }
    return 0;
}