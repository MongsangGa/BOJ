#include <bits/stdc++.h>

using namespace std;

#define SIZE 401
#define INF 1e9
int n, m, d[SIZE][SIZE], res = INF;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    fill(d[0], d[n + 1], INF);
    // for (int i = 1; i <= n; i++) d[i][i] = 0;
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        d[a][b] = c;
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            res = min(res, d[i][j] + d[j][i]);
    if (res >= INF) cout << "-1";
    else cout << res;
    return 0;
}
