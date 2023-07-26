#include<bits/stdc++.h>

using namespace std;

const int cost[4][4] = {{100, 70, 40, 0},
                        {70,  50, 30, 0},
                        {40,  30, 20, 0},
                        {0,   0,  0,  0}};

#define MAX 12

int N, arr[MAX][MAX], dp[MAX][MAX][1 << MAX], NOW, RIGHT, OUT;
char c;

int go(int i, int j, int visit) {
    int &res = dp[i][j][visit];
    if (res) return res;
    if (i == N) return res = 0;
    if (j == N) return res = go(i + 1, 0, visit);

    if (!(visit & NOW)) {
        int a, b;
        // 오른쪽
        if (!(visit & RIGHT) && j + 1 < N) {
            a = arr[i][j], b = arr[i][j + 1];
            res = max(res, go(i, j + 2, (visit << 2) % OUT) + cost[a][b]);
        }
        // 아래쪽
        if (!(visit & 1) && i + 1 < N) {
            a = arr[i][j], b = arr[i + 1][j];
            res = max(res, go(i, j + 1, ((visit | 1) << 1) % OUT) + cost[a][b]);
        }
    }
    // 넘어감
    res = max(res, go(i, j + 1, (visit << 1) % OUT));
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> c;
            arr[i][j] = c == 'F' ? 3 : c - 'A';
        }
    }
    NOW = 1 << N, RIGHT = 1 << (N - 1), OUT = 1 << (N + 1);
    cout << go(0, 0, 0);
    return 0;
}
