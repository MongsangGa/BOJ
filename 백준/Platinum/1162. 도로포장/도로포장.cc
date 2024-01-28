#include<bits/stdc++.h>

using namespace std;

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define P pair<int,int>
#define T tuple<long long int,int,int>
#define SIZE 10'002
#define INF LLONG_MAX

long long int n, m, k, d[SIZE][22]; // node, k
vector<P > adj[SIZE];
priority_queue<T, vector<T >, greater<>> pq; // cost, k, node

int main() {
    fastio;
    cin >> n >> m >> k;
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }
    fill(d[0], d[SIZE - 1], INF);
    d[1][0] = 0;
    pq.push({0, 0, 1});
    while (!pq.empty()) {
        auto [cCost, cK, cNode] = pq.top();
        pq.pop();
        if (d[cNode][cK] != cCost) continue;
        for (auto [nCost, nNode]: adj[cNode]) {
            if (cK < k && d[nNode][cK + 1] > d[cNode][cK]) {
                d[nNode][cK + 1] = d[cNode][cK];
                pq.push({d[nNode][cK + 1], cK + 1, nNode});
            }
            if (d[nNode][cK] > d[cNode][cK] + nCost) {
                d[nNode][cK] = d[cNode][cK] + nCost;
                pq.push({d[nNode][cK], cK, nNode});
            }
        }
    }
    long long res = INF;
    for (int i = 0; i <= k; i++)
        res = min(res, d[n][i]);
    if (res >= LLONG_MAX) cout << 0;
    else cout << res;
    return 0;
}
