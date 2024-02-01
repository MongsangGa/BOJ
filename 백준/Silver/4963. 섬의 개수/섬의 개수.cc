#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(false);
#define SIZE 52
int n, m, board[SIZE][SIZE], vis[SIZE][SIZE], dx[] = {-1, 0, 1, 0, -1, -1, 1, 1}, dy[] = {0, -1, 0, 1, -1, 1, -1, 1};
queue<pair<int, int>> q;

int main() {
    fastio;
    while (1) {
        cin >> m >> n;
        if (!n && !m) break;
        fill(board[0], board[SIZE - 1], 0);
        fill(vis[0], vis[SIZE - 1], 0);
        vector<pair<int, int>> start;
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> board[i][j];
                if (board[i][j])
                    start.push_back({i, j});
            }
        }
        for (auto [sX, sY]: start) {
            if (vis[sX][sY]) continue;
            res++;
            vis[sX][sY] = 1;
            q.push({sX, sY});
            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();
                for (int i = 0; i < 8; i++) {
                    int nx = x + dx[i], ny = y + dy[i];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                    if (vis[nx][ny] || !board[nx][ny]) continue;
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
        cout << res << '\n';
    }
    return 0;
}
