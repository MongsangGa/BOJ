#include <bits/stdc++.h>

using namespace std;

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define SIZE 502
#define INF 1e9
#define P pair<int,int>

int n, m, d[SIZE * SIZE];
char board[SIZE][SIZE];
vector<P > adj[SIZE * SIZE];
priority_queue<P, vector<P >, greater<>> pq;

int idx(int a, int b) {
    return a * SIZE + b;
}

void add(int a, int b, int cost) {
    adj[a].push_back({cost, b});
    adj[b].push_back({cost, a});
}

int main() {
    fastio;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> board[i][j];
            if (board[i][j] == '/') {
                add(idx(i - 1, j), idx(i, j - 1), 0);
                add(idx(i - 1, j - 1), idx(i, j), 1);
            } else {
                add(idx(i - 1, j), idx(i, j - 1), 1);
                add(idx(i - 1, j - 1), idx(i, j), 0);
            }
        }
    }
    fill(d, d + (SIZE * SIZE), INF);
    pq.push({0, idx(0, 0)});
    d[idx(0, 0)] = 0;
    while (!pq.empty()) {
        auto [cost, cur] = pq.top();
        pq.pop();
        if (d[cur] != cost) continue;
        for (auto nxt: adj[cur]) {
            if (d[nxt.second] <= d[cur] + nxt.first) continue;
            d[nxt.second] = d[cur] + nxt.first;
            pq.push({d[nxt.second], nxt.second});
        }
    }
    int res = d[idx(n, m)];
    if (res == INF) cout << "NO SOLUTION";
    else cout << res;
    return 0;
}
