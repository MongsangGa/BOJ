#include <bits/stdc++.h>

using namespace std;

#define SIZE 101
int n, m, arr[SIZE][SIZE], chk[SIZE][SIZE], res, t, dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
queue<pair<int, int>> q, del;

int bfs() {
    int tmp = 0;
    q.push({0, 0});
    chk[0][0] = 1;
    memset(chk, 0, sizeof(chk));
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m || chk[nx][ny]) continue;
            if (arr[nx][ny]) {
                del.push({nx, ny});
                tmp++;
            } else q.push({nx, ny});
            chk[nx][ny] = 1;
        }
    }
    while (!del.empty()) {
        auto [x, y] = del.front();
        del.pop();
        arr[x][y] = 0;
    }
    return tmp;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            res += arr[i][j];
        }
    }
    while (res > 0) {
        int tmp = bfs();
        t++;
        if (res - tmp <= 0)break;
        res -= tmp;
    }
    cout << t << '\n' << res;
    return 0;
}
