#include <bits/stdc++.h>

using namespace std;
#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)
#define pii pair<int,int>
#define tui tuple<int,int,int>
#define SIZE 105
#define INF 1e7

int t, n, m, d[SIZE][SIZE], temp[SIZE][SIZE], dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
char board[SIZE][SIZE];
vector<pii > st;

void BFS(pii s) {
    fill(temp[0], temp[SIZE - 1], INF);
    priority_queue<tui, vector<tui >, greater<>> q;
    q.push({0, s.first, s.second}), temp[s.first][s.second] = 0;
    while (!q.empty()) {
        auto [cost, x, y] = q.top();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx > n + 1 || ny > m + 1 || temp[nx][ny] != INF || board[nx][ny] == '*') continue;
            if (board[nx][ny] == '#') temp[nx][ny] = cost + 1;
            else temp[nx][ny] = cost;
            q.push({temp[nx][ny], nx, ny});
        }
    }
    for (int i = 0; i <= n + 1; i++)
        for (int j = 0; j <= m + 1; j++)
            d[i][j] += temp[i][j];
}

int main() {
    fastio;
    cin >> t;
    while (t--) {
        st.clear();
        fill(d[0], d[SIZE - 1], 0);
        fill(board[0], board[SIZE - 1], ' ');
        st.push_back({0, 0});
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> board[i][j];
                if (board[i][j] == '$')
                    st.push_back({i, j});
            }
        }
        for (auto s: st)
            BFS(s);
        int res = INF;
        for (int i = 0; i <= n + 1; i++) {
            for (int j = 0; j <= m + 1; j++) {
                if (board[i][j] == '*') continue;
                if (board[i][j] == '#') d[i][j] -= 2;
                res = min(res, d[i][j]);
            }
        }
        cout << res << '\n';
    }
    return 0;
}
