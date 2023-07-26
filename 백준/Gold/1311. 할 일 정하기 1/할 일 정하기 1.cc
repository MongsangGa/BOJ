#include<bits/stdc++.h>

using namespace std;

#define INF 10000001
#define MAX 21

int N, arr[MAX][MAX], dp[1 << 20];

int go(int visit, int now) { // cycle
    if (now == N) {
        if (visit == (1 << N) - 1) return 0;
        return INF;
    }
    int &res = dp[visit];
    if (res) return res;
    res = INF;
    for (int i = 0; i < N; i++) {
        if (visit & 1 << i) continue;
        res = min(res, go(visit | 1 << i, now + 1) + arr[now][i]);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> arr[i][j];
    cout << go(0, 0);
    return 0;
}
