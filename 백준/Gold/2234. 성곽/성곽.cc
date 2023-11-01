#include <bits/stdc++.h>

using namespace std;

#define MAX 51
int n, m, arr[MAX][MAX], chk[MAX][MAX], roomCnt, res1, res2, dx[] = {0, -1, 0, 1}, dy[] = {-1, 0, 1, 0};

int BFS(int x, int y) {
    int room = 1;
    chk[x][y] = 1;
    queue<pair<int, int>> q;
    q.push({x, y});
    while (!q.empty()) {
        int x, y;
        tie(x, y) = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m || chk[nx][ny] || arr[x][y] & (1 << i)) continue;
            q.push({nx, ny});
            chk[nx][ny] = 1;
            room++;
        }
    }
    return room;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> m >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (!chk[i][j])
                res1 = max(res1, BFS(i, j)), roomCnt++;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int bit = 1; bit <= 8; bit <<= 1) {
                if (arr[i][j] & bit) {
                    memset(chk, 0, sizeof(chk));
                    arr[i][j] -= bit;
                    res2 = max(res2, BFS(i, j));
                    arr[i][j] += bit;
                }
            }
        }
    }
    cout << roomCnt << '\n' << res1 << '\n' << res2;
    return 0;
}
