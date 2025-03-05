#include <bits/stdc++.h>
using namespace std;

int res;
vector<int> I;
vector<int> E[20];

void DFS(int now, int sheep, int wolf, queue<int> q) {
    if(I[now]) ++wolf;
    else ++sheep;
    if(wolf >= sheep) return;
    if(res < sheep) res = sheep;
    for(int nxt:E[now]) 
        q.push(nxt);
    int qs = q.size();
    while(qs--) {
        int nxt = q.front();
        q.pop();
        DFS(nxt, sheep, wolf, q);
        q.push(nxt);
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    for(auto e:edges) E[e[0]].push_back(e[1]);
    I = info;
    queue<int> q;
    DFS(0, 0, 0, q);
    return res;
}