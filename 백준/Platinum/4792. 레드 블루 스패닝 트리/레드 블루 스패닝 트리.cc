#include<bits/stdc++.h>
using namespace std;
int n,m,k,a,b,v;
char c;
vector<int> p(1002,-1);
int find(int x){
    if(p[x]<0) return x;
    return p[x]=find(p[x]);
}
bool is_diff_group(int u, int v){
    u=find(u); v=find(v);
    if(u==v) return 0;
    if(p[u]>p[v]) swap(u,v);
    p[u]+=p[v];
    p[v]=u;
    return 1;
}
int Kruskal(vector<tuple<int,int,int>>& edge){
    sort(edge.begin(),edge.end());
    int cnt=0,res=0;
    for(int i=0;i<m;i++){
        int cost,a,b;
        tie(cost,a,b)=edge[i];
        if(!is_diff_group(a,b)) continue;
        cnt++;
        res+=cost;
        if(cnt==n) break;
    }
    return res;
}
int main(){
    while(1){
        vector<tuple<int,int,int>> max_blue_edge, min_blue_edge; // 최대 파란 간선, 최소 파란 간선
        scanf("%d%d%d",&n,&m,&k);
        if(!n && !m && !k) break;
        for(int i=0;i<m;i++){
            cin>>c>>a>>b;
            if(c=='B') { // 파란 간선이면
                max_blue_edge.push_back({0,a,b});
                min_blue_edge.push_back({1,a,b});
            }else { // 빨간 간선이면
                max_blue_edge.push_back({1,a,b});
                min_blue_edge.push_back({0,a,b});
            }
        }
        fill(p.begin(),p.end(),-1);
        int min_blue=Kruskal(min_blue_edge);
        fill(p.begin(),p.end(),-1);
        int max_blue=(n-1)-Kruskal(max_blue_edge);
        if(min_blue<=k && k<=max_blue) printf("1\n");
        else printf("0\n");
    }
    return 0;
}
