#include <bits/stdc++.h>
using namespace std;
int n,m,ind[32001];
queue<int> q;
vector<int> v[32001];
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    while(m--){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        ind[b]++;
    }
    for(int i=1;i<=n;i++){
        if(!ind[i])
            q.push(i);
    }
    while(!q.empty()){
        int cur=q.front(); q.pop();
        cout<<cur<<' ';
        for(int nxt:v[cur]){
            ind[nxt]--;
            if(!ind[nxt])
                q.push(nxt);
        }
    }
    return 0;
}
