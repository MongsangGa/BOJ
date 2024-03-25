#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)
const int SIZE = 101;
int n, input[SIZE][SIZE], board[SIZE][SIZE], vis[SIZE][SIZE], island = 0, res = INT_MAX;
int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};

void cnt_island(int x, int y) {
    if (board[x][y]) return;
    queue<pair<int, int>> q;
    ++island;
    board[x][y] = island;
    q.push({x, y});
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i], ny = cur.second + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n || board[nx][ny] || !input[nx][ny]) continue;
            board[nx][ny] = island;
            q.push({nx, ny});
        }
    }
}

int get_dis(int x, int y) {
    fill(vis[0], vis[SIZE - 1], 0);
    int curNum = board[x][y], ans = INT_MAX;
    queue<pair<int, int>> q;
    q.push({x, y});
    vis[x][y] = 1;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i], ny = cur.second + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n || vis[nx][ny] || curNum == board[nx][ny]) continue;
            vis[nx][ny] = vis[cur.first][cur.second] + 1;
            q.push({nx, ny});
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (input[i][j] && curNum != board[i][j] && vis[i][j])
                ans = min(ans, vis[i][j] - 2);
    return ans;
}

int main() {
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> input[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (input[i][j])
                cnt_island(i, j);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (input[i][j])
                res = min(res, get_dis(i, j));
    cout << res;
    return 0;
}
