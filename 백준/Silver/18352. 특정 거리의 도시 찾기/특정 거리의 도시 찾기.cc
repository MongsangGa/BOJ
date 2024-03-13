#include <bits/stdc++.h>

using namespace std;
#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)
#define pii pair<int,int>
#define SIZE 300'002
#define INF 1e9

int n, m, k, st, d[SIZE];
vector<pii > adj[SIZE];
priority_queue<pii, vector<pii >, greater<>> pq;

int main() {
    fastio;
    cin >> n >> m >> k >> st;
    fill(d, d + SIZE, INF);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back({1, b});
    }
    d[st] = 0, pq.push({d[st], st});
    while (!pq.empty()) {
        auto [nowC, nowI] = pq.top();
        pq.pop();
        if (d[nowI] != nowC) continue;
        for (auto [nxtC, nxtI]: adj[nowI]) {
            if (d[nxtI] <= d[nowI] + nxtC) continue;
            d[nxtI] = d[nowI] + nxtC;
            pq.push({d[nxtI], nxtI});
        }
    }
    vector<int> res;
    for (int i = 1; i <= n; i++)
        if (d[i] == k) res.push_back(i);
    if (res.empty()) cout << -1;
    else for (auto r: res) cout << r << '\n';
    return 0;
}
