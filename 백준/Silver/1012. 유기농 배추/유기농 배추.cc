#include<bits/stdc++.h>

using namespace std;

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define SIZE 52
int t, n, m, k, board[SIZE][SIZE], vis[SIZE][SIZE], dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
queue<pair<int, int>> q;
vector<pair<int, int>> bug;

int main() {
    fastio;
    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        int res = 0;
        bug.clear();
        fill(vis[0], vis[SIZE - 1], 0);
        fill(board[0], board[SIZE - 1], 0);
        while (k--) {
            int a, b;
            cin >> a >> b;
            board[a][b] = 1;
            if (board[a][b] == 1)
                bug.push_back({a, b});
        }
        for (auto [bugX, bugY]: bug) {
            if (vis[bugX][bugY]) continue;
            q.push({bugX, bugY});
            vis[bugX][bugY] = 1;
            res++;
            while (!q.empty()) {
                int x, y;
                tie(x, y) = q.front();
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i], ny = y + dy[i];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= m || vis[nx][ny] || !board[nx][ny]) continue;
                    q.push({nx, ny});
                    vis[nx][ny] = 1;
                }
            }
        }
        cout << res << '\n';
    }
    return 0;
}
