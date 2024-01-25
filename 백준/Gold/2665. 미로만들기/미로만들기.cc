#include <bits/stdc++.h>

using namespace std;

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define SIZE 51
#define INF 1e9
int n, d[SIZE][SIZE], dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
char board[SIZE][SIZE];
deque<pair<int, int>> dq;

int main() {
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> board[i];
    fill(d[0], d[SIZE - 1], INF);
    dq.push_back({0, 0});
    d[0][0] = 0;
    while (!dq.empty()) {
        auto [x, y] = dq.front();
        dq.pop_front();
        if (x == n - 1 && y == n - 1) break;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (board[nx][ny] == '0' && (d[nx][ny] > d[x][y] + 1)) {
                d[nx][ny] = d[x][y] + 1;
                dq.push_back({nx, ny});
            } else if (board[nx][ny] == '1' && (d[nx][ny] > d[x][y])) {
                d[nx][ny] = d[x][y];
                dq.push_front({nx, ny});
            }
        }
    }
    cout << d[n - 1][n - 1];
    return 0;
}
