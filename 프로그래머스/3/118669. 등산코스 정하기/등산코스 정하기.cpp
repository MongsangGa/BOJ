#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define SIZE 50'005

int d[SIZE], res_summit = 1e9, res_intensity = 1e9;
bool is_summit[SIZE];
vector<pii> adj[SIZE], res;
priority_queue<pii, vector<pii>, greater<>> pq;


vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    for(auto p:paths)
        adj[p[0]].push_back({p[2], p[1]}), adj[p[1]].push_back({p[2], p[0]});
    for(int s:summits)
        is_summit[s] = 1;
    fill(d, d+SIZE, 1e9);
    for(int g:gates) {
        d[g] = 0;
        pq.push({d[g], g});
    }
    while(!pq.empty()) {
        auto now = pq.top();
        pq.pop();
        if(d[now.second] != now.first) continue;
        if(is_summit[now.second]) {
            res.push_back({d[now.second], now.second});
            continue;
        }
        for(auto nxt:adj[now.second]) {
            int nxt_intensity = max(d[now.second], nxt.first);
            if(d[nxt.second] <= nxt_intensity) continue;
            d[nxt.second] = nxt_intensity;
            pq.push({d[nxt.second], nxt.second});
        }
    }
    sort(res.begin(), res.end());
    return {res[0].second, res[0].first};
}