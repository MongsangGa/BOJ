#include <bits/stdc++.h>
using namespace std;
#define S 202

int N, res;
bool vis[S];
vector<vector<int>> adj;

void DFS(int now) {
    vis[now] = 1;
    for(int nxt=0;nxt<N;nxt++) {
        if(nxt==now || vis[nxt]) continue;
        if(adj[now][nxt]) DFS(nxt);
    }
}

int solution(int n, vector<vector<int>> computers) {
    N = n; adj = computers;
    for(int i=0;i<n;i++) {
        if(vis[i]) continue;
        DFS(i); ++res;
    }
    return res;
}