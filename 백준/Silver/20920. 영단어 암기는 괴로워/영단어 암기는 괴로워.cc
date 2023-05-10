#include <bits/stdc++.h>
using namespace std;
int n,m;
string s;
unordered_map<string, int> um;
bool cmp(pair<string, int> &a, pair<string, int> &b){
    if(a.second==b.second){
        if(a.first.length()==b.first.length())
            return (a.first<b.first);
        return (a.first.length()>b.first.length());
    }
    return (a.second>b.second);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>s;
        if(s.length()>=m)
            um[s]++;
    }
    vector<pair<string, int>> v(um.begin(),um.end());
    sort(v.begin(),v.end(),cmp);
    for(auto i:v)
        cout<<i.first<<'\n';
    return 0;
}