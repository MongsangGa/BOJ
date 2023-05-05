#include <bits/stdc++.h>
using namespace std;
string Si;
int n,m,a,temp,res=1e9;
bool channel[10];
bool check(int target){
    string s= to_string(target);
    for(int i=0;i<s.size();i++){
        if(channel[s[i]-'0'])
            return false;
    }
    return true;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a;
        channel[a]=true;
    }
    res=min(res,(abs(n-100))); // 채널 N으로 +, -만을 이용
    for(int i=0;i<1e6+1;i++){
        if(check(i)){
            temp=abs(n-i)+to_string(i).size();
            res = min(res, temp);
        }
    }
    cout<<res;
    return 0;
}