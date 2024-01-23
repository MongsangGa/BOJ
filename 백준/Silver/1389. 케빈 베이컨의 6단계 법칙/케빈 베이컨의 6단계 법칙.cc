#include <bits/stdc++.h>

using namespace std;

#define SIZE 101
#define INF 1e9
int n, m, d[SIZE][SIZE], sum[SIZE], res = INF, rIdx;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    fill(d[0], d[n + 1], INF);
    for (int i = 1; i <= n; i++) d[i][i] = 0;
    while (m--) {
        int a, b;
        cin >> a >> b;
        d[a][b] = d[b][a] = 1;
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    for (int i = 1; i <= n; i++) {
        int temp = 0;
        for (int j = 1; j <= n; j++) temp += d[i][j];
        if (res > temp) res = temp, rIdx = i;
    }
    cout << rIdx;
    return 0;
}
