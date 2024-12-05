#include<bits/stdc++.h>

using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define S 1'002

bool vis[S][S];
char board[S][S];
int n, m, p, s[12], res[12];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
queue<pair<int, int>> q[12];

int main() {
    fastio;
    cin >> n >> m >> p;
    for (int i = 1; i <= p; i++)
        cin >> s[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] != '.' && board[i][j] != '#')
                q[board[i][j] - '0'].push({i, j});
        }

    while (true) {
        char before[S][S];
        memcpy(before, board, sizeof board);
        int turn = 1;
        while (turn <= p) {
            fill(vis[0], vis[S - 1], 0);
            for (int step = 0; step < s[turn]; step++) {
                int qs = q[turn].size();
                if (qs == 0) break;
                for (int k = 0; k < qs; k++) {
                    auto [x, y] = q[turn].front();
                    q[turn].pop();
                    for (int i = 0; i < 4; i++) {
                        int nx = x + dx[i], ny = y + dy[i];
                        if (nx < 0 || ny < 0 || nx >= n || ny >= m || vis[nx][ny] || board[nx][ny] != '.') continue;
                        q[turn].push({nx, ny});
                        board[nx][ny] = turn + '0';
                        vis[nx][ny] = 1;
                    }
                }
            }
            ++turn;
        }
        int flag = 0;
        for (int i = 0; i < n; i++)
            if (!strcmp(before[i], board[i]))
                ++flag;
        if (flag == n) break;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (board[i][j] != '.' && board[i][j] != '#')
                ++res[board[i][j] - '0'];
    for (int i = 1; i <= p; i++)
        cout << res[i] << ' ';
    return 0;
}
