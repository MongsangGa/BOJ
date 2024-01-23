#include <bits/stdc++.h>

using namespace std;

#define SIZE 201
#define INF 1e9
int n, m, d[SIZE][SIZE];
vector<tuple<int, int, int>> e;
double res = INF;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    fill(d[0], d[n + 1], INF);
    for (int i = 1; i <= n; i++) d[i][i] = 0;
    while (m--) {
        int a, b, t;
        cin >> a >> b >> t;
        e.push_back({a, b, t});
        d[a][b] = d[b][a] = min(d[a][b], t);
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    for (int st = 1; st <= n; st++) {
        double temp = 0;
        for (auto [a, b, t]: e) {
            int diff = abs(d[st][a] - d[st][b]); // st 노드에서 출발했을 때 a 노드와 b 노드의 도착 시간차
            if (diff > t) temp = max(temp, min(d[st][a], d[st][b]) + (double) t);
            else temp = max(temp, min(d[st][a], d[st][b]) + diff + (double) (t - diff) / 2);
        }
        res = min(temp, res);
    }
    printf("%.1lf", res);
    return 0;
}
