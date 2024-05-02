#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)
#define ti tuple<int,int,int>
#define SIZE 102
#define INF 1e9
int t, n, m, k, d[SIZE][10'002];
vector<ti > adj[SIZE];
queue<ti > q;

int main() {
    fastio;
    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        for (int i = 0; i < SIZE; i++) adj[i].clear();
        while (k--) {
            int a, b, cost, time;
            cin >> a >> b >> cost >> time;
            adj[a].push_back({time, cost, b});
        }
        fill(&d[0][0], &d[SIZE - 1][10'001], INF);
        q.push({0, 0, 1});
        d[1][0] = 0;
        while (!q.empty()) {
            auto [curT, curC, curN] = q.front();
            q.pop();
            if (curT > d[curN][curC]) continue;
            for (auto [nxtT, nxtC, nxtN]: adj[curN]) {
                nxtC += curC, nxtT += curT;
                if (nxtC <= m && d[nxtN][nxtC] > nxtT) {
                    for (int i = nxtC; i <= m; i++) {
                        if (d[nxtN][i] > nxtT)
                            d[nxtN][i] = nxtT;
                        else break;
                    }
                    q.push({nxtT, nxtC, nxtN});
                }
            }
        }
        int res = INF;
        for (int i = 0; i <= m; i++)
            if (d[n][i] < res)
                res = d[n][i];
        if (res == INF) cout << "Poor KCM\n";
        else cout << res << '\n';
    }
    return 0;
}
