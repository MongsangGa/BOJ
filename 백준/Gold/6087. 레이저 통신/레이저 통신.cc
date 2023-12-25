#include <bits/stdc++.h>

using namespace std;

#define SIZE 101
struct P {
    int x, y;
};
int n, m, chk[SIZE][SIZE], dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
char arr[SIZE][SIZE];
vector<P> c;

int BFS() {
    queue<P> q;
    chk[c[0].x][c[0].y] = 0;
    q.push({c[0].x, c[0].y});
    while (!q.empty()) {
        P tmp = q.front();
        q.pop();
        int x = tmp.x, y = tmp.y;
        if (x == c[1].x && y == c[1].y) return chk[x][y] - 1;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            while (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                if (arr[nx][ny] == '*') break;
                if (!chk[nx][ny]) {
                    q.push({nx, ny});
                    chk[nx][ny] = chk[x][y] + 1;
                }
                nx += dx[i], ny += dy[i];
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 'C') c.push_back({i, j});
        }
    }
    cout << BFS();
    return 0;
}
