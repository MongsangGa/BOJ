#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 103

int n, arr[SIZE][SIZE], islandN[SIZE][SIZE], vis[SIZE][SIZE], islandCnt = 1, res = 1e9;
int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};

void Number(int sx, int sy, int num) {
    queue<pair<int, int>> q;
    q.push({sx, sy});
    islandN[sx][sy] = num;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n || !arr[nx][ny] || islandN[nx][ny]) continue;
            q.push({nx, ny}), islandN[nx][ny] = num;
        }
    }
}

int connectIsland(int num) {
    int ans = 0;
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (islandN[i][j] == num)
                q.push({i, j}), vis[i][j] = 1;
    while (!q.empty()) {
        int qS = q.size();
        while (qS--) {
            auto [x, y] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx >= n || ny >= n || vis[nx][ny]) continue;
                if (arr[nx][ny] && islandN[nx][ny] != num) return ans;
                q.push({nx, ny}), vis[nx][ny] = 1;
            }
        }
        ++ans;
    }
}

int main() {
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (arr[i][j] && !islandN[i][j])
                Number(i, j, islandCnt++);
    for (int i = 1; i < islandCnt; i++) {
        fill(vis[0], vis[SIZE - 1], 0);
        res = min(res, connectIsland(i));
    }
    cout << res;
    return 0;
}

