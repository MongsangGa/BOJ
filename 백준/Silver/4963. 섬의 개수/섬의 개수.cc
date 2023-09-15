#include<bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
#define MAX 51

int n, m, num, board[MAX][MAX], dx[] = {-1, 0, 1, 0, 1, 1, -1, -1}, dy[] = {0, -1, 0, 1, 1, -1, 1, -1};

void solve(int x, int y) {
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= n || ny >= m || !board[nx][ny]) continue;
        board[nx][ny] = 0;
        solve(nx, ny);
    }
}

int main() {
    while (1) {
        num = 0;
        queue<pii> q;
        cin >> m >> n;
        if (!n && !m) break;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> board[i][j];
                if (board[i][j])
                    q.push({i, j});
            }
        }
        while (!q.empty()) {
            int x, y;
            tie(x, y) = q.front();
            q.pop();
            if (!board[x][y]) continue;
            num++;
            board[x][y] = 0;
            solve(x, y);
        }
        cout << num << '\n';
    }
    return 0;
}
