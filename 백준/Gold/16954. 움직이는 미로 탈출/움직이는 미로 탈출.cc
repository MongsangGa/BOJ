#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)
struct p {
    int x, y;
};

char board[8][8];
queue<p> q;
int dx[] = {0, -1, 0, 1, 0, -1, -1, 1, 1}, dy[] = {0, 0, -1, 0, 1, -1, 1, -1, 1};

int main() {
    fastio;
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            cin >> board[i][j];
    q.push({7, 0}); // from(7,0) -> to(0,7)
    while (!q.empty()) {
        int qsize = q.size();
        while (qsize--) {
            auto cur = q.front();
            q.pop();
            if (cur.x == 0) {
                cout << 1;
                return 0;
            }
            for (int i = 0; i < 9; i++) {
                int nx = cur.x + dx[i], ny = cur.y + dy[i];
                if (nx < 0 || ny < 0 || nx >= 8 || ny >= 8) continue;
                if (board[nx][ny] == '#' || board[nx - 1][ny] == '#') continue;
                q.push({nx, ny});
            }
        }
        for (int i = 7; i >= 0; i--) {
            for (int j = 7; j >= 0; j--) {
                if (board[i][j] == '#') {
                    board[i][j] = '.';
                    if (i == 7) continue;
                    board[i + 1][j] = '#';
                }
            }
        }
    }
    cout << 0;
    return 0;
}
