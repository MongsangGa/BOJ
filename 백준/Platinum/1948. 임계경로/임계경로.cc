#include <bits/stdc++.h>

using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 10'002
int n, m, st, en, d[SIZE], ind[SIZE], cnt;
bool vis[SIZE][SIZE];
vector<pair<int, int>> adj[SIZE], radj[SIZE];
queue<int> q;

int main() {
    fastio;
    cin >> n >> m;
    while (m--) {
        int a, b, cost;
        cin >> a >> b >> cost;
        adj[a].push_back({b, cost});
        radj[b].push_back({a, cost});
        ind[b]++;
    }
    cin >> st >> en;
    q.push(st);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (auto [nxtI, nxtC]: adj[now]) {
            d[nxtI] = max(d[nxtI], d[now] + nxtC);
            ind[nxtI]--;
            if (!ind[nxtI]) q.push(nxtI);
        }
    }
    q.push(en);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (auto [nxtI, nxtC]: radj[now]) {
            if (d[now] == d[nxtI] + nxtC && !vis[now][nxtI]) {
                vis[now][nxtI] = true;
                cnt++;
                q.push(nxtI);
            }
        }
    }
    cout << d[en] << '\n' << cnt;
    return 0;
}
