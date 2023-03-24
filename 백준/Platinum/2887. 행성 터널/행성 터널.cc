#include<bits/stdc++.h>
using namespace std;
int n,x,y,z,cost,cnt,res;
bool chk[100001];
vector<pair<int,int>> v[100001],a,b,c; //node, cost
vector<tuple<int,int,int>> in;
priority_queue< tuple<int,int,int>,vector<tuple<int,int,int>>, greater<tuple<int,int,int>> > pq; //cost, node, node
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d%d",&x,&y,&z);
        a.push_back({x,i});
        b.push_back({y,i});
        c.push_back({z,i});
    }
    sort(a.begin(),a.end()); sort(b.begin(),b.end()); sort(c.begin(),c.end());
    for(int i=1;i<n;i++){
        v[a[i].second].push_back({a[i-1].second, abs(a[i-1].first-a[i].first)});
        v[b[i].second].push_back({b[i-1].second, abs(b[i-1].first-b[i].first)});
        v[c[i].second].push_back({c[i-1].second, abs(c[i-1].first-c[i].first)});
        v[a[i-1].second].push_back({a[i].second, abs(a[i-1].first-a[i].first)});
        v[b[i-1].second].push_back({b[i].second, abs(b[i-1].first-b[i].first)});
        v[c[i-1].second].push_back({c[i].second, abs(c[i-1].first-c[i].first)});
    }

    chk[1]=1;
    for(auto nxt: v[1])
        pq.push({nxt.second, 1, nxt.first});
    while(cnt<n-1){
        tie(cost,x,y)=pq.top(); pq.pop();
        if(chk[y]) continue;
        res+=cost;
        cnt++;
        chk[y]=1;
        for(auto nxt: v[y]){
            if(!chk[nxt.first])
                pq.push({nxt.second,y,nxt.first});
        }
    }
    printf("%d",res);
    return 0;
}
