#include<bits/stdc++.h>

using namespace std;

#define SIZE 303
int n, m, arr[SIZE][SIZE], chk[SIZE][SIZE], dX[] = {0, -1, 0, 1}, dY[] = {-1, 0, 1, 0};

void DFS(int x, int y, int t) {
    int cnt = 0;
    chk[x][y] = t;
    for (int i = 0; i < 4; i++) {
        int nX = x + dX[i], nY = y + dY[i];
        if (chk[nX][nY] == t) continue;
        if (arr[nX][nY] <= 0) cnt++;
        else DFS(nX, nY, t);
    }
    arr[x][y] -= cnt;
}

int solve() {
    int time = 1;
    while (time) {
        int island = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j] > 0 && chk[i][j] != time) {
                    island++;
                    DFS(i, j, time);
                }
            }
        }
        if (!island) return 0;
        if (island > 1) return time - 1;
        time++;
    }
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    cout << solve();
    return 0;
}
