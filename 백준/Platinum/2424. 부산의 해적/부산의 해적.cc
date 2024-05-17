#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)
#define SIZE 702
struct p {
    int x, y;
};
int n, m, viking_see[SIZE][SIZE], viking_vis[SIZE][SIZE], sua_vis[SIZE][SIZE], dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0,
                                                                                                             1};
char board[SIZE][SIZE];
p sua_st, viking_st, en;
queue<p> q;

int main() {
    fastio;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'Y') sua_st = {i, j};
            if (board[i][j] == 'V') viking_st = {i, j};
            if (board[i][j] == 'T') en = {i, j};
        }
    }
    fill(&viking_vis[0][0], &viking_vis[SIZE - 1][SIZE - 1], 1e9);
    fill(&viking_see[0][0], &viking_see[SIZE - 1][SIZE - 1], 1e9);
    // viking BFS
    q.push(viking_st), viking_vis[viking_st.x][viking_st.y] = 1;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i], ny = cur.y + dy[i];
            if (board[nx][ny] == 'I' || viking_vis[nx][ny] != 1e9 || nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            viking_vis[nx][ny] = viking_vis[cur.x][cur.y] + 1;
            q.push({nx, ny});
        }
    }
    // min J viking see
    for (int i = 0; i < n; i++) {
        int j = 0;
        while (j < m) {
            if (board[i][j] != 'I') {
                int s = j, v = 1e9;
                while (j < m && board[i][j] != 'I')
                    v = min(v, viking_vis[i][j]), j++;
                for (int k = s; k < j; k++)
                    viking_see[i][k] = v;
            } else j++;
        }
    }
    // min I viking see
    for (int i = 0; i < m; i++) {
        int j = 0;
        while (j < n) {
            if (board[j][i] != 'I') {
                int s = j, v = 1e9;
                while (j < n && board[j][i] != 'I')
                    v = min(v, viking_vis[j][i]), j++;
                for (int k = s; k < j; k++)
                    viking_see[k][i] = min(viking_see[k][i], v);
            } else j++;
        }
    }
    // sua BFS
    fill(&sua_vis[0][0], &sua_vis[SIZE - 1][SIZE - 1], 1e9);
    q.push(sua_st), sua_vis[sua_st.x][sua_st.y] = 1;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i], ny = cur.y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (sua_vis[cur.x][cur.y] + 1 >= viking_see[nx][ny] || board[nx][ny] == 'I' || sua_vis[nx][ny] != 1e9)
                continue;
            sua_vis[nx][ny] = sua_vis[cur.x][cur.y] + 1;
            q.push({nx, ny});
        }
    }
    if (sua_vis[en.x][en.y] != 1e9 && sua_vis[en.x][en.y] < viking_see[en.x][en.y]) cout << "YES";
    else cout << "NO";
    return 0;
}
