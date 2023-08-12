#include <bits/stdc++.h>

using namespace std;

#define MAX 101

int n, arr[MAX][MAX], last, dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1}, cnt, res;
bool chk[MAX][MAX];
queue<pair<int, int>> q;

void BFS(int last) {
    chk[q.front().first][q.front().second] = 1;
    while (!q.empty()) {
        int x, y;
        tie(x, y) = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n || arr[nx][ny] <= last || chk[nx][ny]) continue;
            chk[nx][ny] = 1;
            q.push({nx, ny});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            last = max(last, arr[i][j]);
        }
    }
    while (last--) {
        memset(chk, 0, sizeof(chk));
        cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[i][j] > last && !chk[i][j]) {
                    q.push({i, j});
                    BFS(last);
                    cnt++;
                }
            }
        }
        res = max(res, cnt);
    }
    cout << res;
}
