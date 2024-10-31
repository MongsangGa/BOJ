#include <bits/stdc++.h>
using namespace std;

#define SIZE 100'002
bool on[SIZE];
vector<int> adj[SIZE];

void DFS(int now, int parent) {
    for(auto nxt:adj[now]) {
        if(nxt == parent) continue;
        DFS(nxt, now);
        if(!on[now] && !on[nxt])
            on[now] = 1;
    }
}

int solution(int n, vector<vector<int>> lighthouse) {
    for(auto cur:lighthouse) {
        adj[cur[0]].push_back(cur[1]);
        adj[cur[1]].push_back(cur[0]);
    }
    DFS(1, -1);
    int answer = accumulate(on+1, on+n+1, 0);
    return answer;
}