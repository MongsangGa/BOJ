#include <bits/stdc++.h>
using namespace std;
#define S 10'001

bool vis[S*S];
vector<string> res;
vector<vector<string>> ticket;

bool DFS(string now, int cnt) {
    res.push_back(now);
    if(cnt == ticket.size()) return true;
    for(int i=0;i<ticket.size();i++) {
        if(vis[i]) continue;
        if(ticket[i][0] == now) {
            vis[i] = 1;
            bool chk = DFS(ticket[i][1], cnt + 1);
            if(chk) return true;
            vis[i] = 0;
        }
    }
    res.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end());
    ticket = tickets;
    DFS("ICN", 0);
    return res;
}