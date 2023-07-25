#include<bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f

int n, w[17][17], dp[17][1 << 16];

int go(int now, int visited) {
    if (visited == (1 << n) - 1) {
        if (w[now][0]) return w[now][0]; // 사이클이기 때문에 1번만 체크
        return INF;
    }
    int &res = dp[now][visited];
    if (res) return res;
    res = INF;
    for (int i = 0; i < n; i++) {
        if (!(visited & 1 << i) && w[now][i])
            res = min(res, go(i, visited | 1 << i) + w[now][i]);
    }
    return res;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> w[i][j];
    cout << go(0, 1);
    return 0;
}
