#include <bits/stdc++.h>
using namespace std;

#define S 20'002

int d[S];
queue<int> q;
vector<int> adj[S];

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    for(int i=0;i<edge.size();i++) {
        int u = edge[i][0], v = edge[i][1];
        adj[u].push_back(v), adj[v].push_back(u);
    }
    fill(d, d+S, 1e9), q.push(1), d[1] = 0;
    int MAX = 0;
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        for(int nxt: adj[now]){
            if(d[nxt] <= d[now] + 1) continue;
            d[nxt] = d[now] + 1, q.push(nxt);
            MAX = max(MAX, d[nxt]);
        }
    }
    for(int i=1;i<=n;i++)
        if(d[i] == MAX)
            ++answer;
    return answer;
}