#include <bits/stdc++.h>

using namespace std;

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define SIZE 301
#define INF 1e9
#define X first
#define Y second

int n, m, d[SIZE][SIZE], dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
char board[SIZE][SIZE];
pair<int, int> st, en;
deque<pair<int, int>> dq;

int main() {
    fastio;
    cin >> n >> m;
    cin >> st.X >> st.Y >> en.X >> en.Y;
    st.X--, st.Y--, en.X--, en.Y--;
    for (int i = 0; i < n; i++) cin >> board[i];
    fill(d[0], d[SIZE], INF);
    d[st.X][st.Y] = 0;
    dq.push_back({st.X, st.Y});
    while (!dq.empty()) {
        auto [x, y] = dq.front();
        dq.pop_front();
        if (x == en.X && y == en.Y) break;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (board[nx][ny] == '0' && d[nx][ny] > d[x][y]) {
                d[nx][ny] = d[x][y];
                dq.push_front({nx, ny});
            } else {
                if (d[nx][ny] > d[x][y] + 1) {
                    d[nx][ny] = d[x][y] + 1;
                    dq.push_back({nx, ny});
                }
            }
        }
    }
    cout << d[en.X][en.Y];
    return 0;
}
