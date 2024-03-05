#include <bits/stdc++.h>

using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 101
#define INF 1e9
int n, m, d[SIZE][SIZE], cnt[SIZE], ans;
bool res[SIZE];

int main() {
    fastio;
    cin >> n >> m;
    fill(d[0], d[SIZE - 1], INF);
    while (m--) {
        int a, b;
        cin >> a >> b;
        d[a][b] = 1;
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (d[i][j] != INF)
                cnt[i]++;
    for (int i = 1; i <= n; i++)
        if (cnt[i] > n / 2)
            res[i] = true;
    fill(cnt, cnt + SIZE, 0);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (d[j][i] != INF)
                cnt[i]++;
    for (int i = 1; i <= n; i++)
        if (cnt[i] > n / 2)
            res[i] = true;
    for (int i = 1; i <= n; i++)
        if (res[i])
            ans++;
    cout << ans;
    return 0;
}
