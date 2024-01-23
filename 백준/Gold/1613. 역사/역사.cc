#include <bits/stdc++.h>

using namespace std;

#define SIZE 401
#define INF 1e9
int n, m, l, d[SIZE][SIZE];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    fill(d[0], d[n + 1], INF);
    for (int i = 1; i <= n; i++) d[i][i] = 0;
    while (m--) {
        int a, b;
        cin >> a >> b;
        d[a][b] = 1;
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    cin >> l;
    while (l--) {
        int a, b;
        cin >> a >> b;
        if (d[a][b] == INF && d[b][a] == INF) cout << "0\n";
        else if (d[a][b] == INF && d[b][a]) cout << "1\n";
        else cout << "-1\n";
    }
    return 0;
}
