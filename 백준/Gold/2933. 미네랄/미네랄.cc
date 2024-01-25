#include <bits/stdc++.h>

using namespace std;

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define SIZE 102
#define INF 1e9
int r, c, n, target, chk[SIZE][SIZE], dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
string board[SIZE];

int main() {
    fastio;
    cin >> r >> c;
    for (int i = 0; i < r; i++) cin >> board[i];
    cin >> n;
    for (int angle = 0; angle < n; angle++) {
        cin >> target;
        // 미네랄 깨기
        if (angle & 1) { // right
            int idx = c - 1;
            while (board[r - target][idx] == '.' && idx >= 0) idx--;
            if (idx >= 0) board[r - target][idx] = '.';
        } else { // left
            int idx = 0;
            while (board[r - target][idx] == '.' && idx < c) idx++;
            if (idx < c) board[r - target][idx] = '.';
        }
        // 바닥 미네랄 체크
        fill(chk[0], chk[SIZE - 1], 0);
        for (int i = 0; i < c; i++) {
            queue<pair<int, int>> q;
            if (chk[r - 1][i] || board[r - 1][i] == '.') continue;
            q.push({r - 1, i});
            chk[r - 1][i] = 1;
            while (!q.empty()) {
                auto cur = q.front();
                q.pop();
                for (int j = 0; j < 4; j++) {
                    int nx = cur.first + dx[j], ny = cur.second + dy[j];
                    if (nx < 0 || ny < 0 || nx >= r || ny >= c || chk[nx][ny] || board[nx][ny] == '.') continue;
                    q.push({nx, ny});
                    chk[nx][ny] = 1;
                }
            }
        }
        // 높이 구하기
        int height = INF;
        for (int i = 0; i < c; i++) {
            int height1 = r - 1;
            while (height1 >= 0 && (chk[height1][i] || board[height1][i] == '.')) height1--;
            if (height1 < 0) continue;
            int height2 = height1 + 1;
            while (height2 < r && !chk[height2][i]) height2++;
            height = min(height, height2 - height1 - 1);
        }
        if (height == INF) continue;
        // 떨어트리기
        for (int j = c - 1; j >= 0; j--) {
            for (int i = r - 1; i >= 0; i--) {
                if (board[i][j] == '.' || chk[i][j]) continue;
                board[i][j] = '.';
                board[i + height][j] = 'x';
                chk[i + height][j] = 1;
            }
        }
    }
    for (int i = 0; i < r; i++) cout << board[i] << '\n';
    return 0;
}
