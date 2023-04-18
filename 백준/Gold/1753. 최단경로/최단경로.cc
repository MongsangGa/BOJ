#include<bits/stdc++.h>
using namespace std;
#define INF 1e9+1
int n,m,k,v,a,b,d[20005];
vector<pair<int, int>> node[20005];
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
int main(){
    scanf("%d%d%d",&n,&m,&k);
    fill(d,d+n+1,INF);
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&a,&b,&v);
        node[a].push_back({v,b}); // cost, end
    }
    d[k]=0;
    pq.push({d[k],k});
    while(!pq.empty()){
        auto cur=pq.top(); pq.pop();
        int idx,cost; tie(cost,idx)=cur;
        if(d[idx]!=cost) continue;// 이전에 최소값이 들어간 경우
        for(auto nxt:node[idx]){
            int nidx,ncost; tie(ncost,nidx)=nxt;
            if(d[nidx]>cost+ncost){
                d[nidx]=cost+ncost;
                pq.push({d[nidx], nidx});
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(d[i]==INF) printf("INF\n");
        else printf("%d\n",d[i]);
    }
    return 0;

}
