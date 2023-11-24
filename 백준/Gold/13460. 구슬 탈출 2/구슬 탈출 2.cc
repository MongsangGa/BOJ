#include<bits/stdc++.h>

using namespace std;

int n, m, dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1}, res = 1e9;
bool chk[11][11][11][11];
char board[11][11];

void move(int &x, int &y, int dx, int dy, int &dist) {
    while (board[x + dx][y + dy] != '#') {
        x += dx, y += dy, dist++;
        if (board[x][y] == 'O') break;
    }
}

void DFS(int r1, int r2, int b1, int b2, int cnt) {
    if (res <= cnt) return;
    if (cnt > 10) return;
    if (board[b1][b2] == 'O' || (board[r1][r2] == 'O' && board[b1][b2] == 'O')) return;
    if (board[r1][r2] == 'O') {
        res = min(res, cnt);
        return;
    }
    for (int i = 0; i < 4; i++) {
        int nr1, nr2, nb1, nb2, rd, bd;
        nr1 = r1, nr2 = r2, nb1 = b1, nb2 = b2, rd = 0, bd = 0;
        move(nr1, nr2, dx[i], dy[i], rd);
        move(nb1, nb2, dx[i], dy[i], bd);
        if (board[nr1][nr2] != 'O' && board[nb1][nb2] != '0' && nr1 == nb1 && nr2 == nb2) {
            if (rd > bd)
                nr1 -= dx[i], nr2 -= dy[i];
            else nb1 -= dx[i], nb2 -= dy[i];
        }
        if (chk[nr1][nr2][nb1][nb2]) continue;
        chk[nr1][nr2][nb1][nb2] = true;
        DFS(nr1, nr2, nb1, nb2, cnt + 1);
        chk[nr1][nr2][nb1][nb2] = false;
    }
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int R1, R2, B1, B2;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'B') B1 = i, B2 = j;
            if (board[i][j] == 'R') R1 = i, R2 = j;
        }
    }
    chk[R1][R2][B1][B2] = true;
    DFS(R1, R2, B1, B2, 0);
    if (res == 1e9) cout << "-1";
    else cout << res;
    return 0;
}
